#include "Battle.h"
#include <sstream>
#include "../../logger.h"

Battle::Battle(Region* region, OccupancyTable * table, bool testing) {
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
    this->testing = testing;
}

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
  * @brief Simulates a exchange of fire in a battle.
  * @return bool if true then it means that the battle is not finnished,
  * if false then the battle is finnished and someone is victorious.
*/
bool Battle::takeTurn() {
    this->checkReinforcements();
    if (!testing) {
	std::shuffle(this->teamA.begin(), this->teamA.end(), gen); // gen is the generator from uuid.h
	std::shuffle(this->teamB.begin(), this->teamB.end(), gen); // gen is the generator from uuid.h
    }
    int teamACount = this->teamA.size();
    int teamBCount = this->teamB.size();
    int totalCountTeamA = 0;
    int totalCountTeamB = 0;
    std::stringstream out;

    if (teamACount == 0 || teamBCount == 0) {
	return false;
    }
    if (teamACount < teamBCount) {
	for (int count = 0; count < teamBCount; count++) {
	    // [Entity] from [Country] and [Entity] from [Country] clash together.
	    out << this->teamA.at(count%teamACount)->getName() << " from " <<
		this->teamA.at(count%teamACount)->getCountry()->getName()
		<< " and " << this->teamB.at(count)->getName() << " from "
		<< this->teamB.at(count)->getCountry()->getName() << "clash." << std::endl;

	    Logger::log(out.str());
	    out.clear();

	    this->teamA.at(count%teamACount)->attack(* this->teamB.at(count),testing);
	    this->teamB.at(count)->attack(* this->teamA.at(count%teamACount), testing);

	    this->teamA.at(count%teamACount)->update();
	    this->teamB.at(count)->update();

	    totalCountTeamA += this->teamA.at(count%teamACount)->getAmount();
	    totalCountTeamB += this->teamB.at(count)->getAmount();
	    Logger::log("----------------------------------------------------");
	}
    } else {
	for (int count = 0; count < teamACount; count++) {
	    // [Entity] from [Country] and [Entity] from [Country] clash together.
	    out << this->teamA.at(count)->getName() << " from " <<
		this->teamA.at(count)->getCountry()->getName()
		<< " and " << this->teamB.at(count%teamBCount)->getName()
		<< " from "
		<< this->teamB.at(count%teamBCount)->getCountry()->getName()
		<< "clash." << std::endl;

	    Logger::log(out.str());
	    out.clear();

	    this->teamA.at(count)->attack(* this->teamB.at(count%teamBCount), testing);
	    this->teamB.at(count%teamBCount)->attack(* this->teamA.at(count), testing);

	    this->teamA.at(count)->update();
	    this->teamB.at(count%teamBCount)->update();
	    totalCountTeamA += this->teamA.at(count)->getAmount();
	    totalCountTeamB += this->teamB.at(count%teamBCount)->getAmount();
	}
    }
    this->table->cleanUp();

    return true;
}

Battle::~Battle(){
}
