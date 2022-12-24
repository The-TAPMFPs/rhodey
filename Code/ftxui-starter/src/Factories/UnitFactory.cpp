#include "UnitFactory.h"
#include <climits>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "Country/Country.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"

UnitFactory::UnitFactory(std::string name, int num, Country * con)
 : name(name), num(num), country(con)
{
    weapons = this->country->getWeaponFlyweightFactory();
    this->batalionNumber = 1;
}

UnitFactory::~UnitFactory() {
}

void UnitFactory::ouputCreationFlair(vector<Weapon *> weapons) {
    std::stringstream convert; /**<A stringstream to concentate the intital message.>*/
    std::map<std::string,std::string> uniqueNames; /**<The only reason a map is
						     used here is becuase it is
						     fast and i didn't want to
						     create a new data structure
						     just for lookups>*/
    convert << "A battalion of troops armed with: ";
    for (int count = 0; count < weapons.size(); count++) { // get all the unique names
	if (uniqueNames.find(weapons.at(count)->getName()) == uniqueNames.end()) {
	    uniqueNames.emplace(
	      pair<std::string, std::string>(
		weapons.at(count)->getName(),
		weapons.at(count)->getName()
		)
	      );
	}
    }

    // Iterate through all the unique names to build a string.
    for (auto iter = uniqueNames.begin(); iter != (--uniqueNames.end()); ++iter) {
	convert << iter->second << ", ";
    }

    convert << "and " << (--uniqueNames.end())->second << " were recruited.";
    Logger::log(convert.str());
}

int UnitFactory::numberToProduce(int num) {
    int toReturn = num;
    if (num == INT_MIN) {
	if (this->country->getPopulation() < 1000000 + num*100) {
	    toReturn = toReturn/3;
	}
    }
    return toReturn;
}

std::string UnitFactory::incAndGetBatalionNumber() {
    this->batalionNumber = this->batalionNumber%20;
    std::stringstream temp;
    temp << ++this->batalionNumber;
    return temp.str();
}



