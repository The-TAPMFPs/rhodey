#pragma once

#include <vector>
#include <utility>

#include "../../../lib/eigen3/Eigen/Dense"
#include "Alliance.h"
#include "Observable.h"

// #include "../Factories/TroopFactory.h"
// #include "../Factories/VehicleFactory.h"

//Predefine classes to resolve circular dependencies:

class Alliance;
class BattleStrategy;
class Map;
class Region;

class Country : public Observable {
    friend class Alliance;
    friend class Intel;
#ifdef UNIT_TEST
    public:
#else
    private:
#endif

    Map* map;
    std::string name;
    BattleStrategy* strategy;

    //===== STATS =====//
    int population;   // The number of citizens in the country
    double economy;   // The GDP
    double resources;  // TODO: Reconsider this since it may be redundant with `economy`
    double research; // The amount of research points the country has
    double aggressiveness; // The aggressiveness of the country
    double goalRating; // The rating of the country's goal
    double numSpies;
    int numTroops;
    int numVehicles;
    int numEnemyRegions;

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
    std::vector<std::pair<Country*, double>> countriesBeingSpiedOn;
  public:
    double morale;    // The general morale of the country's citizens
    Country(std::string name);
    Country(std::string name, Map* map);
    ~Country();
    std::string getName();
    void takeTurn();
    void generatePersonalityMatrix();
    Eigen::MatrixXd generateValueMatrix();
    double* generateRandomNums(int num);
    void setStrategy(BattleStrategy* strategy);
    void decideStrategy();
    std::vector<std::string> getFormattedStats();
    Alliance * getAlliance() {return this->allies;}
    std::vector<std::pair<Country*, double>>* getCountriesBeingSpiedOn();
    double getMorale();
    double getEconomy();
    int getPopulation();
    double getResearch();
    double getGoalRating();
    double getAggressiveness();
    double getResources();
    int getNumSpies();
    int getNumTroops();
    int getNumVehicles();
    int getNumEnemyRegions();
    void setMorale(double morale);
    void setEconomy(double economy);
    void setPopulation(int population);
    void setResearch(double research);
    void setGoalRating(double goalRating);
    void setAggressiveness(double aggressiveness);
    void setResources(double resources);
    void setNumSpies(int numSpies);
    void setNumTroops(int numTroops);
    void setNumVehicles(int numVehicles);
    void setNumEnemyRegions(int numEnemyRegions);
};


