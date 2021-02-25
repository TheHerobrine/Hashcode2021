#pragma once

#include <iostream>
#include <random>
#include <algorithm>

#include "../../pizzeria/Pizzeria.h"
#include "./Utils.h"

using namespace std;

struct PizzeriaInstance {
    int remainingTeam[5];
    vector<Street*> availablePizzas;

    PizzeriaInstance(Pizzeria pizzeria) {
        remainingTeam[2] = pizzeria.teamsNumber[2];
        remainingTeam[3] = pizzeria.teamsNumber[3];
        remainingTeam[4] = pizzeria.teamsNumber[4];

        for (auto &pizza : pizzeria.pizzas)
        {
            availablePizzas.push_back(pizza);
        }
    }

    bool IsDeliveryPossible() {
        const int possibleTeamNumber[] = {2, 3, 4};

        for (auto &teamNumber : possibleTeamNumber) {
            if (remainingTeam[teamNumber] > 0 &&
                availablePizzas.size() > teamNumber) {
                return true;
            }
        }
        return false;
    }

    void Shuffle() {
        random_device randomDevice;
        mt19937 generator(randomDevice());
        shuffle(availablePizzas.begin(), availablePizzas.end(), generator);
    }
};