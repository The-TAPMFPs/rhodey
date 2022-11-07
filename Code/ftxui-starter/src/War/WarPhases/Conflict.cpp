#include "Conflict.h"

Conflict::Conflict() {
  War::warState = "Conflict";
  War::warStateDesc = "The conflict has ended!"; //TODO: Summary of conflict
  War::warStateThumbnailColor = ftxui::Color::GreenYellow;
  War::warStateThumbnail = {
"",
"",
"",
"                                  .---.",
"                            _.   /_____\\",
"                           /.|  `( u u )",
"                           | |    \\_w_/_",
"                           \\ `-.-\"`'V'//-.",
"                            `.__,   |// , \\",
"                                |Ll //Ll|\\ \\",
"                                |__//   | \\_\\",
"                               /---|[]==| / /",
"                               \\__/ |   \\/\\/",
"                               /_   | Ll_\\|",
"                                |`^\"\"\"^`|",
"                                |   |   |",
"                                |   |   |",
"                                |   |   |",
"                                |   |   |",
"                                L___l___J",
"                                 |_ | _|",
"                                (___|___)",
"                                 ^^^ ^^^"
  };
  warPhase = phase::CONFLICT;
}

void Conflict::handleWarChange(War* war) {
  war->transitionTo(new PostWar());
}

std::string Conflict::getCurrentWarState() {
  return "Currently in Conflict State";
}