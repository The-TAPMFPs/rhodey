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
};

//==========================================================================//
//============================START EntityTest==============================//

TEST_F(TroopFactoryTest, test1){
    EXPECT_EQ(e1->getName(), "TroopFactory1");
    EXPECT_EQ(e1->getAmount(), 5000);
    EXPECT_EQ(e1->getCountry()->getName(), "WillyWonka");
    std::vector<Weapon *> * v = new std::vector<Weapon*>{new SMG(), new Pistol()};
    EXPECT_EQ(e1->getWeapon(), v);
}

TEST_F(TroopFactoryTest, test2){
    EXPECT_EQ(e2->getName(), "TroopFactory2");
    EXPECT_EQ(e2->getAmount(), 5000);
    EXPECT_EQ(e2->getCountry()->getName(), "WillyWonka");
    std::vector<Weapon *> * v =  new vector<Weapon *> {new AR(), new Pistol(), new Sniper()}
    EXPECT_EQ(e2->getWeapon(), v);
}

TEST_F(TroopFactoryTest, test3){
    std::vector<Weapon *> * v1 = new vector<Weapon *> {new AR(), new DualBurette(), new Sniper50(), new AK47()};
    std::vector<Weapon *> * v2 = new vector<Weapon *> {new AK47(), new DualBurette(), new Bazooka(), new Sniper50()};
    EXPECT_TRUE(e3->getWeapon() == v1 || e3->getWeapon() == v2);
    EXPECT_TRUE(e4->getWeapon() == v1 || e4->getWeapon() == v2);
}

TEST_F(VehicleFactoryTest, test4){
    EXPECT_EQ(e1->getName(), "VehicleFactory1");
    EXPECT_EQ(e1->getType(), truck);
}

TEST_F(VehicleFactoryTest, test5){
    EXPECT_EQ(e2->getName(), "VehicleFactory2");
    EXPECT_EQ(e2->getType(), truck);
}

TEST_F(VehicleFactoryTest, test6){
    EXPECT_EQ(e3->getName(), "VehicleFactory3");
    EXPECT_EQ(e3->getType(), truck);
}
