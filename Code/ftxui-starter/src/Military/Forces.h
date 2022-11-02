#pragma once
#include "Regiment.h"


class Forces : public Military{
    private:
	std::string name;
	Region * region;
	vector<Regiment *> * airForce;
	vector<Regiment *> * army;
	vector<Regiment *> * navy;
    public:

};