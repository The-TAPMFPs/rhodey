/**
 * \file PostWar.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "PostWar.h"

/**
 * \fn PostWar ()
 * \brief constructor for the PostWar class
 *
 */
PostWar::PostWar() {
  War::warState = "PostWar";
  War::warStateDesc = "Currently in PostWar State <- This should be changed";
  War::warStateThumbnailColor = ftxui::Color::Aquamarine1;
  War::warStateThumbnail = {
"",
"",
"",
"",
"                          _____  _  _____",
"                         (___  \\( )/  ___)",
"                           (___ | | ___)",
"                            /\")`| |'(\"\\",
"                           | |  | |  | |",
"                            \\ \\_| |_/ /",
"                             `._!' _.'",
"                               / .'\\",
"                              | / | |",
"                               \\|/ /",
"                                /.<",
"                               (| |)",
"                                | '",
"                                | |",
"                                `-'"
  };
  warPhase = phase::POST_WAR;
}

/**
 * \fn handleWarChange (War* war)
 * \brief transitions the current war to a new WarState
 *
 * \param war the war that will have its state changed
 */
void PostWar::handleWarChange(War* war) {
  war->transitionTo(new DisputeSettled());
}

/**
 * \fn string getCurrentWarState()
 * \brief gets what is to be displayed as the title of a cutscene of the current war phase
 *
 * \return the title of the current war phase
 */
std::string PostWar::getCurrentWarState() {
  return "Currently in Postwar State";
}