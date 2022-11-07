#include "Hostilities.h"

Hostilities::Hostilities() {
  War::warState = "Hostilities";
  War::warStateDesc = War::narrative.hostilities;
  War::warStateThumbnailColor = ftxui::Color::Red1;
  War::warStateThumbnail = {
"",
"",
"",
"",
"",
"",
"                                     |__",
"                                     |\\/",
"                                     ---",
"                                     / | [",
"                              !      | |||",
"                            _/|     _/|-++'",
"                        +  +--|    |--|--|_ |-",
"                     { /|__|  |/\\__|  |--- |||__/",
"                    +---------------___[}-_===_.'____               /\\",
"                ____`-' ||___-{]_| _[}-  |     |_[___\\==--          \\/   _",
" __..._____--==/___]_|__|_____________________________[___\\==--___,-----' .7",
"|                                                                   BB-61/",
" \\_______________________________________________________________________|"
  };
  warPhase = phase::HOSTILITIES;
}

void Hostilities::handleWarChange(War* war) {
  war->transitionTo(new Conflict());
}

std::string Hostilities::getCurrentWarState() {
  return "Currently in Hostilities State";
}