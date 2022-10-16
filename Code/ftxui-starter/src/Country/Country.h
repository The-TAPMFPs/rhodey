#pragma once

#include "Alliance.h"
#include "BattleStrategy.h"

class Country : protected AllianceMember {
	private:
		BattleStrategy * strategy;

		//===== STATS =====//
		int population;		//The number of citizens in the country
		double economy;		//The GDP
		double morale;		//The general morale of the country's citizens
		double supplies;	//TODO: Reconsider this since it may be redundant with `economy`
		double attrition;
		double aggressiveness;

		//===== AGGREGATE STATS =====//
		unsigned int sizeOfArmy() {
			return 0; //TODO: Calculate based off of troops
		}
		unsigned int prowessInRegion(Region* region) {

		}

		// TODO trainingFacilities vector<TroopFactory *>
		// TODO vehicleFactories vector<VehicleFactory *>
		Alliance * allies;

    public:
		// TODO Functions that we can use here?
		Country(std::string name) : AllianceMember(name){};
};