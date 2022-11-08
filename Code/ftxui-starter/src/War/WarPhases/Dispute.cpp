#include "Dispute.h"
#include "Conflict.h"

Dispute::Dispute() {
  War::warState = "Dispute";
  War::warStateDesc = "The war in Asia began when Japan invaded China on July 7, 1937. The war began in Europe when Germany invaded Poland on September 1, 1939. France and the United Kingdom reacted by declaring war on Germany. By 1941, much of Europe was under German control, including France. Only the British remained fighting against the Axis in North Africa";
  War::warStateThumbnailColor = ftxui::Color::Cyan;
  War::warStateThumbnail = {
"",
"",
"                              ,,ggddY\"\"\"Ybbgg,,",
"                       ,agd888b,_ \"Y8, ___`\"\"Ybga, ",
"                    ,gdP\"\"88888888baa,.\"\"8b    \"888g,",
"                  ,dP\"     ]888888888P'  \"Y     `888Yb, ",
"                ,dP\"      ,88888888P\"  db,       \"8P\"\"Yb,",
"               ,8\"       ,888888888b, d8888a           \"8,",
"              ,8'        d88888888888,88P\"' a,          `8,",
"             ,8'         88888888888888PP\"  \"\"           `8, ",
"             d'          I88888888888P\"                   `b ",
"             8           `8\"88P\"\"Y8P'                      8 ",
"             8            Y 8[  _ \"                        8 ",
"             8              \"Y8d8b  \"Y a                   8",
"             8                 `\"\"8d,   __                 8",
"             Y,                    `\"8bd888b,             ,P ",
"             `8,                     ,d8888888baaa       ,8'",
"              `8,                    888888888888'      ,8' ",
"               `8a                   \"8888888888I      a8' ",
"                `Yba                  `Y8888888P'    adP' ",
"                  \"Yba                 `888888P'   adY\" ",
"                    `\"Yba,             d8888P\" ,adP\"' ",
"                       `\"Y8baa,      ,d888P,ad8P\"'",
"                            ``\"\"YYba8888P\"\"''"
  };
  warPhase = phase::DISPUTE;
}

void Dispute::handleWarChange(War* war) {
  war->transitionTo(new Conflict());
}

std::string Dispute::getCurrentWarState() {
  return "Currently in Dispute State";
}