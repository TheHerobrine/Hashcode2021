#include <gtest/gtest.h>
#include "../src/world/World.h"
#include "../src/solution/Solution.h"
#include "./Lib.h"



TEST(solution, save) {
    World world;
    world.LoadFromFile("a.txt");

    Solution solution = buildSampleSolution(&world);

    EXPECT_EQ(solution.getScore(), 1002);

    solution.writeSolution("a_test.out");
}