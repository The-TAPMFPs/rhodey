// Copyright [2022] <Gustav Daniel Radloff>
#ifndef CODE_FTXUI_STARTER_SRC_FACTION_H_
#define CODE_FTXUI_STARTER_SRC_FACTION_H_
#include "AllianceMember.h"
class Faction : public AllianceMember {
    public:
	Faction(std::string name) : AllianceMember(name) {};
};

#endif  // CODE_FTXUI_STARTER_SRC_FACTION_H_
