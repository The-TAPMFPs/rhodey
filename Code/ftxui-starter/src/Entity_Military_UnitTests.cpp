#include <gtest/gtest.h>
#include <vector>
#include "Country/Alliance.h"
#include "Country/Country.h"
#include "Entities/Entity.h"
#include "Entities/Troop/Troop.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "MapRegions/Map.h"
#include "MapRegions/OccupancyTable.h"
#include "MapRegions/Region.h"
#include "War/Battle/Battle.h"
#include "gtest/gtest.h"
#include "Entities/Vehicle/GroundVehicle/Tank.h"
#include "Entities/Vehicle/GroundVehicle/Truck.h"
#include "Entities/Vehicle/AirVehicle/Bomber.h"
#include "Entities/Vehicle/AirVehicle/Fighterjet.h"
struct EntitityTest : testing::Test {
    Entity * friendly;
    Entity * hostile;
    Country * country1;
    Country * country2;


    EntitityTest() {
	vector<Weapon *> * weapons = new vector<Weapon *>;
	weapons->push_back(new TestWeapon());
	weapons->push_back(new TestWeapon());
	vector<Weapon *> * enemyWeapons = new vector<Weapon *>;
	enemyWeapons->push_back(new TestWeapon());
	enemyWeapons->push_back(new TestWeapon());
	this->country1 = new Country("Friends");
	this->country2 = new Country("Enemys");
	this->friendly = new Troop("My Squad", 100,  weapons, this->country1);
	this->hostile = new Troop("Enemy Squad", 50, enemyWeapons, this->country2);
    }
    ~EntitityTest() {
	delete friendly;
	delete hostile;
	delete country1;
	delete country2;
    }
    void reset(int friendlyCount, int hostileCount) {
	delete friendly;
	delete hostile;

	vector<Weapon *> * weapons = new vector<Weapon *>;
	weapons->push_back(new TestWeapon());
	weapons->push_back(new TestWeapon());
	vector<Weapon *> * enemyWeapons = new vector<Weapon *>;
	enemyWeapons->push_back(new TestWeapon());
	enemyWeapons->push_back(new TestWeapon());
	this->friendly = new Troop("My Squad", friendlyCount, weapons, this->country1);
	this->hostile = new Troop("Enemy Squad", hostileCount, enemyWeapons, this->country2);
    }
};

struct OccupancyTableTest : testing::Test {
    Entity * friendly;
    Entity * friendly2;
    Entity * hostile;
    Country * country1;
    Country * country2;
    Map * theMap;
    OccupancyTable * table;
    Region * aRegion;
    Region * bRegion;
    Alliance * friendlies;
    Alliance * baddies;
    std::vector<Region *> regions;

    OccupancyTableTest() {
	vector<Weapon *> * weapons = new vector<Weapon *>;
	weapons->push_back(new TestWeapon());
	weapons->push_back(new TestWeapon());
	vector<Weapon *> * weapons2 = new vector<Weapon *>;
	weapons2->push_back(new TestWeapon());
	weapons2->push_back(new TestWeapon());
	vector<Weapon *> * enemyWeapons = new vector<Weapon *>;
	enemyWeapons->push_back(new TestWeapon());
	enemyWeapons->push_back(new TestWeapon());
	// setup
	this->country1 = new Country("Friends");
	this->country2 = new Country("Enemys");
	this->friendlies = new Alliance("Friendlyies",true);
	this->baddies = new Alliance("Bad Guys", false);
	this->friendlies->add(country1);
	this->baddies->add(country2);
	this->friendly = new Troop("My Squad", 100, weapons, this->country1);
	this->friendly2 = new Troop("My Other Squad", 50, weapons2, this->country1);
	this->hostile = new Troop("Enemy Squad", 50, enemyWeapons, this->country2);

	this->theMap = new Map({this->country1, this->country2},true);
	this->table = new OccupancyTable(this->theMap);

	std::vector<MapCoords> regions = theMap->getRegionLocations();
	this->aRegion = theMap->getRegionAt(0, 0);
	this->bRegion = theMap->getRegionAt(49, 24);

	// testing addEntity function AND testing if duplicates are discarded.
	this->table->addEntity(this->friendly, aRegion);
	this->table->addEntity(this->hostile, aRegion);
	this->table->addEntity(this->hostile, aRegion);
	this->table->addEntity(this->friendly2, aRegion);
    }

