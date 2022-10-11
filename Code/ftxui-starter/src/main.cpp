#include <functional>
#include <memory>      // for shared_ptr, allocator, __shared_ptr_access
#include <string>
#include <vector>
 
#include "ftxui/component/captured_mouse.hpp"       // for ftxui
#include "ftxui/component/component.hpp"            // for Slider, Checkbox, Vertical, Renderer, Button, Input, Menu, Radiobox, Toggle
#include "ftxui/component/component_base.hpp"       // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"   // for Component, ScreenInteractive
#include "ftxui/component/event.hpp"                // for Event
#include "ftxui/component/mouse.hpp"                // for Mouse

#include "ftxui/dom/elements.hpp"                   // for separator, operator|, Element, size, xflex, text, WIDTH, hbox, vbox, EQUAL, border, GREATER_THAN
#include "ftxui/dom/canvas.hpp"                     // for Canvas
#include "ftxui/dom/node.hpp"                       // for Render

#include "ftxui/screen/color.hpp"                   // for Color, Color::Red, Color::Blue, Color::Green, ftxui
 
using namespace ftxui;
 
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



int main(int argc, const char* argv[]) {
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
  auto mapCanvas = Canvas(mapW, mapH);

  mapCanvas.DrawPointLine(0, 0, mapW-1, mapH-1, Color::Red);
  mapCanvas.DrawPointLine(0, mapH-1, mapW-1, 0, Color::Red);

  mapCanvas.DrawText(mapW/4, mapH/2, std::to_string(mouseX), [](Pixel& p) {
    p.foreground_color = Color::Aquamarine1;
  });

  auto mapRenderer = Renderer([&] {
    auto c = Canvas(mapW, mapH);

    c.DrawPointLine(0, 0, mapW-1, mapH-1, Color::Red);
    c.DrawPointLine(0, mapH-1, mapW-1, 0, Color::Red);

    c.DrawText(mapW/4, mapH/2, std::to_string(mouseX), [](Pixel& p) {
      p.foreground_color = Color::Aquamarine1;
    });

    return canvas(std::move(c));
  });

  auto tab_with_mouse = CatchEvent(parent, [&](Event e) {
    if(e.is_mouse())
    {
      mouseX = (e.mouse().x - 1) * 2;
      mouseY = (e.mouse().x - 1) * 4;
    }
    return false;
  });

  //=====RIGHT PANEL=====//
  auto right = Renderer([&] {
    // return canvas(&mapCanvas) | hcenter;
    return mapRenderer->Render() | hcenter;
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
 
  auto container = parent; // The main container holding all the window panels
  container = ResizableSplitTop(top, container, &top_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);

  //=====MAIN PANEL=====//
  auto renderer = Renderer(container, [&] { return container->Render() | border; }); //The global container renderer
#pragma endregion

  screen.Loop(renderer);
}