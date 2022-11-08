#include "Offensive.h"

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
    //enemyRergion = region with highest friendly ratio
    //friendlyRegion = region with lowest enemy ratio
}

/**
 * @fn void redistributeTroops
 * @brief Moves troops from one position to another in order to improve defense.
 * 
 */
void Offensive::redistributeTroops(){
    //move troops from region with lowest enemy troop count to region with highest friendly ratio
    OccupancyTable* occTable = map->getOccupancyTable();
    occTable->moveEntity(occTable->getEntities(friendlyRegion), enemyRegion);
    Logger::log(this->friendlyCountry->getName() + " has moved troops from " + this->friendlyRegion->getRegionName() + " to " + this->enemyRegion->getRegionName() + "\n");
    delete occTable;
}

/**
 * @fn void attack()
 * @brief Informs a country that it is in a position to take an aggresive stance against an enemy.
 * 
 */
void Offensive::attack(){
    OccupancyTable* occTable = map->getOccupancyTable();
    Battle* battle = new Battle(enemyRegion, occTable);
    Logger::log(this->friendlyCountry->getName() + " has started a battle in" + battle->getRegion()->getRegionName() + "\n");
    while(battle->takeTurn()){

    }

    std::vector<Entity *> teamA = battle->getTeamA();
    std::vector<Entity *> teamB = battle->getTeamB();
    std::vector<Country *> losers = battle->getLossers();
    Entity* winner;


    if(teamA.size()==0){
        winner = teamB.front();
        Logger::log(winner->getCountry()->getAlliance()->getName() + " has won the battle in " + battle->getRegion()->getRegionName() + "\n");
    }
    else{
        winner = teamA.front();
        Logger::log(winner->getCountry()->getAlliance()->getName() + " has won the battle in " + battle->getRegion()->getRegionName() + "\n");
    }

    srand((unsigned)time(NULL));
    double agg = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;
    double mor = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;
    double goal = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;

    for (auto it = begin (losers); it != end (losers); ++it) {
        (*it)->setAggressiveness((*it)->getAggressiveness() - agg);
        (*it)->setMorale((*it)->getMorale() + mor);
        (*it)->setGoalRating((*it)->getGoalRating() + goal);
    }
    


    delete battle;
    delete occTable;
    delete winner;
}

/**
 * @fn void setFriendlyRegion(Region* friendlyRegion)
 * @brief A setter for a Region that a country can move too.
 * 
 * @param friendlyRegion A Region reference to a region that is an ally.
 */
void Offensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

/**
 * @fn void setEnemyRegion(Region* enemyRegion)
 * @brief A setter for a Region that is owned by an enemy of a country.
 * 
 * @param friendlyRegion A Region reference to a region that is an enemy.
 */
void Offensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}

void Offensive::setFriendlyCountry(Country* friendlyCountry){
    this->friendlyCountry = friendlyCountry;
}