    ~OccupancyTableTest() {
	delete theMap;
	delete table;
	delete country1;
	delete country2;
	delete friendlies;
	delete baddies;
    }

    float proportionOfTransport(Region * a, Region * b, Entity * x);

};

struct BattleTest : testing::Test {
    Entity * friendly;
    Entity * hostile;
    Country * country1;
    Country * country2;
    Map * theMap;
    OccupancyTable * table;
    Region * aRegion;
    Region * bRegion;
    Alliance * friendlies;
    Alliance * baddies;
    Battle * testBattle;
    std::vector<Region *> regions;

    BattleTest() {
	vector<Weapon *> * weapons = new vector<Weapon *>;
	weapons->push_back(new TestWeapon());
	weapons->push_back(new TestWeapon());
	vector<Weapon *> * weapons2 = new vector<Weapon *>;
	weapons2->push_back(new TestWeapon());
	weapons2->push_back(new TestWeapon());
	vector<Weapon *> * enemyWeapons = new vector<Weapon *>;
	enemyWeapons->push_back(new TestWeapon());
	enemyWeapons->push_back(new TestWeapon());
	// setup
	this->friendlies = new Alliance("Friendlyies",true);
	this->baddies = new Alliance("Bad Guys", false);
	this->country1 = new Country("Friends");
	this->country2 = new Country("Enemys");
	this->friendlies->add(country1);
	this->baddies->add(country2);
	this->friendly = new Troop("My Squad", 100, weapons, this->country1);
	this->hostile = new Troop("Enemy Squad", 50, enemyWeapons, this->country2);

	this->theMap = new Map({country1, country2},true);
	this->table = new OccupancyTable(this->theMap);

	std::vector<MapCoords> regions = theMap->getRegionLocations();
	this->aRegion = theMap->getRegionAt(regions.at(0).x, regions.at(0).y);
	this->bRegion = theMap->getRegionAt(regions.at(1).x, regions.at(1).y);

	// testing addEntity function AND testing if duplicates are discarded.
	this->table->addEntity(this->friendly, aRegion);
	this->table->addEntity(this->hostile, aRegion);
	this->table->addEntity(this->hostile, aRegion);
    }

    ~BattleTest() {
	delete theMap;
	delete table;
	delete country1;
	delete country2;
	delete friendlies;
	delete baddies;
    }
};

//==========================================================================//
//============================START EntityTest==============================//
TEST_F(EntitityTest, Initialize) {
    EXPECT_EQ(friendly->getAmount(), 100);
    EXPECT_EQ(this->friendly->getCarryingCapacity(), 100);
    EXPECT_EQ(this->friendly->getCountry(), this->country1);
    EXPECT_EQ(this->friendly->getDefenseStatus(), false);
    EXPECT_EQ(this->friendly->getTerrainHandling(), 3);
    EXPECT_EQ(friendly->getName(), "My Squad");
    EXPECT_EQ(friendly->getType(), "Ground Infantry");
}

TEST_F(EntitityTest, attackTest1) {
    hostile->attack(*friendly,true);
    friendly->attack(*hostile,true);
    EXPECT_EQ(friendly->getAmount(), 100);
    EXPECT_EQ(friendly->getDefenseStatus(), false);
    EXPECT_EQ(hostile->getAmount(), 50);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 93);
    EXPECT_EQ(hostile->getAmount(), 37);


    this->reset(100,100);
    hostile->attack(*friendly,true);
    friendly->attack(*hostile, true);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 87);
    EXPECT_EQ(hostile->getAmount(), 87);



    this->reset(10000,9000);
    hostile->attack(*friendly,true);
    friendly->attack(*hostile,true);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 8789);
    EXPECT_EQ(hostile->getAmount(), 7655);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 8789);
    EXPECT_EQ(hostile->getAmount(), 7655);
    hostile->attack(*friendly,true);
    friendly->attack(*hostile,true);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 7760);
    EXPECT_EQ(hostile->getAmount(), 6473);

    this->reset(100,50);
}

