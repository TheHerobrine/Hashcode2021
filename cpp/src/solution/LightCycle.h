#pragma once

#include <iostream>
#include <vector>
#include "../world/World.h"

using namespace std;

struct LightTime {
    Street *street;
    int duration;
};

struct LightCycle {
    Intersection *intersection;
    vector<LightTime> lightTimes;
};
