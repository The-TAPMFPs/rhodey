#include "Offensive.h"
#include "War/Battle/Battle.h"

/**
 * @file Offensive.cpp
 * @brief Construct a new Offensive Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022
 */

/**
 * @fn Offensive(Map* map)
 * @brief The constructor for the Offensive class.
 *
 * @param map allows access to the map
 */
Offensive::Offensive(Map* map) : BattleStrategy(map) {}


void Offensive::doStrategy(Country* country){
    if (country == NULL) {
	throw new exception();
    }
    std::vector<Region*> regionsForAttack = map->getAllAvailableRegionsForAttack(country);
    int rIndex = uuid::randomInt(0, regionsForAttack.size()-1);

    Battle* battle = new Battle(regionsForAttack[rIndex], map->getOccupancyTable(), false);

    while(battle->takeTurn()) {} //Simulate battle
    vector<Country*> winners;
    try {
	winners = battle->getWinners();
    } catch(StaleMate& e) {
	Logger::log("Stale Mate after battle in: " + regionsForAttack[rIndex]->getRegionName());
	return;
    }

    winners = battle->getWinners();

    float n = map->getEnemyRatioInRegion(regionsForAttack[rIndex], country->getAlliance()->isTeamA());

    Logger::log(std::to_string(n) + "winners");

    if(winners.size() > 0)
    {
        regionsForAttack[rIndex]->setPossessor(winners[uuid::randomInt(0, winners.size()-1)]);
        map->recalculateTravelFields();
    }

    //TODO: Increase morale on win

    // Region* toAttack = map->getTeamsRegionWithEnemyRatio(country->getAlliance()->isTeamA(), true, false);

    // for(auto r = regionsForAttack.begin(); r != regionsForAttack.end(); r++)
    // {

    // }
}
