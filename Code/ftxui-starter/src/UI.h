#pragma once
#pragma region INCLUDES
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

#include "War/War.h"
#pragma endregion

using namespace ftxui;

class UI {
    private:
        War* war;

    public:
        UI(War* war);
        void render();
};