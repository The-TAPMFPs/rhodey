#include <gtest/gtest.h>
#include "Military/Forces.h"
#include "Entities/Troop/Troop.h"
#include "gtest/gtest.h"

struct EntitityTest : testing::Test {
    Entity * friendly;
    Entity * hostile;

    EntitityTest() {
	vector<Weapon *> * weapons = new vector<Weapon *>;
	weapons->push_back(new TestWeapon());
	weapons->push_back(new TestWeapon());
	vector<Weapon *> * enemyWeapons = new vector<Weapon *>;
	enemyWeapons->push_back(new TestWeapon());
	enemyWeapons->push_back(new TestWeapon());
	this->friendly = new Troop("My Squad", 100, weapons);
	this->hostile = new Troop("Enemy Squad", 50, enemyWeapons);
    }
    ~EntitityTest() {
	delete friendly;
	delete hostile;
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
	this->friendly = new Troop("My Squad", friendlyCount, weapons);
	this->hostile = new Troop("Enemy Squad", hostileCount, enemyWeapons);
    }
};

TEST_F(EntitityTest, Initialize) {
    EXPECT_EQ(friendly->getAmount(), 100);
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

int main(int argc, char **argv) {
    int * test = new int(1);
    delete test;
    delete test;
    delete test;
    delete test;
    delete test;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
