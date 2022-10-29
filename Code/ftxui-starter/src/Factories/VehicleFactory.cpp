#include "VehicleFactory.h"
#include "Entities/Vehicle/Vehicle.h"

VehicleFactory::VehicleFactory(std::string name, int hp, int num){
    _name = name;
    _hp = hp;
    _num = num
}

VehicleFactory::~VehicleFactory(){}

void VehicleFactory::setVehicleType(VEHICLE_TYPE type){
    currVehicleType = type;
}

Entity* VehicleFactory::makeUnit(){
    switch(currVehicleType){
        case truck:
            Vehicle tr = new truck();
            return tr;
        case tank:
            Vehicle ta = new Tank();
            return ta;
        case carrier:
            Vehicle 
        case cargoship:
        case warship:
        case submarine:
        case fighterjet:
        case bomber:
        case cargoplane:
    }
}
