#ifndef  CODE_FTXUI_STARTER_SRC_COUNTRY_H_
#define CODE_FTXUI_STARTER_SRC_COUNTRY_H_
#include "AllianceMember.h"
#include "Alliance.h"
#include "BattleStrategy.h"
class Country : protected AllianceMember {
    public:
	// TODO Functions that we can use here?
	Country(std::string name) : AllianceMember(name){};
};
#endif  // CODE_FTXUI_STARTER_SRC_COUNTRY_H_
