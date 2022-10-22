#include "UI.h"

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

void UI::render()
{
  auto screen = ScreenInteractive::Fullscreen();

  int mouseX = 0, mouseY = 0;

  //===== CREATE SCREEN CONTAINERS =====//

#pragma region PARENT_PANEL
  
  //CREATE MENU
  const std::vector<std::string> menu_entries = {
      "Menu 1",
      "Menu 2",
      "Menu 3",
      "Menu 4",
  };
  int menu_selected = 0;
  auto menu = Menu(&menu_entries, &menu_selected);
  menu = Wrap("Menu", menu);

  //CREATE BUTTON
  std::string button_label = "Quit";
  std::function<void()> on_button_clicked_;
  auto button = Button(&button_label, screen.ExitLoopClosure());
  // button = Wrap("Button", button);

  //PANEL LAYOUT
  auto layout = Container::Vertical({
      button,
      menu
  });

  //=====PARENT PANEL=====//
  auto parent = Renderer(layout, [&] {
      return vbox({
        menu->Render(),
        separator(),
        (text("Hello world") | center),
        separator(),
        button->Render()
      });
  });
#pragma endregion


#pragma region TOP_PANEL
  //=====TOP PANEL=====//
  auto top = Renderer([] { return text("TOP PANEL") | center; });
#pragma endregion


#pragma region RIGHT_PANEL
  //GAME MAP
  int mapW = 50, mapH = 50;

  // auto mapCanvas = Canvas(mapW, mapH);
  // mapCanvas.DrawPointLine(0, 0, mapW-1, mapH-1, Color::Red);
  // mapCanvas.DrawPointLine(0, mapH-1, mapW-1, 0, Color::Red);
  // mapCanvas.DrawText(mapW/4, mapH/2, std::to_string(mouseX), [](Pixel& p) {
  //   p.foreground_color = Color::Aquamarine1;
  // });

  auto mapRenderer = Renderer([&] {
    auto c = Canvas(mapW, mapH);

    c.DrawPointLine(0, 0, mapW-1, mapH-1, Color::Red);
    c.DrawPointLine(0, mapH-1, mapW-1, 0, Color::Red);

    c.DrawText(mouseX, mouseY, std::to_string(mouseX) + ", " + std::to_string(mouseY), [](Pixel& p) {
    // c.DrawText(mapW/4, mapH/2, std::to_string(mouseX) + ", " + std::to_string(mouseY), [](Pixel& p)
      p.foreground_color = Color::Aquamarine1;
    });

    return canvas(c);
  });

  //Capture mouse input for the mapRenderer
  auto mapMouseCapture = CatchEvent(mapRenderer, [&](Event e) {
    if(e.is_mouse())
    {
      mouseX = (e.mouse().x - 1);
      mouseY = (e.mouse().y - 1) * 2;
    }
    return false;
  });

  //=====RIGHT PANEL=====//
  auto right = Renderer([&] {
    // return canvas(&mapCanvas) | hcenter;
    return mapMouseCapture->Render() | hcenter;
  });
  right = Container::Horizontal({
    mapMouseCapture
  });
#pragma endregion


#pragma region BOTTOM_PANEL
  //=====BOTTOM PANEL=====//
  auto bottom = Renderer([] { return text("BOTTOM PANEL") | center; });
#pragma endregion


#pragma region MAIN_CONTAINER
  //Default starting sizes for each panel
  int right_size = 40;
  int top_size = 1;
  int bottom_size = 2;
 
  // auto container = Container::Horizontal({
  //   parent,
  //   mapMouseCapture
  // });
  auto container = parent; // The main container holding all the window panels
  container = ResizableSplitTop(top, container, &top_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);

  //=====MAIN PANEL=====//
  auto renderer = Renderer(container, [&] { return container->Render() | border; }); //The global container renderer
#pragma endregion

  screen.Loop(renderer);
}