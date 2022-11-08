/**
 * \file Battle.h
 * \brief Header File for the Battle class.
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \version 1.0
 * \date 6 November 2022
 */
#pragma once

#include <vector>
#include "../../MapRegions/OccupancyTable.h"
#include "Country/Country.h"
#include <unordered_set>

class Battle{
    private:
        Region * _region;
	OccupancyTable * table;
        std::vector<Entity *> teamA;
        std::vector<Entity *> teamB;
	void checkReinforcements();
	bool testing = false;
	unordered_set<Country *> allianceAInvolved;
	unordered_set<Country *> allianceBInvolved;
    public:
	/**
	 * \fn Battle::Battle(Region *, OccupancyTable *)
	 * \brief Creates a Battle.
	 *
	 * \param a Region where the battle will take place.
	 * \param b OccupancyTable of the Simulation
	 * \return  Nothing
	 */
        Battle(Region* region, OccupancyTable *, bool testing = false);
	/**
	 * \fn Battle::takeTurn()
	 * \brief Simulates one turn of battle.
	 *
	 * \return  If the battle has concluded, then it will return false. if there are still troops
	 * fighting then it will return true.
	 */
	bool takeTurn();
	Region * getRegion() {return this->_region;};
	std::vector<Entity *> getTeamA() {return this->teamA;}
	std::vector<Entity *> getTeamB() {return this->teamB;}
	std::vector<Country *> getLossers();
	std::vector<Country *> getWinners();
        ~Battle();
};
