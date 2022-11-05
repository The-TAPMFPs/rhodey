#include "UI.h"
#include "War/War.h"
#include <cmath>
#include <chrono>

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
          int colIntensity = (255*m.travelFieldA[i][j]);
          auto col = Color(0, colIntensity, colIntensity);

          if(100*m.travelFieldA[i][j] > mapHeight - 3 &&
             100*m.travelFieldA[i][j] < mapHeight + 3)
          {
            auto col = Color::White;
          }
          
          int x = 100*m.travelFieldA[i][j];

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

      if(clamp(mouseX, 0, 99) == x && clamp(mouseY, 0, 99) == y)
      {
        std::string regionName = "REGION";
        int nameLen = regionName.length()*2;

        //Position name so it doesnt overflow out of the map bounds
        int clampX = clamp(x-nameLen/2, 2, 99-nameLen);
        int clampY = (y < 1)?4:y-1;

        c.DrawText(clampX, clampY, regionName, Color::Red3);
      }
      else
      {
        c.DrawText(x, y, "R", Color::Red);

        //Draw mouse cursor
        if(mouseX >= 0 && mouseY >= 0 && mouseX < mapW && mouseY < mapH)
        {
          c.DrawText(mouseX, mouseY, "X", Color::Red);
        }
      }

      //Draw selected region marker
      if(selectedRegion != nullptr)
      {
        MapCoords coords = selectedRegion->getCoords();
        c.DrawText(coords.x*2, coords.y*4, "R", Color::Gold1);
      }
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
    else if(e == Event::Custom)
    {
      war->step();
    }
    war->onEvent(e);

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


#pragma region RIGHT_PANEL
  //CREATE MENU
  const std::vector<std::string> menu_entries = {
    "Algeria",
    "Benezuela",
    "Chad",
    "Democratic Republic of the Congo",
    "Equador",
    "Finland",
    "Germany"
  };
  int menu_selected = 0;
  auto menu = Menu(&menu_entries, &menu_selected);
  menu = Wrap("Countries", menu);

  //CREATE BUTTON
  std::string button_label = "Quit";
  std::function<void()> on_button_clicked_;
  auto button = Button(&button_label, screen.ExitLoopClosure());
  // button = Wrap("Button", button);

  //PANEL LAYOUT
  auto rightPanelLayout = Container::Vertical({
      button,
      menu
  });

  //=====RIGHT PANEL=====//
  auto right = Renderer(rightPanelLayout, [&] {
      return vbox({
        menu->Render(),
        separator(),
        (text("Team A") | center),
        (text("Team B") | center),
        separator(),
        button->Render()
      });
  });
#pragma endregion


#pragma region INFO_PANEL
  //=====INFO PANEL=====//
  auto info = Renderer([] {
      return text("ADDITIONAL DATA") | center;
    });
#pragma endregion


#pragma region MAIN_CONTAINER
  //Default starting sizes for each panel
  int left_size = 50;
  int map_size = 25;
  int bottom_size = 2;

  auto mapContainer = ResizableSplitTop(map, regionData, &map_size);
  auto container = ResizableSplitLeft(mapContainer, right, &left_size);
  container = ResizableSplitBottom(info, container, &bottom_size);

  //=====MAIN PANEL=====//
  auto renderer = Renderer(container, [&] { return container->Render() | border; }); //The global container renderer
#pragma endregion

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

void UI::simSetup() {
  auto screen = ScreenInteractive::Fullscreen();

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

    auto doneButton = Button("START", screen.ExitLoopClosure(), ButtonOption::Animated(Color::Red));

  auto container = Container::Vertical({
    tab_toggle,
    tab_container,
    doneButton,
  });



  auto renderer = Renderer(container, [&] {
    std::vector<std::string> stats;
    if(tab_selected == 0) {
      stats = war->teamA->getMembers()->at(countryA_selected)->getFormattedStats();
    } else {
      stats = war->teamB->getMembers()->at(countryB_selected)->getFormattedStats();
    }

    std::vector<Element> twoByTwoElems;
    for(int i = 0; i < stats.size(); i += 2) {
      auto elem = vbox({
        text(stats[i]) | borderLight,
        text(stats[i + 1]) | borderLight,
      });

      twoByTwoElems.push_back(elem);
    };

    std::vector<Element> tabContainerElems {
      tab_container->Render(),
      separator(),
    };
    tabContainerElems.insert(tabContainerElems.end(), twoByTwoElems.begin(), twoByTwoElems.end());

    return vbox({
      text("WAR START STATE") | center,
      separator(),
      vbox({
        tab_toggle->Render(),
        separator(),
        hbox(tabContainerElems),
      }) | border,
      doneButton->Render() | center | flex,
    }) | border;
  });

  screen.Loop(renderer);
}

void UI::startSim()
{
  bool running = true;
  int frameCount = 0;

  //PHASES:
  //Dispute, Hostilitiies, Conflict, Postwar, DisputeSettled

  simSetup();

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