TEST_F(EntitityTest, SplitAndMerge) {
    Entity * splitup = this->friendly->split(50);
    EXPECT_EQ(splitup->getAmount(),50);
    EXPECT_EQ(friendly->getAmount(),50);
    friendly->absorb(splitup);
    EXPECT_EQ(splitup->getAmount(), 0);
    EXPECT_EQ(friendly->getAmount(), 100);
    delete splitup;
}

TEST_F(EntitityTest, AttackAgainstDifferentTypes) {
    std::vector<Weapon * > * v = new std::vector<Weapon *>{new TestWeapon()};
    std::vector<Weapon * > * v2 = new std::vector<Weapon *>{new TestWeapon()};
    Entity * tank = (Entity *) new Tank("Armour",2,v,country1);
    Entity * enemyTank = (Entity *) new Tank("Armour", 1, v2, country2);
    for (int count = 0; count < 10000; count++) {
	enemyTank->attack(*tank,true);
	tank->update();
    }
    EXPECT_EQ(tank->getAmount(), 2);
    enemyTank->assignWeapon(*(new TestBomb()));
    for (int count = 0; count < 10000; count++) {
	enemyTank->attack(*tank,true);
	tank->update();
    }
    EXPECT_LE(tank->getAmount(), 0);
}

TEST_F(EntitityTest, CountryKnowledgeTest) {
    country1->spyOnCountry(country2);
}

//============================END EntityTest================================//
//==========================================================================//

float OccupancyTableTest::proportionOfTransport(Region * a, Region * b, Entity * x) {
    EXPECT_NE(a,b);
    EXPECT_NE(a->getCoords().x, b->getCoords().x);
    EXPECT_NE(a->getCoords().y, b->getCoords().y);
    float difficulty = this->theMap->getTravelDifficulty(
	    a->getCoords(), b->getCoords(), true);
    float proportionToTransport = float(x->getTerrainHandling())/difficulty;
    float numberToTransport = x->getAmount()*proportionToTransport + 10;
    return numberToTransport;
}

//==========================================================================//
//============================START OccupancyTableTest======================//

TEST_F(OccupancyTableTest, NoDuplicates) {
    std::vector<Entity *> entities = this->table->getEntities(this->aRegion);
    EXPECT_EQ(entities.size(), 3);
}

TEST_F(OccupancyTableTest, whereAreEntities) {
    EXPECT_EQ(this->table->getRegion(this->friendly), aRegion);
    EXPECT_EQ(this->table->getRegion(this->hostile)->getUUID(), aRegion->getUUID());
}

TEST_F(OccupancyTableTest, EntitiesAtRegion) {
    std::vector<Entity *> entities = {friendly,hostile,friendly2};
    EXPECT_EQ(this->table->getEntities(aRegion), entities);
}

TEST_F(OccupancyTableTest,getNumTroops) {
    std::vector<Weapon *> * baddiesbombs = new std::vector<Weapon*>{new TestBomb()};
    Entity * theirBomber =(Entity *) new Bomber("7th AirForce Division", 2, baddiesbombs, this->country2);
    EXPECT_EQ(this->table->getNumTroops(country2), this->hostile->getAmount());
}

TEST_F(OccupancyTableTest, getNumVehicles) {
    std::vector<Weapon *> * baddiesbombs = new std::vector<Weapon*>{new TestBomb()};
    std::vector<Weapon *> * baddiestankWeapons = new std::vector<Weapon*>{new TestBomb()};
    Entity * theirBomber = (Entity *) new Bomber("7th AirForce Division", 2, baddiesbombs, this->country2);
    Entity * tank = (Entity *) new Tank("7th AirForce Division", 6, baddiestankWeapons, this->country2);
    this->table->addEntity(theirBomber, aRegion);
    this->table->addEntity(tank, aRegion);
    EXPECT_EQ(this->table->getNumVehicles(country2), tank->getAmount() + theirBomber->getAmount());
}

