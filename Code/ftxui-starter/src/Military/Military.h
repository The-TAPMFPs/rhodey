#pragma once
#include "Forces.h"
#include "SpyAgency.h"
#include <vector>


class Military{
    private:
        std::vector<Forces*> battleGroups;
        std::vector<SpyAgency*> spies;
    public:
        virtual void move() = 0;
        ~Military();
};