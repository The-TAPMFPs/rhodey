#include "UnitFactory.h"

UnitFactory::UnitFactory(std::string name, int num, Country * con)
 : _name(name), _num(num), _con(con)
{}

UnitFactory::UnitFactory(std::string name, int num, VEHICLE_TYPE type, Country * con)
 : _name(name), _num(num), _con(con), currVehicleType(type)
{}