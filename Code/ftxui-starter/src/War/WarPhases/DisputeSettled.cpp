/**
 * \file DisputeSettled.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "DisputeSettled.h"

/**
 * \fn DisputeSettled ()
 * \brief constructor for the DisputeSettled class
 *
 */
DisputeSettled::DisputeSettled() {
  War::warState = "DisputeSettled";
  War::warStateDesc = War::narrative.disputeSettled;
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
  warPhase = phase::DISPUTE_SETTLED;
}

/**
 * \fn handleWarChange (War* war)
 * \brief transitions the current war to a new WarState
 *
 * \param war the war that will have its state changed
 */
void DisputeSettled::handleWarChange(War* war) {
  // transitions to null to screen loop
  war->transitionTo(NULL);
}

/**
 * \fn string getCurrentWarState()
 * \brief gets what is to be displayed as the title of a cutscene of the current war phase
 *
 * \return the title of the current war phase
 */
std::string DisputeSettled::getCurrentWarState() {
  return "Currently in DisputeSettled State";
}