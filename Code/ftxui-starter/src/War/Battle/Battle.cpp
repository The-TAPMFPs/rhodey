#include "Battle.h"

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