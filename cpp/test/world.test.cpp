#include <gtest/gtest.h>
#include "../src/world/World.h"

TEST(world, load) {
    World world;
    world.LoadFromFile("a.txt");

    EXPECT_EQ(world.cars.size(), 2);
    EXPECT_EQ(world.map.streets.size(), 5);
    EXPECT_EQ(world.map.intersections.size(), 4);

    EXPECT_EQ(world.cars[0]->path[0], world.map.streets[0]);
    EXPECT_EQ(world.cars[0]->path[1], world.map.streets[1]);

    EXPECT_EQ(world.map.intersections[0]->inStreets[0], world.map.streets[0]);
    EXPECT_EQ(world.map.intersections[0]->outStreets[0], world.map.streets[1]);
}