#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include "World.h"
#include "Solution.h"

using namespace std;

struct SimulatedCar;

struct SimulatedStreet {
    Street *street;
    queue<SimulatedCar *> carQueue;
};


struct Position {
    SimulatedStreet *simulatedStreet;
    int timeToEnd = 0;
};

struct SimulatedCar {
    Car *car;
    Position position;
    int pathIndex = 0;

    void Tick() {
        if (position.timeToEnd > 0) {
            position.timeToEnd--;

            if (position.timeToEnd == 0) {
                position.simulatedStreet->carQueue.push(this);
            }
        }
    }
};

struct WorldSimulation {
    World *world;
    LightCycle *lightCycle;
    int score;
    int elapsedTime = 0;

    vector<SimulatedCar *> simulatedCars;
    vector<SimulatedStreet *> simulatedStreets;

    WorldSimulation(World *world, vector<LightCycle> &lightCycles) {
        this->world = world;
        this->lightCycle = lightCycle;

        for (auto &street: world->map.streets) {
            SimulatedStreet *simulatedStreet = new SimulatedStreet();
            simulatedStreet->street = street.second;
            simulatedStreets.push_back(simulatedStreet);
        }

        for (auto &car : world->cars) {
            SimulatedCar *simulatedCar = new SimulatedCar();
            simulatedCar->car = car;
            simulatedCar->position = Position{
                    simulatedStreets[car->path[0]->index],
                    0
            };

            simulatedCars.push_back(simulatedCar);

            simulatedStreets[car->path[0]->index]->carQueue.push(simulatedCar);
        }
    }

    void Tick() {
        for (auto &intersection: world->map.intersections) {

        }

        for (auto &simulatedCar: simulatedCars) {
            simulatedCar->Tick();
        }

        elapsedTime++;
    }
};