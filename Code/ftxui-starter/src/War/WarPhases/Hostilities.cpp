/**
 * \file Hostilities.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "Hostilities.h"

/**
 * \fn Hostilities ()
 * \brief constructor for the Hostilities class
 *
 */
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

/**
 * \fn handleWarChange (War* war)
 * \brief transitions the current war to a new WarState
 *
 * \param war the war that will have its state changed
 */
void Hostilities::handleWarChange(War* war) {
  war->transitionTo(new Conflict());
}

/**
 * \fn string getCurrentWarState()
 * \brief gets what is to be displayed as the title of a cutscene of the current war phase
 *
 * \return the title of the current war phase
 */
std::string Hostilities::getCurrentWarState() {
  return "Currently in Hostilities State";
}