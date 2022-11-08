#include "Conflict.h"
#include "Hostilities.h"

Conflict::Conflict() {
  War::warState = "Conflict";
  War::warStateDesc = War::narrative.conflict;
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
  war->transitionTo(new Hostilities());
}

std::string Conflict::getCurrentWarState() {
  return "Currently in Conflict State";
}