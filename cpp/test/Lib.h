#include "../src/world/World.h"
#include "../src/solution/Solution.h"

Solution buildSampleSolution(World *world) {
    Solution solution(world);

    {
        LightCycle lightCycle;
        lightCycle.intersection = world->map.intersections[1];
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets[2],
                2
        });
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets[1],
                1
        });

        solution.lightCycles.push_back(lightCycle);
    }

    {
        LightCycle lightCycle;
        lightCycle.intersection = world->map.intersections[0];
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets[0],
                2
        });

        solution.lightCycles.push_back(lightCycle);
    }

    {
        LightCycle lightCycle;
        lightCycle.intersection = world->map.intersections[2];
        lightCycle.lightTimes.push_back(LightTime{
                world->map.streets[4],
                1
        });

        solution.lightCycles.push_back(lightCycle);
    }

    return solution;
}