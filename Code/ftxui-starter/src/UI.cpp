#include "UI.h"
#include "logger.h"
#include "War/War.h"
#include <cmath>
#include <chrono>
#include <sstream>
#include <iomanip>

// Display a component nicely with a title on the left.
//TODO: Remove since we probably won't need this
Component Wrap(std::string name, Component component) {
  return Renderer(component, [name, component] {
    return hbox({
               text(name) | size(WIDTH, EQUAL, 10),
               separator(),
               component->Render() | xflex,
           }) |
           xflex;
  });
}

int clamp(int val, int min, int max)
{
  return std::max(std::min(val, max), min);
}

UI::UI(War* war)
 : war(war)
{}

//Returns the linearly interpolated point between two mapCoords
//t in [0, 1] inclusive
MapCoords flerp(MapCoords a, MapCoords b, float t)
{
    int dx = (a.x - b.x) * t;
    int dy = (a.y - b.y) * t;

    return {b.x + dx, b.y + dy};
}

float fdist(MapCoords a, MapCoords b)
{
    int dx = a.x-b.x;
    int dy = a.y-b.y;

    return sqrt(dx*dx + dy*dy);
}

std::vector<MapCoords> plotLineLow(int x0, int y0, int x1, int y1)
{
    std::vector<MapCoords> res;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = y0;

    for(int x = x0; x <= x1; x++)
    {
        res.push_back({x, y});
        if (D > 0)
        {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else
        {
            D = D + 2*dy;
        }
    }
    return res;
}

std::vector<MapCoords> plotLineHigh(int x0, int y0, int x1, int y1)
{
    std::vector<MapCoords> res;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;

    for(int y = y0; y <= y1; y++)
    {
        res.push_back({x, y});
        if (D > 0)
        {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
        {
            D = D + 2*dx;
        }
    }
    return res;
}

std::vector<MapCoords> brensenhamLine(int x0, int y0, int x1, int y1)
{
    std::vector<MapCoords> line;

    if (std::abs(y1 - y0) < std::abs(x1 - x0))
    {
        if (x0 > x1)
        {
            auto newLine = plotLineLow(x1, y1, x0, y0);
            line.insert(line.end(), newLine.begin(), newLine.end());
        }
        else
        {
            auto newLine = plotLineLow(x0, y0, x1, y1);
            line.insert(line.end(), newLine.begin(), newLine.end());
        }
    }
    else
    {
        if (y0 > y1)
        {
            auto newLine = plotLineHigh(x1, y1, x0, y0);
            line.insert(line.end(), newLine.begin(), newLine.end());
        }
        else
        {
            auto newLine = plotLineHigh(x0, y0, x1, y1);
            line.insert(line.end(), newLine.begin(), newLine.end());
        }
    }
    return line;
}

void UI::render()
{
  auto screen = ScreenInteractive::Fullscreen();

  int mouseX = 0, mouseY = 0;

  // This thread exists to make sure that the event queue has an event to
  // process at approximately a rate of 60 FPS
  std::atomic<bool> refresh_ui_continue = true;
  std::thread refresh_ui([&] {
    while (refresh_ui_continue) {
      using namespace std::chrono_literals;
      const auto refresh_time = 1.0s / 60.0;
      std::this_thread::sleep_for(refresh_time);
      screen.PostEvent(Event::Custom);
    }
  });

  //===== CREATE SCREEN CONTAINERS =====//

#pragma region MAP_PANEL
  //GAME MAP
  int mapW = 100, mapH = 100;
  int camX = 0, camY = 0;
  int mapHeight = 40;
  Region* selectedRegion = nullptr;

  MapData m = war->getCurrentMapData();

  auto mapRenderer = Renderer([&] {
    auto c = Canvas(mapW, mapH);

    for(int i = 0; i < mapW; i++) {
      for(int j = 0; j < mapH; j++) {
        {
          int colIntensity = (255*m.travelFieldB[i][j]);
          auto col = Color(0, colIntensity, colIntensity);

          if(100*m.travelFieldB[i][j] > mapHeight - 3 &&
             100*m.travelFieldB[i][j] < mapHeight + 3)
          {
            auto col = Color::White;
          }
          
          int x = 100*m.travelFieldB[i][j];

          if(x%5==0 || x%5==1) //Draw terrain banding
          {
            // col = Color::White;
            c.DrawPoint(i, j, true, col);
          }
        }
      }
    }

    // Draw regions markers
    for(auto r = m.regionLocations.begin(); r != m.regionLocations.end(); r++)
    {
      int x = r->x*2;
      int y = r->y*4;

      if(clamp(mouseX, 0, 99) == x && clamp(mouseY, 0, 99) == y) //If mouse over region
      {
        std::string regionName = "REGION";
        int nameLen = regionName.length()*2;

        //Position name so it doesnt overflow out of the map bounds
        int clampX = clamp(x-nameLen/2, 2, 99-nameLen);
        int clampY = (y < 1)?4:y-1;

        c.DrawText(clampX, clampY, regionName, Color::Red3);
      }
      else //Mouse not hovered over region
      {
        c.DrawText(x, y, "R", Color::Red);

        //Draw mouse cursor
        if(mouseX >= 0 && mouseY >= 0 && mouseX < mapW && mouseY < mapH)
        {
          c.DrawText(mouseX, mouseY, "X", Color::Red);
        }
      }

      //Draw travel difficulties from selected region
      if(selectedRegion != nullptr)
      {
        bool diffForTeamA = selectedRegion->getPossessor()->getAlliance()->isTeamA();
        // float travelDifficulty = diffForTeamA ? 10.5 : 0;
        float travelDifficulty = war->getTravelDifficulty(selectedRegion->getCoords(), {r->x, r->y}, diffForTeamA);

        //Round to 2 decimal places
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << travelDifficulty;

        //Draw Bresenham lines
        // MapCoords from = selectedRegion->getCoords();
        // MapCoords to = {r->x, r->y};
        // int x0 = from.x*2, x1 = to.x*2;
        // int y0 = from.y*4, y1 = to.y*4;
        // std::vector<MapCoords> line = brensenhamLine(x0, y0, x1, y1);
        // int c_r = (x*13 + y*7)%255;
        // int c_g = (x*19 + y*31)%255;
        // int c_b = (x*53 + y*19)%255;
        // for(auto l = line.begin(); l != line.end(); l++)
        // {
        //   c.DrawBlock(l->x, l->y, true, Color(c_r, c_g, c_b));
        // }

        c.DrawText(x, y+4, ss.str(), Color::Cyan1);
      }
    }

    //Draw selected region marker
    if(selectedRegion != nullptr)
    {
      MapCoords coords = selectedRegion->getCoords();
      c.DrawText(coords.x*2, coords.y*4, "R", Color::Gold1);
    }

    return canvas(c);
  });

  //Capture mouse input for the mapRenderer
  mapRenderer |= CatchEvent([&](Event e) {
    if(e.is_mouse())
    {
      mouseX = (e.mouse().x - 1) * 2;
      mouseY = (e.mouse().y - 1) * 4;

      if(e.mouse().button == Mouse::Left &&
         e.mouse().motion == Mouse::Pressed)
      {
        selectedRegion = war->getRegionAt(mouseX/2, mouseY/4);
        // selectedRegion = new Region("test", mouseX, mouseY);
      }
    }
    // else if(e == Event::Custom)
    // {
    //   war->step();
    // }
    // war->onEvent(e);

    return false;
  });

  //=====MAP PANEL=====//
  auto map = mapRenderer;

#pragma endregion


#pragma region REGION_DATA_PANEL
  //=====TOP PANEL=====//

  // auto mapSlider = Slider("Height:", &mapHeight, 0, 100, 1);
  auto regionDataLayout = Container::Vertical({});

  auto regionData = Renderer(regionDataLayout, [&] {
    if(selectedRegion!=nullptr)
    {
      return vbox({
        text("Region Data") | center,
        separator(),
        text(selectedRegion->getRegionName()) | center,
        text(selectedRegion->getPossessor()->getName()) | center,
        text(std::to_string(selectedRegion->getCoords().x)),
        text(std::to_string(selectedRegion->getCoords().y))
      });
    }
    else
    {
      return vbox({
        text("Region Data") | center,
        separator(),
        text("Please select a region on the map.") | center,
      });
    }
  });
#pragma endregion


#pragma region COUNTRY_DATA_PANEL
  //COUNTRY MANAGEMENT
  std::vector<std::string> tab_values{
      "Team A",
      "Team B",
  };

  int tab_selected = 0;
  auto tab_toggle = Toggle(&tab_values, &tab_selected);

  std::vector<std::string> countries_on_sideA = war->teamA->getAllianceNames();
  int countryA_selected = 0;

  std::vector<std::string> countries_on_sideB = war->teamB->getAllianceNames();
  int countryB_selected = 0;

  auto tab_container = Container::Tab(
    {
      Dropdown(&countries_on_sideA, &countryA_selected),
      Dropdown(&countries_on_sideB, &countryB_selected),
    },
    &tab_selected);

  auto countryManagerLayout = Container::Vertical({
    tab_toggle,
    tab_container,
  });

  auto countryManager = Renderer(countryManagerLayout, [&] {

    std::vector<std::string> stats;
    if(tab_selected == 0) {
      stats = war->teamA->getMembers().at(countryA_selected)->getFormattedStats();
    } else {
      stats = war->teamB->getMembers().at(countryB_selected)->getFormattedStats();
    }

    ftxui::Elements statsElements;
    for(int i = 0; i < stats.size(); i++) {
      auto elem = text(stats[i]) | border | size(Direction::WIDTH, Constraint::GREATER_THAN, 40);
      statsElements.push_back(elem);
    };

    FlexboxConfig statsFlexboxConfig;
    statsFlexboxConfig.direction =        FlexboxConfig::Direction::Column;
    statsFlexboxConfig.wrap =             FlexboxConfig::Wrap::NoWrap;
    statsFlexboxConfig.justify_content =  FlexboxConfig::JustifyContent::SpaceAround;
    statsFlexboxConfig.align_items =      FlexboxConfig::AlignItems::Stretch;
    statsFlexboxConfig.align_content =    FlexboxConfig::AlignContent::SpaceEvenly;

    return vbox({
      text("Conflict") | center,
      separator(),
      vbox({
        tab_toggle->Render(),
        separator(),
        hbox({
          tab_container->Render() | size(Direction::WIDTH, Constraint::GREATER_THAN, 20),
          separator(),
          flexbox(statsElements, statsFlexboxConfig),
        })
      })
    });
  });

  //PANEL LAYOUT
  auto countryDataPanelLayout = Container::Vertical({
      countryManager
  });

  //=====RIGHT PANEL=====//

  auto countryData = Renderer(countryDataPanelLayout, [&] {
      return vbox({
        countryManager->Render(),
      });
  });
#pragma endregion


#pragma region INFO_PANEL
  //CREATE BUTTON
  std::string button_label = "Quit";
  std::function<void()> on_button_clicked_;
  auto button = Button(&button_label, screen.ExitLoopClosure());

  auto infoPanelLayout = Container::Horizontal({
    button
  });

  //=====INFO PANEL=====//
  auto info = Renderer(infoPanelLayout, [&] {
      return hbox({
        filler(),
        vbox({
          text("=====LOG=====") | center,
          text(Logger::getMsg()) | center,
        }),
        filler(),
        separator(),
        button->Render()
        | size(Direction::WIDTH, Constraint::GREATER_THAN, 10)
        | size(Direction::HEIGHT, Constraint::EQUAL, 1)
      });
    });

#pragma endregion


#pragma region MAIN_CONTAINER
  //Default starting sizes for each panel
  int left_size = 50;
  int map_size = 25;
  int bottom_size = 3;

  auto mapContainer = ResizableSplitTop(map, regionData, &map_size);
  auto container = ResizableSplitLeft(mapContainer, countryData, &left_size);
  container = ResizableSplitBottom(info, container, &bottom_size);

  //=====MAIN PANEL=====//
  auto renderer = Renderer(container, [&] { return container->Render() | border; }); //The global container renderer
#pragma endregion

  //Catch event from parallel thread and call simulation loop
  renderer |= CatchEvent([&](Event e) {
    if(e == Event::Custom)
    {
      war->step();
    }
    war->onEvent(e);

    return false;
  });

  screen.Loop(renderer);

  //Kill game loop thread
  refresh_ui_continue = false;
  refresh_ui.join();
}

Element cutSceneDecorator(Element buttons)
{
  auto desc = vbox({
    filler(),
    paragraphAlignCenter(War::warState),
    separator(),
    filler(),
    paragraphAlignCenter(War::warStateDesc),
    filler()
  });

  auto page = vbox({
    desc | flex_grow,
    buttons | center
  });

  if(War::warStateThumbnail.empty()) //No thumbnail available
  {
    return page;
  }

  auto c = Canvas(150, 100);
  int i = 0;
  for(auto line = War::warStateThumbnail.begin(); line != War::warStateThumbnail.end(); line++, i++)
  {
    c.DrawText(0, i*4, line->data(), War::warStateThumbnailColor);
  }

  auto thumb = vbox({
    filler(),
    canvas(c) | center | border,
    filler()
  });

  auto result = hbox({
    filler(),
    page,
    filler(),
    thumb
  });

  return result |= border;
}

void UI::executeDispute()
{
  auto screen = ScreenInteractive::Fullscreen();

  // std::atomic<bool> refresh_ui_continue = true;
  // std::thread refresh_ui([&] {
  //   while (refresh_ui_continue) {
  //     using namespace std::chrono_literals;
  //     const auto refresh_time = 1.0s / 10.0;
  //     std::this_thread::sleep_for(refresh_time);
  //     screen.PostEvent(Event::Custom);
  //   }
  // });

  auto nextButton = Button("Next", screen.ExitLoopClosure(), ButtonOption::Animated(War::warStateThumbnailColor));

  // page |= CatchEvent([&](Event e) {
  //   if(e == Event::Custom) {
  //     // War::warStateThumbnailFrameCount++;
  //   }

    // return false;
  // });

  screen.Loop(nextButton | cutSceneDecorator);
}

void UI::startSim()
{
  bool running = true;
  int frameCount = 0;

  //PHASES:
  //Dispute, Hostilitiies, Conflict, Postwar, DisputeSettled

  int i = 0;
  while(!war->isOver()) {
    executeDispute();
    war->changeState();
    if(i == 1) {
      render();
    }
    i++;
  }

  // while(running)
  {
    frameCount++;
  }
}