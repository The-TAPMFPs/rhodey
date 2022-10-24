#pragma once

#include "Alliance.h"
#include "BattleStrategy/BattleStrategy.h"
#include "../MapRegions/Region.h"

//Predefine classes to resolve circular dependencies:
class Region;
class Alliance;

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
  unsigned int sizeOfArmy();
  unsigned int prowessInRegion(Region* region);

  // TODO trainingFacilities vector<TroopFactory *>
  // TODO vehicleFactories vector<VehicleFactory *>
  Alliance* allies;
  public:
	Country(std::string name);
	std::string getName();
};