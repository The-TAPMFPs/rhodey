#include "gtest/gtest.h"
#include "Factories/UnitFactory.h"
#include "Factories/TroopFactory.h"
#include "Factories/VehicleFactory.h"
#include "Country/Country.h"
#include "Entities/Entity.h"

struct TroopFactoryTest : testing::Test{
    UnitFactory * uf1;
    UnitFactory * uf2;
    UnitFactory * uf3;
    Entity * e1;
    Entity * e2;
    Entity * e3;
    Entity * e4;
    Entity * e5;
    Country * cunt;

    TroopFactoryTest() {
        cunt = new Country("WillyWonka");
        uf1 = new TroopFactory("TroopFactory1", 5000, cunt);
        e1 = uf1->makeUnit();
        cunt->setResearch(0.3);
        uf2 = new TroopFactory("TroopFactory2", 5000, cunt);
        e2 = uf2->makeUnit();
        cunt->setResearch(0.9);
        uf3 = new TroopFactory("TroopFactory3", 5000, cunt);
        e3 = uf3->makeUnit();
        e4 = uf3->makeUnit();
        e5 = uf3->makeUnit();
    }

    ~TroopFactoryTest(){
        delete uf1;
        delete uf2;
        delete uf3;
        delete cunt;
    }
};

struct VehicleFactoryTest : testing::Test{
    UnitFactory * uf1;
    UnitFactory * uf2;
    UnitFactory * uf3;
    Entity * e1;
    Entity * e2;
    Entity * e3;
    Country * cunt;
    VEHICLE_TYPE veh;

    VehicleFactoryTest(){
        cunt = new Country("WillyWonka");
        veh = truck;
        uf1 = new VehicleFactory("VehicleFactory1", 100, veh, cunt);
        e1 = uf1->makeUnit();
        veh = bomber;
        uf2 = new VehicleFactory("VehicleFactory2", 100, veh, cunt);
        uf2->makeUnit();
        veh = warship;
        uf3 = new VehicleFactory("VehicleFactory3", 100, veh, cunt);
        //uf3->makeUnit();
    }

    ~VehicleFactoryTest(){
        delete uf1;
        delete uf2;
        delete uf3;
        delete cunt; 
    }
}

//==========================================================================//
//============================START EntityTest==============================//

TEST_F(TroopFactoryTest, test1){
    EXPECT_EQ(e1->getName(), "TroopFactory1");
    EXPECT_EQ(e1->getAmount(), 5000);
    EXPECT_EQ(e1->getCountry()->getName(), "WillyWonka");
    EXPECT_EQ(e1->getWeapon(), {smg, pis});
}