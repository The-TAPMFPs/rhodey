#include "UI.h"
#include "War/War.h"
#include <cmath>

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
  int mapW = 50, mapH = 50;
  int camX = 0, camY = 0;
  int mapHeight = 40;

  // MapData m = war->getCurrentMapData(); //ERROR: Segfault

  auto mapRenderer = Renderer([&] {
    auto c = Canvas(mapW, mapH);

    for(int i = -1; i < 100; i++) {
      for(int j = 0; j < 100; j++) {
        // if(i % 5 != 0) //Optional; splits grid into 4x4 tiles to account for horizontal lines
        // if(m.travelFieldA[i][j] > 0.5)
        {
          c.DrawPoint(i+mapHeight, j, Color::Green);
        }
      }
    }

    // c.DrawPointLine(0, 0, mapW-1, mapH-1, Color::Red);
    // c.DrawPointLine(0, mapH-1, mapW-1, 0, Color::Red);

    c.DrawPoint(mouseX%mapW, mouseY%mapW, true, Color::Red);

    // c.DrawText(mouseX, mouseY, std::to_string(mouseX) + ", " + std::to_string(mouseY), [](Pixel& p) {
    //   p.foreground_color = Color::Aquamarine1;
    // });

    return canvas(c);
  });

  //Capture mouse input for the mapRenderer
  auto mapMouseCapture = CatchEvent(mapRenderer, [&](Event e) {
    if(e.is_mouse())
    {
      mouseX = (e.mouse().x - 1) * 2;
      mouseY = (e.mouse().y - 1) * 4;
    }
    return false;
  });

  //=====PARENT PANEL=====//
  auto parent = Renderer([&] {
    return mapMouseCapture->Render() | hcenter;
  });

  parent = Container::Horizontal({
    mapMouseCapture
  });
#pragma endregion


#pragma region MAP_CONFIG_PANEL
  //=====TOP PANEL=====//

  auto mapSlider = Slider("Height:", &mapHeight, 0, 100, 1);

  auto mapConfigLayout = Container::Vertical({
    mapSlider
  });

  auto mapConfig = Renderer(mapConfigLayout, [&] {
    return vbox({
      text("Map Config") | center,
      text(std::to_string(mapHeight)) | center,
      mapSlider->Render()
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
  int mapConfig_size = 20;
  int bottom_size = 2;
 
  // auto container = Container::Horizontal({
  //   parent,
  //   mapMouseCapture
  // });
  auto container = parent; // The main container holding all the window panels
  container = ResizableSplitBottom(mapConfig, container, &mapConfig_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);

  //=====MAIN PANEL=====//
  auto renderer = Renderer(container, [&] { return container->Render() | border; }); //The global container renderer
#pragma endregion

  screen.Loop(renderer);
}