#ifndef CODE_FTXUI_STARTER_SRC_ALLIANCE_MEMBER_H_
#define CODE_FTXUI_STARTER_SRC_ALLIANCE_MEMBER_H_
#include "BattleStrategy.h"
#include "Conglomerate.h"
#include "Alliance.h"
class AllianceMember : public Conglomerate {
    friend class Country;
    private:
	BattleStrategy * strategy;
	long int sizeOfArmy;
	long int population;
	double economy;
	double morale;
	double supplies;
	double resolve; // TODO I feel like this is redundent
	double attrition; // TODO I feel like this is redundent

	// TODO locations : vector<Location *>
	// TODO trainingFacilities vector<TroopFactory *>
	// TODO vehicleFactories vector<VehicleFactory *>
	Alliance * allies;
    public:
	void print() override;
	AllianceMember(std::string name) : Conglomerate(name) {};
};

#endif  // CODE_FTXUI_STARTER_SRC_ALLIANCE_MEMBER_H_