TEST_F(OccupancyTableTest, CheckThatCantMergeWithWrongType) {
    std::vector<Weapon *> * tankWeapons = new std::vector<Weapon*>{new TestBomb()};
    this->table->addEntity((Entity *) new Tank("My Squad", 1, tankWeapons, country1), aRegion);
    vector<Entity *> entities = this->table->getEntities(aRegion);
    EXPECT_EQ(entities.size(),4);

};
// Test if moving a single entity between regions works as expected.
TEST_F(OccupancyTableTest, MoveSingleEntity) {
    // Check that movement is correct
    float expected = proportionOfTransport(aRegion, bRegion, friendly);
    this->table->moveEntity(friendly, bRegion);
    vector<Entity*> entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.at(0)->getAmount(), 2);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(hostile, bRegion);
    entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.size(), 2);
    EXPECT_EQ(entities.at(0)->getAmount(), 4);
    EXPECT_EQ(entities.at(1)->getAmount(), 2);
    EXPECT_EQ(friendly->getAmount(), 96);
    // Check that entities are not the same one.
    EXPECT_NE(entities.at(0), friendly);

    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    entities = this->table->getEntities(bRegion);
    EXPECT_EQ(this->friendly->getAmount(), 76);
    EXPECT_EQ(entities.size(), 2);
    EXPECT_EQ(entities.at(0)->getAmount(), 24);
    EXPECT_EQ(entities.at(1)->getAmount(), 2);
}

TEST_F(OccupancyTableTest, CheckMulipleMoveConditions) {
    std::vector<Weapon *> * v = new std::vector<Weapon*>{new TestWeapon};
    Entity * newEnt = new Troop("test", 10,v,this->country1);
    this->table->addEntity(newEnt, bRegion);
    // check if from different places cant move together
    EXPECT_ANY_THROW(this->table->moveEntity({friendly, newEnt}, bRegion));
    // check if opposing factions can't move together
    EXPECT_ANY_THROW(this->table->moveEntity({hostile, friendly2}, bRegion));
}

TEST_F(OccupancyTableTest, MulitpleMoveOfSameType) {
    this->table->moveEntity({friendly, friendly2}, bRegion);
    vector<Entity *> entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.size(), 2);
    entities = this->table->getEntities(aRegion);
    EXPECT_EQ(entities.size(), 3);
    this->table->moveEntity({friendly, friendly2}, bRegion);
    this->table->moveEntity({friendly, friendly2}, bRegion);
    entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.at(0)->getAmount(), 6);
    EXPECT_EQ(entities.at(1)->getAmount(), 3);
    EXPECT_EQ(entities.size(), 2);
}

TEST_F(OccupancyTableTest, MulitpleMoveOfDifferentTypes) {
    Entity * carConvoy = (Entity *) new Truck("Convoy", 6, NULL, country1);
    this->table->addEntity(carConvoy, aRegion);
    this->table->moveEntity({carConvoy,friendly}, bRegion);
    std::vector<Entity *> v = this->table->getEntities(bRegion);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.at(0)->getAmount(),2);
    EXPECT_EQ(v.at(1)->getAmount(),37);
    this->table->moveEntity({carConvoy,friendly}, bRegion);
    this->table->moveEntity({carConvoy,friendly}, bRegion);
    EXPECT_EQ(v.at(0)->getAmount(),4);
    EXPECT_EQ(v.at(1)->getAmount(),77);

    this->table->moveEntity({carConvoy,friendly}, bRegion);
    EXPECT_EQ(v.at(0)->getAmount(),4);
    EXPECT_NE(v.at(0),carConvoy);
    EXPECT_EQ(v.at(1)->getAmount(),87);
    this->table->moveEntity({carConvoy,friendly}, bRegion);

    EXPECT_EQ(v.at(0)->getAmount(),5);
    EXPECT_NE(v.at(0),carConvoy);
    EXPECT_EQ(v.at(1)->getAmount(),95);

    this->table->moveEntity({carConvoy,friendly}, bRegion);
    this->table->moveEntity({carConvoy,friendly}, bRegion);
    v = this->table->getEntities(bRegion);
    EXPECT_EQ(v.at(0),carConvoy);
    EXPECT_EQ(v.at(0)->getAmount(),6);
    EXPECT_EQ(v.at(1)->getAmount(),100);
}

