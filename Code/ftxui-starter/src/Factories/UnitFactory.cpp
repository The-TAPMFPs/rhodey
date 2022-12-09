#include "UnitFactory.h"
#include "Country/Country.h"

UnitFactory::UnitFactory(std::string name, int num, Country * con)
 : name(name), num(num), country(con)
{
    weapons = this->country->getWeaponFlyweightFactory();
}

UnitFactory::~UnitFactory() {
}
