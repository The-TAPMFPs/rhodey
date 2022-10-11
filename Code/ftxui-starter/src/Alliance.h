// Copyright [2022] <Gustav Daniel Radloff>
#ifndef CODE_FTXUI_STARTER_SRC_ALLIANCE_H_
#define CODE_FTXUI_STARTER_SRC_ALLIANCE_H_
#include "Conglomerate.h"
#include <vector>
class Alliance : public Conglomerate {
    private:
	std::vector<Conglomerate *> members;
    public:
	Alliance(std::string name) : Conglomerate(name) {};
	void add(Conglomerate &);
	void print() override;
};
#endif  // CODE_FTXUI_STARTER_SRC_ALLIANCE_H_
