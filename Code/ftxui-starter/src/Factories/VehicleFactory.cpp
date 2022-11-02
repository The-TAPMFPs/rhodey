#include "VehicleFactory.h"

VehicleFactory::VehicleFactory(std::string name, int hp, int num){
    _name = name;
    _num = num;
    AR* ar;
    SMG* smg;
    Pistol* pis;
    w1 =  new vector<Weapon *> {ar, smg, pis};
}

VehicleFactory::~VehicleFactory(){}

void VehicleFactory::setVehicleType(VEHICLE_TYPE type){
    currVehicleType = type;
}

Entity* VehicleFactory::makeUnit(){
    switch(currVehicleType){
        case truck:
            Truck* v1 = new Truck(_name, _num, w1);
            return v1;
        case tank:
        case carrier:
        case cargoship:
        case warship:
        case submarine:
        case fighterjet:
        case bomber:
        case cargoplane:
    }
}
