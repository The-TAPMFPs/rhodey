#include <gtest/gtest.h>
#include "Country/Country.h"
#include "Entities/Troop/Troop.h"
#include "MapRegions/Map.h"
#include "MapRegions/OccupancyTable.h"
#include "MapRegions/Region.h"
#include "gtest/gtest.h"

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
    Entity * hostile;
    Country * country1;
    Country * country2;
    Map * theMap;
    OccupancyTable * table;
    Region * aRegion; /// Region at (20,20)

    OccupancyTableTest() {
	vector<Weapon *> * weapons = new vector<Weapon *>;
	weapons->push_back(new TestWeapon());
	weapons->push_back(new TestWeapon());
	vector<Weapon *> * enemyWeapons = new vector<Weapon *>;
	enemyWeapons->push_back(new TestWeapon());
	enemyWeapons->push_back(new TestWeapon());
	// setup
	this->country1 = new Country("Friends");
	this->country2 = new Country("Enemys");
	this->friendly = new Troop("My Squad", 100, weapons, this->country1);
	this->hostile = new Troop("Enemy Squad", 50, enemyWeapons, this->country2);
	this->theMap = new Map();
	this->table = new OccupancyTable(this->theMap);

	std::vector<MapCoords> regions = theMap->getRegionLocations();
	this->aRegion = theMap->getRegionAt(regions.at(1).x, regions.at(1).y);
	// testing addEntity function AND testing if duplicates are discarded.
	this->table->addEntity(this->friendly, aRegion);
	this->table->addEntity(this->hostile, aRegion);
	this->table->addEntity(this->hostile, aRegion);
    }

    ~OccupancyTableTest() {
	delete friendly;
	delete hostile;
	delete theMap;
	delete table;
	delete country1;
	delete country2;
    }
};
//==========================================================================//
//============================START EntityTest==============================//
TEST_F(EntitityTest, Initialize) {
    EXPECT_EQ(friendly->getAmount(), 100);
    EXPECT_EQ(friendly->getName(), "My Squad");
    EXPECT_EQ(this->friendly->getCarryingCapacity(), 0);
    EXPECT_EQ(this->friendly->getDefenseStatus(), false);
    EXPECT_EQ(this->friendly->getTerrainHandling(), 0);
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

//============================END EntityTest================================//
//==========================================================================//

//==========================================================================//
//============================START OccupancyTableTest======================//
TEST_F(OccupancyTableTest, NoDuplicates) {
    std::vector<Entity *> entities = this->table->getEntities(this->aRegion);
    EXPECT_EQ(entities.size(), 2);
}

TEST_F(OccupancyTableTest, whereAreEntities) {
    EXPECT_EQ(this->table->getRegion(this->friendly), aRegion);
    EXPECT_EQ(this->table->getRegion(this->hostile)->getUUID(), aRegion->getUUID());
}

TEST_F(OccupancyTableTest, MoveEntities) {

}
//============================END OccupancyTableTest========================//
//==========================================================================//

int main(int argc, char **argv) {
    int * test = new int(1);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
