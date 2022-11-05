#pragma once

#include "../../../lib/eigen3/Eigen/Dense"
#include "Alliance.h"
#include "BattleStrategy/BattleStrategy.h"
#include "../MapRegions/Map.h"
#include "BattleStrategy/Offensive.h"
#include "BattleStrategy/ResearchAndDevelopment.h"
#include "BattleStrategy/Defensive.h"
#include "BattleStrategy/Prepare.h"
#include "BattleStrategy/Diplomacy.h"



//Predefine classes to resolve circular dependencies:
class Region;
class Alliance;
class BattleStrategy;

class Country {
  private:
    std::string name;
    BattleStrategy* strategy;

    //===== STATS =====//
    int population;   // The number of citizens in the country
    double economy;   // The GDP
    double morale;    // The general morale of the country's citizens
    double resources;  // TODO: Reconsider this since it may be redundant with `economy`
    double research; // The amount of research points the country has
    double aggressiveness; // The aggressiveness of the country
    double goalRating; // The rating of the country's goal
    double numSpies;
    int numTroops;
    int numVehicles;
    int numEnemyRegions;
    BattleStrategy* strats[5];


    //===== CHARACTER MATRIX =====//

    
    Eigen::MatrixXd personalityMatrix;
    /*  m << 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; */

    //===== AGGREGATE STATS =====//
    unsigned int sizeOfArmy();
    unsigned int prowessInRegion(Region* region);

    // TODO trainingFacilities vector<TroopFactory *>
    // TODO vehicleFactories vector<VehicleFactory *>
    Alliance* allies;
  public:
    Country(std::string name);
    std::string getName();
    void takeTurn();
    void generatePersonalityMatrix();
    Eigen::MatrixXd generateValueMatrix();
    double* generateRandomNums(int num);
    void setStrategy(BattleStrategy* strategy);
    int nextStrategy();
    std::vector<std::string> getFormattedStats();
};