#include "UI.h"
#include "War/War.h"
#include <cmath>
#include <chrono>

// Display a component nicely with a title on the left.
//TODO: Remove since we probably won't need this
Component Wrap(std::string name, Component component) {
  return Renderer(component, [name, component] {
    return hbox({
               text(name) | size(WIDTH, EQUAL, 8),
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

  //===== CREATE SCREEN CONTAINERS =====//

#pragma region PARENT_PANEL
  //GAME MAP
  int mapW = 100, mapH = 100;
  int camX = 0, camY = 0;
  int mapHeight = 40;
  Region* selectedRegion;

  MapData m = war->getCurrentMapData();

  auto mapRenderer = Renderer([&] {
    auto c = Canvas(mapW, mapH);

    for(int i = 0; i < mapW; i++) {
      for(int j = 0; j < mapH; j++) {
        {
          // mapHeight = 100*m.travelFieldA[clamp(mouseX, 0, 99)][clamp(mouseX, 0, 99)];

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

            // c.DrawPoint(i, j, true, Color(0, col, ((i/2+j/4)%2==0?col/2:col))); //Add tiling pattern to terrain
        }
      }
    }

    // Draw regions markers
    for(auto r = m.regionLocations.begin(); r != m.regionLocations.end(); r++)
    {
      //X and Y coords must be rounded to nearest mouse coord
      int x = 2*(floor(r->x/2));
      int y = 4*(floor(r->y/4));

      c.DrawBlock(x, y, true, Color::Red1);

      if(clamp(mouseX, 0, 99) == x && clamp(mouseY, 0, 99) == y)
      {
        c.DrawText(x, y, (std::to_string(x) + ", " + std::to_string(y)), Color::Red3);
      }
      else
      {
        c.DrawText(x, y, "R", Color::Red);
        c.DrawText(mouseX+1, mouseY+1, "X");

        //Draw mouse cursor
        // if(mouseX >= 0 && mouseY >= 0 && mouseX < mapW && mouseY < mapH)
        {
          // c.DrawText(mouseX, mouseY, "X", Color::Red);
        }
      }
    }

    //DEBUG: Show mouse coords
    // c.DrawText(mouseX, mouseY, std::to_string(mouseX) + ", " + std::to_string(mouseY), [](Pixel& p) {
      // p.foreground_color = Color::Aquamarine1;
    // });

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
      }
    }
    return false;
  });

  //=====PARENT PANEL=====//
  auto parent = mapRenderer;

#pragma endregion


#pragma region REGION_DATA_PANEL
  //=====TOP PANEL=====//

  // auto mapSlider = Slider("Height:", &mapHeight, 0, 100, 1);

  auto regionDataLayout = Container::Vertical({
    // mapSlider
  });

  auto regionData = Renderer(regionDataLayout, [&] {
    return vbox({
      text("Region Data") | center,
      // text(std::to_string(mapHeight)) | center,
      // mapSlider->Render()
    });
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


#pragma region BOTTOM_PANEL
  //=====BOTTOM PANEL=====//
  auto bottom = Renderer([] { return text("BOTTOM PANEL") | center; });
#pragma endregion


#pragma region MAIN_CONTAINER
  //Default starting sizes for each panel
  int right_size = 75;
  int regionData_size = 20;
  int bottom_size = 2;
 
  // auto container = Container::Horizontal({
  //   parent,
  //   mapMouseCapture
  // });
  auto container = parent; // The main container holding all the window panels
  container = ResizableSplitBottom(regionData, container, &regionData_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);

  //=====MAIN PANEL=====//
  auto renderer = Renderer(container, [&] { return container->Render() | border; }); //The global container renderer
#pragma endregion

  screen.Loop(renderer);
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

  return page |= border;
}

void executeDispute()
{
  auto screen = ScreenInteractive::Fullscreen();

  auto nextButton = Button("Next", screen.ExitLoopClosure(), ButtonOption::Animated(Color::Red));

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