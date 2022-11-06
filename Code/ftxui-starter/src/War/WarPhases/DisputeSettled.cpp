#include "DisputeSettled.h"

DisputeSettled::DisputeSettled() {
  War::warState = "DisputeSettled";
  War::warStateDesc = "Currently in DisputeSettled State <- This should be changed";
  War::warStateThumbnailColor = ftxui::Color::CadetBlue;
  War::warStateThumbnail = {
"",
"",
"",
"",
"",
"",
"                 /~~~~~~~//~~~~~~~~//~~~~~|",
"                /       //        //      |",
"               /_\\.___ //__ \\.___//_______|",
"     O       [\%\%\%\%\%\%\%\%\%] O=====] |[_______]",
"    __\\__ ===========___/_ --------}==========================",
"   |**   |/|(@ ## (@|   **|        |     []|                  |)",
"   |     |/| ###### |     | _____  |       |         ___      |",
"   |_____|/|_######_|____ |/_  _  \\}_______|________/_  _\\    |.",
"  |________________________|     \\ \\_______________//     \\\\ /",
"    |%{  @  }            |%{  @  }                |%{  @  }",
"     \\%\\   /              \\%\\   /                  \\%\\   /",
"       ~~~~                 ~~~~                     ~~~~"
  };
}

void DisputeSettled::handleWarChange(War* war) {
  // transitions to null to screen loop
  war->transitionTo(NULL);
}

std::string DisputeSettled::getCurrentWarState() {
  return "Currently in DisputeSettled State";
}