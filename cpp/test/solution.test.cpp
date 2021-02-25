#include <gtest/gtest.h>
#include "../src/world/World.h"
#include "../src/solution/Solution.h"

Solution buildSampleSolution(World *world) {
    Solution solution(world);

    {
        LightCycle lightCycle;
        lightCycle.intersection = world->map.intersections[1];
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets["rue-d-athenes"],
                2
        });
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets["rue-d-amsterdam"],
                1
        });

        solution.lightCycles.push_back(lightCycle);
    }

    {
        LightCycle lightCycle;
        lightCycle.intersection = world->map.intersections[0];
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets["rue-de-londres"],
                2
        });

        solution.lightCycles.push_back(lightCycle);
    }

    {
        LightCycle lightCycle;
        lightCycle.intersection = world->map.intersections[2];
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets["rue-de-moscou"],
                1
        });

        solution.lightCycles.push_back(lightCycle);
    }

    return solution;
}

TEST(solution, save) {
    World world;
    world.LoadFromFile("a.txt");

    Solution solution = buildSampleSolution(&world);

    EXPECT_EQ(solution.getScore(), 1002);

    solution.writeSolution("a_test.out");
}