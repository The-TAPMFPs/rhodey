#include <gtest/gtest.h>
#include <cmath>
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
#include "Entities/Vehicle/AirVehicle/Bomber.h"

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
	this->friendly = new Troop("My Squad", 100, weapons, this->country1);
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
	this->friendly2 = new Troop("My Other Squad", 50, weapons2, this->country1);
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
	this->table->addEntity(this->friendly2, aRegion);
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
    hostile->attack(*friendly);
    friendly->attack(*hostile);
    EXPECT_EQ(friendly->getAmount(), 100);
    EXPECT_EQ(friendly->getDefenseStatus(), false);
    EXPECT_EQ(hostile->getAmount(), 50);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 87);
    EXPECT_EQ(hostile->getAmount(), 20);


    this->reset(100,100);
    hostile->attack(*friendly);
    friendly->attack(*hostile);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 70);
    EXPECT_EQ(hostile->getAmount(), 70);



    this->reset(10000,9000);
    hostile->attack(*friendly);
    friendly->attack(*hostile);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 5277);
    EXPECT_EQ(hostile->getAmount(), 3698);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 5277);
    EXPECT_EQ(hostile->getAmount(), 3698);
    hostile->attack(*friendly);
    friendly->attack(*hostile);
    friendly->update();
    hostile->update();
    EXPECT_EQ(friendly->getAmount(), 3503);
    EXPECT_EQ(hostile->getAmount(), 1073);

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

// Test if moving a single entity between regions works as expected.
TEST_F(OccupancyTableTest, MoveSingleEntity) {
    // Check that movement is correct
    float expected = proportionOfTransport(aRegion, bRegion, friendly);
    this->table->moveEntity(friendly, bRegion);
    vector<Entity*> entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.at(0)->getAmount(), 10);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(hostile, bRegion);
    entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.at(0)->getAmount(), 20);
    EXPECT_EQ(entities.at(1)->getAmount(), 50);
    EXPECT_EQ(friendly->getAmount(), 80);
    // Check that entities are not the same one.
    EXPECT_NE(entities.at(0), friendly);

    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.size(), 2);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(friendly, bRegion);
    entities = this->table->getEntities(bRegion);
    EXPECT_EQ(this->friendly->getAmount(), 100);
    EXPECT_EQ(entities.size(), 2);
    EXPECT_EQ(entities.at(0)->getAmount(), 50);
    EXPECT_EQ(entities.at(1)->getAmount(), 100);
    EXPECT_EQ(entities.at(1), friendly);
}

TEST_F(OccupancyTableTest, CheckMulipleMoveConditions) {
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
    // check if from different places cant move together
    EXPECT_ANY_THROW(this->table->moveEntity({friendly, friendly2}, bRegion));
    // check if opposing factions can't move together
    EXPECT_ANY_THROW(this->table->moveEntity({hostile, friendly2}, bRegion));
}

TEST_F(OccupancyTableTest, MulitpleMoveOfSameType) {
    // TODO: Waiting for dino to fix his function
    this->table->moveEntity({friendly, friendly2}, bRegion);
    vector<Entity *> entities = this->table->getEntities(bRegion);
    //EXPECT_EQ(entities.size(), 2);
}

TEST_F(OccupancyTableTest, Attacking) {
    this->table->moveEntity(friendly, bRegion);
    this->table->moveEntity(hostile, bRegion);
    vector<Entity *> entities = this->table->getEntities(bRegion);
    EXPECT_EQ(entities.at(0)->getAmount(), 10);
    EXPECT_EQ(entities.at(1)->getAmount(), 50);

};
//============================END OccupancyTableTest========================//
//==========================================================================//

//==========================================================================//
//==============================START BattleTest============================//
TEST_F(BattleTest, InitializeToRegion) {
    this->testBattle = new Battle(this->aRegion, this->table);
    EXPECT_EQ(this->testBattle->getRegion(), this->aRegion);
    std::vector<Entity *> teamA = {friendly, friendly2};
    std::vector<Entity *> teamB = {hostile};
    EXPECT_EQ(this->testBattle->getTeamA(), teamA);
    EXPECT_EQ(this->testBattle->getTeamB(), teamB);
}

TEST_F(BattleTest, RunBattleBetweenJustTwo) {
    this->table->moveEntity(friendly2, bRegion);
    this->table->moveEntity(friendly2, bRegion);
    this->table->moveEntity(friendly2, bRegion);
    this->table->moveEntity(friendly2, bRegion);
    this->table->moveEntity(friendly2, bRegion);
    std::vector<Entity *> v = {friendly, hostile};

    EXPECT_EQ(this->table->getEntities(aRegion), v);
    this->testBattle = new Battle(this->aRegion, this->table);
    EXPECT_EQ(friendly->getAmount(), 100);
    EXPECT_EQ(hostile->getAmount(), 50);
    this->testBattle->takeTurn();
    EXPECT_EQ(friendly->getAmount(), 87);
    EXPECT_EQ(hostile->getAmount(), 20);
}

TEST_F(BattleTest, RunBattle) {
    this->testBattle = new Battle(this->aRegion, this->table);
    this->testBattle->takeTurn();

    // have to check due to randomness
    if (friendly->getAmount() == 92) {
	EXPECT_EQ(friendly2->getAmount(), 37);
    } else {
	EXPECT_EQ(friendly2->getAmount(), 46);
	EXPECT_EQ(friendly->getAmount(), 87);
    }
    EXPECT_EQ(hostile->getAmount(), 8);
}

TEST_F(BattleTest, BigBattle) {
    std::vector<Weapon *> * tankWeapons = new std::vector<Weapon*>{new Cannon()};
    std::vector<Weapon *> * bomberfriends = new std::vector<Weapon*>{new Cannon()};
    std::vector<Weapon *> * baddiesbombs = new std::vector<Weapon*>{new Cannon()};
    this->table->addEntity((Entity *) new Tank("7th Heavy Armour Division", 50, tankWeapons, country1), aRegion);
    this->table->addEntity((Entity *) new Bomber("7th AirForce Division", 2, bomberfriends, country1), aRegion);
    this->table->addEntity((Entity *) new Bomber("7th AirForce Division", 2, baddiesbombs, country2), aRegion);
    this->testBattle = new Battle(this->aRegion, this->table);
    this->testBattle->takeTurn();
    std::vector<Entity *> v = {friendly};
    //EXPECT_EQ(this->table->getEntities(aRegion), v);
}
//==============================END BattleTest============================//
//==========================================================================//

int main(int argc, char **argv) {
    int * test = new int(1);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
