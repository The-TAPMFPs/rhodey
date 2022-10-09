// Copyright [2022] <Gustav Radloff Radloff>
#ifndef CODE_FTXUI_STARTER_SRC_CONGLOMERATE_H_
#define CODE_FTXUI_STARTER_SRC_CONGLOMERATE_H_
#include <string>
#include <vector>
#include <iostream>
class Conglomerate {
    friend class AllianceMember;
    friend class Alliance;
    private:
	std::string name;
    public:
	Conglomerate();
	explicit Conglomerate(std::string name);
	virtual void print()=0;
};
#endif  // CODE_FTXUI_STARTER_SRC_CONGLOMERATE_H_
