#include "Entities/WeaponTemplateMethod/Weapon.h"
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
    Country * countrytry;

    TroopFactoryTest() {
        countrytry = new Country("WillyWonka");
        uf1 = new TroopFactory("TroopFactory1", 5000, countrytry);
        e1 = uf1->makeUnit();
        countrytry->setResearch(0.3);
        uf2 = new TroopFactory("TroopFactory2", 5000, countrytry);
        e2 = uf2->makeUnit();
        countrytry->setResearch(0.9);
        uf3 = new TroopFactory("TroopFactory3", 5000, countrytry);
        e3 = uf3->makeUnit();
        e4 = uf3->makeUnit();
        e5 = uf3->makeUnit();
    }

    ~TroopFactoryTest(){
        delete uf1;
        delete uf2;
        delete uf3;
        delete countrytry;
    }
};

struct VehicleFactoryTest : testing::Test{
    UnitFactory * uf1;
    UnitFactory * uf2;
    UnitFactory * uf3;
    Entity * e1;
    Entity * e2;
    Entity * e3;
    Country * countrytry;
    VEHICLE_TYPE veh;

    VehicleFactoryTest(){
        countrytry = new Country("WillyWonka");
        veh = truck;
        uf1 = new VehicleFactory("VehicleFactory1", 100,  countrytry);
        e1 = uf1->makeUnit();
        veh = bomber;
        uf2 = new VehicleFactory("VehicleFactory2", 100, countrytry);
        uf2->makeUnit();
        veh = warship;
        uf3 = new VehicleFactory("VehicleFactory3", 100, countrytry);
        //uf3->makeUnit();
    }

    ~VehicleFactoryTest(){
        delete uf1;
        delete uf2;
        delete uf3;
        delete countrytry;
    }
};

//==========================================================================//
//============================START EntityTest==============================//

TEST_F(TroopFactoryTest, test1){
    EXPECT_EQ(e1->getName(), "TroopFactory1");
    EXPECT_EQ(e1->getAmount(), 5000);
    EXPECT_EQ(e1->getCountry()->getName(), "WillyWonka");
    std::vector<Weapon *> * v = new std::vector<Weapon*>{new SMG(), new Pistol()};
    EXPECT_NE(e1->getWeapon(), v);
}
