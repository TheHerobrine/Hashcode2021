#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include "World.h"
#include "../solution/Solution.h"

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
    bool active = true;

    void Tick() {
        if (position.timeToEnd > 0) {
            position.timeToEnd--;

            if (position.timeToEnd == 0) {
                if (!HasArrived()) {
                    if (car->index == 954)
                    {
                        cout << "toast" << endl;
                    }

                    position.simulatedStreet->carQueue.push(this);
                }
            }
        }
    }

    bool HasArrived() {
        return (position.timeToEnd == 0) && (pathIndex >= car->path.size() - 1);
    }
};

struct WorldSimulation {
    World *world;
    vector<LightCycle> *lightCycles;
    int score = 0;
    int elapsedTime = 0;

    vector<SimulatedCar *> simulatedCars;
    vector<SimulatedStreet *> simulatedStreets;

    WorldSimulation(World *world, vector<LightCycle> *lightCycles) {
        this->world = world;
        this->lightCycles = lightCycles;

        for (auto &street: world->map.streets) {
            SimulatedStreet *simulatedStreet = new SimulatedStreet();
            simulatedStreet->street = street;
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

    void Launch() {
        for (int i = 0; i < world->duration; i++) {
            Tick();
        }
    }

    void Tick() {
        for (auto &lightCycle: *lightCycles) {
            Street *street = lightCycle.getActivatedStreet(elapsedTime);

            if (!simulatedStreets[street->index]->carQueue.size()) {
                continue;
            }

            SimulatedCar *simulatedCar = simulatedStreets[street->index]->carQueue.front();
            if (simulatedCar->car->index == 954)
            {
                cout << "toast" << endl;
            }
            simulatedStreets[street->index]->carQueue.pop();

            if (simulatedCar->HasArrived()) {
                continue;
            }

            simulatedCar->pathIndex++;
            simulatedCar->position.simulatedStreet = simulatedStreets[simulatedCar->car->path[simulatedCar->pathIndex]->index];
            simulatedCar->position.timeToEnd = simulatedCar->car->path[simulatedCar->pathIndex]->length;
        }

        for (auto &simulatedCar: simulatedCars) {
            if (!simulatedCar->active) {
                continue;
            }

            if (simulatedCar->HasArrived()) {
                simulatedCar->active = false;
                score += world->bonusPoints + world->duration - elapsedTime;
                continue;
            }

            simulatedCar->Tick();
        }

        elapsedTime++;
    }
};