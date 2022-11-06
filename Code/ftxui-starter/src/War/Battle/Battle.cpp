#include "Battle.h"
/**
 * \fn void Battle::Battle(std::vector<Forces*> attackingForces, std::vector<Forces*> defendingForces, Region* region, Country* country)
 * \brief constructor that sets all battle 
 * 
 * \return the region at the specified coordinates
 */
Battle::Battle(std::vector<Forces*> attackingForces, std::vector<Forces*> defendingForces, Region* region, Country* country){
    _attackingForces = attackingForces;
    _defendingForces = defendingForces;
    _country = country;
    _region = region;
}

void Battle::start(){
    
}

void Battle::end(){

}

Battle::~Battle(){}