//============================END OccupancyTableTest========================//
//==========================================================================//

//==========================================================================//
//==============================START BattleTest============================//
TEST_F(BattleTest, InitializeToRegion) {
    this->testBattle = new Battle(this->aRegion, this->table);
    EXPECT_EQ(this->testBattle->getRegion(), this->aRegion);
    std::vector<Entity *> teamA = {friendly};
    std::vector<Entity *> teamB = {hostile};
    EXPECT_EQ(this->testBattle->getTeamA(), teamA);
    EXPECT_EQ(this->testBattle->getTeamB(), teamB);
}

TEST_F(BattleTest, RunBattleBetweenJustTwo) {
    this->testBattle = new Battle(this->aRegion, this->table,true);
    EXPECT_EQ(friendly->getAmount(), 100);
    EXPECT_EQ(hostile->getAmount(), 50);
    this->testBattle->takeTurn();
    EXPECT_EQ(friendly->getAmount(), 93);
    EXPECT_EQ(hostile->getAmount(), 37);
}

TEST_F(BattleTest, RunBattle) {
    this->testBattle = new Battle(this->aRegion, this->table,true);
    std::vector<Weapon *> * tankWeapons = new std::vector<Weapon*>{new TestWeapon(), new TestWeapon()};
    Entity * friendly2 = new Troop("Other One", 50, tankWeapons, country1);
    this->table->addEntity(friendly2, aRegion);
    this->testBattle->takeTurn();

    // have to check due to randomness
    if (friendly->getAmount() == 94) {
	EXPECT_EQ(friendly2->getAmount(), 43);
    } else {
	EXPECT_EQ(friendly2->getAmount(), 45);
	EXPECT_EQ(friendly->getAmount(), 93);
    }
    EXPECT_EQ(hostile->getAmount(), 30);
}

TEST_F(BattleTest, getLosser) {
    Country * newCountry = new Country("COuntry C");
    this->friendlies->add(newCountry);
    std::vector<Weapon *> * tankWeapons = new std::vector<Weapon*>{new TestBomb()};
    std::vector<Weapon *> * baddiesbombs = new std::vector<Weapon*>{new TestBomb()};
    Entity * myTank = (Entity *) new Tank("My Squad", 1, tankWeapons, newCountry);
    Entity * theirBomber =(Entity *) new Bomber("7th AirForce Division", 100000, baddiesbombs, this->country2);
    this->table->addEntity(myTank, aRegion);
    this->table->addEntity(theirBomber,aRegion);
    Battle * newBattle = new Battle(aRegion,this->table,true);
    while (newBattle->takeTurn()) {};

    std::vector<Country *> v = newBattle->getLossers();
    std::vector<Entity *> shouldBeEmpty = newBattle->getTeamA();
    EXPECT_EQ(shouldBeEmpty.size(), 0);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.at(1), this->country1);
    EXPECT_EQ(v.at(0), newCountry);
}
TEST_F(BattleTest, BigBattle) {
    std::vector<Weapon *> * tankWeapons = new std::vector<Weapon*>{new TestBomb()};
    std::vector<Weapon *> * bomberfriends = new std::vector<Weapon*>{new TestBomb()};
    std::vector<Weapon *> * baddiesbombs = new std::vector<Weapon*>{new TestBomb()};
    Entity * myTank = (Entity *) new Tank("My Squad", 1, tankWeapons, this->country1);
    Entity * myBomber = (Entity *) new Bomber("7th AirForce Division", 2, bomberfriends, this->country1);
    Entity * theirBomber =(Entity *) new Bomber("7th AirForce Division", 2, baddiesbombs, this->country2);
    this->table->addEntity(myTank,aRegion);
    this->table->addEntity(myBomber,aRegion);
    this->table->addEntity(theirBomber,aRegion);
    std::vector<Entity *> v = {friendly, hostile, myTank,myBomber,theirBomber};
    EXPECT_EQ(this->table->getEntities(aRegion), v);
    this->testBattle = new Battle(this->aRegion, this->table,true);
    this->testBattle->takeTurn();
    EXPECT_EQ(this->table->getEntities(aRegion), v);
    v = this->table->getEntities(aRegion);
    EXPECT_EQ(v.at(1)->getAmount(), 21);
    EXPECT_EQ(v.at(1)->getName(), "Enemy Squad");
    this->testBattle->takeTurn();
    this->testBattle->takeTurn();
    v = {friendly, myTank,myBomber,theirBomber};
    EXPECT_EQ(this->table->getEntities(aRegion), v);
    EXPECT_NE(v.at(1)->getName(), "Enemy Squad");
}


