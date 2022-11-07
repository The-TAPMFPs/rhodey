#include <gtest/gtest.h>
#include "War/War.h"
#include "War/WarPhases/WarPhase.h"
#include "War/WarPhases/Conflict.h"
#include "War/WarPhases/Dispute.h"
#include "War/WarPhases/DisputeSettled.h"
#include "War/WarPhases/Hostilities.h"
#include "War/WarPhases/PostWar.h"

struct WarPhaseTest : testing::Test {
    War* war;
    WarPhaseTest() {
        war = new War();
    }
    ~WarPhaseTest() {
        delete war;
    }
};

TEST_F(WarPhaseTest, StatePatternTest) {
    // Testinng the progression of the States
    EXPECT_EQ(war->warPhase->warPhase, phase::DISPUTE);
    war->changeState();
    EXPECT_EQ(war->warPhase->warPhase, phase::HOSTILITIES);
    war->changeState();
    EXPECT_EQ(war->warPhase->warPhase, phase::CONFLICT);
    war->changeState();
    EXPECT_EQ(war->warPhase->warPhase, phase::POST_WAR);
    war->changeState();
    EXPECT_EQ(war->warPhase->warPhase, phase::DISPUTE_SETTLED);
    war->changeState();
    EXPECT_EQ(war->warPhase == NULL, true);
}   

int main(int argc, char **argv) {
    int * test = new int(1);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}