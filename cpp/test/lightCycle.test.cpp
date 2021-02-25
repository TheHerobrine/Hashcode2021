#include <gtest/gtest.h>
#include "../src/solution/LightCycle.h"

TEST(lightCycle, street) {
    World world;
    world.LoadFromFile("a.txt");

    LightCycle lightCycle;


    Solution solution = buildSampleSolution(&world);

    EXPECT_EQ(solution.getScore(), 1002);

    solution.writeSolution("a_test.out");
}