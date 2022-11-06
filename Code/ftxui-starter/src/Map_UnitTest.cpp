#include <gtest/gtest.h>
#include "MapRegions/Map.h"
#include "MapRegions/MapCaretaker.h"

struct MapTest : testing::Test {
    Map* testMap1, *testMap2;

    MapTest() {
        testMap1 = new Map();
        testMap2 = new Map();
    }

    ~MapTest() {
        delete testMap1;
        delete testMap2;
    }

    bool travelFieldsEqual(scalarField2D field1, scalarField2D field2) {
        for (int i = 0; i < testMap1->mapW; i++) {
            for (int j = 0; j < testMap2->mapH; j++) {
                if (field1[i][j] != field2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

TEST_F(MapTest, MapMementoTest) {
    MapCaretaker* caretaker = new MapCaretaker();
    caretaker->addMemento(testMap1->makeMemento());

    testMap2->setMemento(caretaker->removeMemento());

    EXPECT_EQ(travelFieldsEqual(testMap1->getTravelFieldA(), testMap2->getTravelFieldA()), true);
    EXPECT_EQ(travelFieldsEqual(testMap1->getTravelFieldB(), testMap2->getTravelFieldB()), true);
    
    delete caretaker;
}

int main(int argc, char **argv) {
    int * test = new int(1);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}