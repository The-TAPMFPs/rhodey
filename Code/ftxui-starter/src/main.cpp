// #include <iostream>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

// int main(void) {
//   using namespace ftxui;

//   auto summary = [&] {
//     auto content = vbox({
//         hbox({text(L"- done:   "), text(L"3") | bold}) | color(Color::Green),
//         hbox({text(L"- active: "), text(L"2") | bold}) | color(Color::RedLight),
//         hbox({text(L"- queue:  "), text(L"9") | bold}) | color(Color::Red),
//     });
//     return window(text(L" Summary "), content);
//   };

//   auto document =  //
//       vbox({
//           hbox({
//               summary(),
//               summary(),
//               summary() | flex,
//           }),
//           summary(),
//           summary(),
//       });

//   // Limit the size of the document to 80 char.
//   document = document | size(WIDTH, LESS_THAN, 80);

//   auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
//   Render(screen, document);

//   std::cout << screen.ToString() << '\0' << std::endl;

//   return EXIT_SUCCESS;
// }

// #include "ftxui/component/captured_mouse.hpp"      // for ftxui
// #include "ftxui/component/component.hpp"           // for Slider
// #include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

// using namespace ftxui;

// int main(int argc, const char* argv[]) {
//   auto screen = ScreenInteractive::TerminalOutput();
//   int value1 = 50;
//   int value2 = 25;

//   // auto slider1 = Slider("Value 1:", &value1, 0, 100, 1);
//   // auto slider2 = Slider("Value 2:", &value2, 1, 100, 1);

//   auto document =  //
//       vbox({
//       });

//   screen.Loop(document);
// }

#include <ftxui/screen/screen.hpp>
#include <iostream>
 
int main(void) {
  using namespace ftxui;
  auto screen = Screen::Create(Dimension::Fixed(32), Dimension::Fixed(10));
 
  auto& pixel = screen.PixelAt(9,9);
  pixel.character = U'A';
  pixel.bold = true;
  pixel.foreground_color = Color::Blue;
 
  std::cout << screen.ToString();
  return EXIT_SUCCESS;
}