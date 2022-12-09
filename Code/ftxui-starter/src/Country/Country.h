#pragma once

#include <memory>
#include <vector>

#include "../../../lib/eigen3/Eigen/Dense"
#include "Alliance.h"
#include "Observable.h"

//Predefine classes to resolve circular dependencies:

class WeaponFlyweightFactory;
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
    Region * capital;
    // TODO trainingFacilities vector<TroopFactory *>
    // TODO vehicleFactories vector<VehicleFactory *>
    Alliance* allies;
    std::vector<std::pair<Country*, double>> countriesBeingSpiedOn;
    std::shared_ptr<WeaponFlyweightFactory> weaponFactory; // Used to keep references to weapons in factories.

    //===== STATS =====//
    int population;   // The number of citizens in the country
    double economy;   // The GDP
    double resources;  // TODO: Reconsider this since it may be redundant with `economy`
    double research; // The amount of research points the country has
    double aggressiveness; // The aggressiveness of the country
    double goalRating; // The rating of the country's goal
    double morale;    // The general morale of the country's citizens
    double numSpies;
    int numTroops;
    int numVehicles;
    int numEnemyRegions;

    //===== CHARACTER MATRIX =====//
    Eigen::MatrixXd personalityMatrix;
    /*  m <<    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; */

    //===== AGGREGATE STATS =====//
    int sizeOfArmy();
    int prowessInRegion(Region* region);

  public:
    Country(std::string name);
    ~Country();
    void takeTurn();
    void generatePersonalityMatrix();
    Eigen::MatrixXd generateValueMatrix();
    double* generateRandomNums(int num);
    void decideStrategy();
    void validateValues();
    void improveMillitary();

    // Getters and Setters
    double getAggressiveness() {return this->aggressiveness;}
    Alliance * getAlliance() {return this->allies;}
    Region * getCapital() {return this->capital;}
    std::vector<std::pair<Country*, double>>* getCountriesBeingSpiedOn() {
	return &this->countriesBeingSpiedOn;}
    double getEconomy() {return this->economy;}
    std::vector<std::string> getFormattedStats();
    double getGoalRating() {return this->goalRating;}
    Map * getMap() {return this->map;}
    double getMorale() {return this->morale;}
    std::string getName() {return this->name;}
    int getNumSpies() {return this->numSpies;}
    int getNumTroops() {return this->numTroops;}
    int getNumVehicles() {return this->numVehicles;}
    int getNumEnemyRegions() {return this->numEnemyRegions;}
    int getPopulation() {return this->population;}
    double getResearch() {return this->research;}
    double getResources() {return this->resources;}
    std::shared_ptr<WeaponFlyweightFactory> getWeaponFlyweightFactory() {
	return this->weaponFactory;}

    void setAggressiveness(double aggressiveness) {
	this->aggressiveness = aggressiveness;}
    void setCapital(Region *);
    void setEconomy(double economy) {this->economy = economy;}
    void setGoalRating(double goalRating) {this->goalRating = goalRating;}
    void setMap(Map *map);
    void setMorale(double morale) {this->morale = morale;}
    void setNumSpies(int numSpies);
    void setNumTroops(int numTroops);
    void setNumVehicles(int numVehicles);
    void setNumEnemyRegions(int numEnemyRegions);
    void setPopulation(int population) {this->population = population;}
    void setResearch(double research) {this->research = research;}
    void setResources(double resources) {this->resources = resources;}
    void setStrategy(BattleStrategy* strategy) {this->strategy = strategy;}
};


