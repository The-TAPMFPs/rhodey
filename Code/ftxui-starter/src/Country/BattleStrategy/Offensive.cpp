#include "Offensive.h"

Offensive::Offensive(Map* map) : BattleStrategy(map) {}

// void Offensive::warAlgorithm(int off){
//     this->off =(_off) off;
//     switch(off){
//         case redOff:
//             redistributeTroops();
//             break;
//         case attOff:
//             attack();
//             break;
//     }
//     return;
// }

void Offensive::doStrategy(Country* country){
    //enemyRergion = region with highest friendly ratio
    //friendlyRegion = region with lowest enemy ratio
}

void Offensive::redistributeTroops(){
    //move troops from region with lowest enemy troop count to region with highest friendly ratio
    OccupancyTable* occTable = map->getOccupancyTable();
    occTable->moveEntity(occTable->getEntities(friendlyRegion), enemyRegion);
    Logger::log(this->friendlyCountry->getName() + " has moved troops from " + this->friendlyRegion->getRegionName() + " to " + this->enemyRegion->getRegionName() + "\n");
    delete occTable;
}

void Offensive::attack(){
    OccupancyTable* occTable = map->getOccupancyTable();
    Battle* battle = new Battle(enemyRegion, occTable);
    Logger::log(this->friendlyCountry->getName() + " has started a battle in" + battle->getRegion()->getRegionName() + "\n");
    while(battle->takeTurn()){

    }

    std::vector<Entity *> teamA = battle->getTeamA();
    std::vector<Entity *> teamB = battle->getTeamB();
    Entity* winner;

    


    if(teamA.size()==0){
        winner = teamB.front();
        Logger::log(winner->getCountry()->getName() + " has won the battle in " + battle->getRegion()->getRegionName() + "\n");
    }
    else{
        winner = teamA.front();
        Logger::log(winner->getCountry()->getName() + " has won the battle in " + battle->getRegion()->getRegionName() + "\n");
    }

    srand((unsigned)time(NULL));
    double agg = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;
    double mor = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;
    double goal = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;

    winner->getCountry()->setAggressiveness(winner->getCountry()->getAggressiveness() + agg);
    winner->getCountry()->setMorale(winner->getCountry()->getMorale() + mor);
    winner->getCountry()->setGoalRating(winner->getCountry()->getGoalRating() + goal);
    


    delete battle;
    delete occTable;
    delete winner;
}

void Offensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Offensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}

void Offensive::setFriendlyCountry(Country* friendlyCountry){
    this->friendlyCountry = friendlyCountry;
}
