/**
 * \file Conflict.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "Conflict.h"

/**
 * \fn void Conflict::Conflict
 * \brief constructor for the Conflict class
 * 
 *
 */
Conflict::Conflict() {
  War::warState = "Conflict";
  War::warStateDesc = "Currently in Conflict State <- This should be changed";
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

/**
 * \fn handleWarChange (War* war)
 * \brief transitions the current war to a new WarState
 *
 * \param war the war that will have its state changed
 */
void Conflict::handleWarChange(War* war) {
  war->transitionTo(new PostWar());
}

/**
 * \fn string getCurrentWarState()
 * \brief gets what is to be displayed as the title of a cutscene of the current war phase
 *
 * \return the title of the current war phase
 */
std::string Conflict::getCurrentWarState() {
  return "Currently in Conflict State";
}