TEST_F(BattleTest, VeryBigBattle) {
    // Weapons ===============================================================
    std::vector<Weapon *> * tankWeapons =
	new std::vector<Weapon*>{new TestBomb()};
    std::vector<Weapon *> * fighterWeapons =
	new std::vector<Weapon*>{new TestBomb(), new TestBomb()};
    std::vector<Weapon *> * baddiesbombs =
	new std::vector<Weapon*>{new TestBomb()};
    std::vector<Weapon *> * enemyTankWeapons =
	new std::vector<Weapon * >{new TestBomb()};

    std::vector<Weapon *> * friendlyTroops1Weapons =
	new std::vector<Weapon *>{new TestWeapon(),new TestWeapon(),
	    new TestWeapon(),new TestWeapon()};
    std::vector<Weapon *> * friendlyTroops2Weapons =
	new std::vector<Weapon *>{new TestWeapon(),new TestWeapon(),
	    new TestWeapon()};
    std::vector<Weapon *> * badTroops1Weapons =
	new std::vector<Weapon *>{new TestWeapon(),new TestWeapon(),
	    new TestWeapon(),new TestWeapon()};
    std::vector<Weapon *> * badTroops2Weapons =
	new std::vector<Weapon *>{new TestWeapon(),new TestWeapon(),
	    new TestWeapon()};

    // Entities ==============================================================
    Tank * friendlyTank = new Tank("Armour",10,tankWeapons,country1);
    Fighterjet * friendlyFighterjet = new Fighterjet("Air Force",3,fighterWeapons,country1);
    Troop * friendlyTroop1 =  new Troop("5th Battalion",1000,friendlyTroops1Weapons,country1);
    Troop * friendlyTroop2 =  new Troop("4th Battalion",500,friendlyTroops2Weapons,country1);

    Tank * badTanks = new Tank("Armour",15,enemyTankWeapons,country2);
    Bomber * badBomber = new Bomber("Air Force",5,baddiesbombs,country2);
    Troop * badTroop1 =  new Troop("5th Battalion",1200,badTroops1Weapons,country2);
    Troop * badTroop2 =  new Troop("4th Battalion",500,badTroops2Weapons,country2);

    this->table->addEntity((Entity*)friendlyTank, bRegion);
    this->table->addEntity((Entity*)friendlyFighterjet, bRegion);
    this->table->addEntity((Entity*)friendlyTroop1, bRegion);
    this->table->addEntity((Entity*)friendlyTroop2, bRegion);
    this->table->addEntity((Entity*)badTroop1, bRegion);
    this->table->addEntity((Entity*)badTroop2, bRegion);
    this->table->addEntity((Entity*)badTanks, bRegion);
    this->table->addEntity((Entity*)badBomber, bRegion);
    EXPECT_EQ(this->table->getEntities(bRegion).size(), 8);

    // Battle
    Battle * newBattle = new Battle(bRegion,this->table,true);
    int count = 0;
    while (newBattle->takeTurn()) {
	count++;
    }
    EXPECT_EQ(count,36);
    std::vector<Entity *> all = this->table->getEntities(bRegion);
    for (auto itr = all.begin(); itr != all.end(); ++itr) {
	EXPECT_EQ((*itr)->getCountry(), country2);
    }
}
//==============================END BattleTest============================//
//==========================================================================//

int main(int argc, char **argv) {
    int * test = new int(1);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
