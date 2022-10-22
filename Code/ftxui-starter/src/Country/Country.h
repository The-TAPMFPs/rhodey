#pragma once

#include "Alliance.h"
#include "BattleStrategy.h"

class Country {
 private:
  std::string name;
  BattleStrategy* strategy;

  //===== STATS =====//
  int population;   // The number of citizens in the country
  double economy;   // The GDP
  double morale;    // The general morale of the country's citizens
  double supplies;  // TODO: Reconsider this since it may be redundant with
                    // `economy`
  double attrition;
  double aggressiveness;

  //===== AGGREGATE STATS =====//
  unsigned int sizeOfArmy() {
    return 0;  // TODO: Calculate based off of troops
  }
  unsigned int prowessInRegion(Region* region) {}

  // TODO trainingFacilities vector<TroopFactory *>
  // TODO vehicleFactories vector<VehicleFactory *>
  Alliance* allies;
  public:
	Country(std::string name);
	std::string getName();
};