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

    Street *getActivatedStreet(int time) {
        int totalTime = 0;
        for (auto &lightTime : lightTimes) {
            totalTime += lightTime.duration;
        }

        time = time % totalTime;

        for (auto &lightTime : lightTimes) {
            time -= lightTime.duration;
            if (time <= 0)
            {
                return lightTime.street;
            }
        }
    }
};
