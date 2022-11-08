#include "Battle.h"
/**
 * \file Battle.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 8 November 2022
 */

/**
 * \fn Battle::Battle(Region* region, OccupancyTable * table)
 * \brief the battle constructor which creates and initializes a new battle 
 * \param region a pointer to a Region
 * \param table a pointer to a OccupancyTable
*/
Battle::Battle(Region* region, OccupancyTable * table) {
    this->_region = region;
    this->table = table;
    std::vector<Entity *> allEntitities = table->getEntities(region);
    for (auto itr = allEntitities.begin(); itr != allEntitities.end(); ++itr) {
	if ((*itr)->getCountry()->getAlliance()->isTeamA()) {
	    teamA.push_back((*itr));
	} else {
	    teamB.push_back((*itr));
	}
    }
}
/**
 * \fn void Battle::checkReinforcements()
 * \brief a function that checks if certain teams have reinforcements , if not - fall back
*/
void Battle::checkReinforcements() {
    this->teamA.clear();
    this->teamB.clear();
    std::vector<Entity *> allEntitities = table->getEntities(this->_region);
    for (auto itr = allEntitities.begin(); itr != allEntitities.end(); ++itr) {
	if ((*itr)->getCountry()->getAlliance()->isTeamA()) {
	    teamA.push_back((*itr));
	} else {
	    teamB.push_back((*itr));
	}
    }
}
/**
 * \fn bool Battle::takeTurn()
 * \brief this function implements the taking a turn functionality 
*/
bool Battle::takeTurn() {
    this->checkReinforcements();
    std::shuffle(this->teamA.begin(), this->teamA.end(), gen); // gen is the generator from uuid.h
    std::shuffle(this->teamB.begin(), this->teamB.end(), gen); // gen is the generator from uuid.h
    int teamACount = this->teamA.size();
    int teamBCount = this->teamB.size();
    int totalCountTeamA = 0;
    int totalCountTeamB = 0;

    if (teamACount == 0 || teamBCount == 0) {
	return false;
    }
    if (teamACount < teamBCount) {
	for (int count = 0; count < teamBCount; count++) {
	    this->teamA.at(count%teamACount)->attack(* this->teamB.at(count));
	    this->teamB.at(count)->attack(* this->teamA.at(count%teamACount));

	    this->teamA.at(count%teamACount)->update();
	    this->teamB.at(count)->update();
	    totalCountTeamA += this->teamA.at(count%teamACount)->getAmount();
	    totalCountTeamB += this->teamB.at(count)->getAmount();
	}
    } else {
	for (int count = 0; count < teamACount; count++) {
	    this->teamA.at(count)->attack(* this->teamB.at(count%teamBCount));
	    this->teamB.at(count%teamBCount)->attack(* this->teamA.at(count));

	    this->teamA.at(count)->update();
	    this->teamB.at(count%teamBCount)->update();
	    totalCountTeamA += this->teamA.at(count)->getAmount();
	    totalCountTeamB += this->teamB.at(count%teamBCount)->getAmount();
	}
    }

    if (totalCountTeamA == 0 || totalCountTeamB == 0) {
	return false;
    }

    return true;
}
/**
 * \fn Battle::~Battle()
 * \brief a destructor that ends a battle*(deallocates memory)
*/
Battle::~Battle(){
}
