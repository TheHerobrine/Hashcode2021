#pragma once

#include <iostream>
#include <algorithm>

#include "../../pizzeria/Pizzeria.h"
#include "../../solution/Solution.h"
#include "./Lib.h"
#include "./Utils.h"

using namespace std;

struct Solver {
    Pizzeria pizzeria;
    Solution savedSolution;

    void Load(string fileName) {
        pizzeria.LoadFromFile(fileName);
    }

    void LoadSolution(string fileName) {
        savedSolution.LoadFromFile(fileName, pizzeria);
    }

    void Improve(string fileName) {
        int currentScore = savedSolution.getScore();

        int tryNumber = 100000;
        for (int i = 0; i < tryNumber; i++) {
            const Solution solution = generateRandomSolution();
            const int score = solution.getScore();

            if (score > currentScore) {
                cout << "Found better score: " << score << "(+" << score - currentScore << ")" << endl;
                currentScore = score;
                savedSolution = solution;
                savedSolution.writeSolution(fileName);
            }
        }
    }

    void Solve() {
        Solution bestSolution;
        int bestScore = 0;
        int tryNumber = 1000;

        for (int i = 0; i < tryNumber; i++) {
            if (i % 10 == 0) {
                cout << "Generating random solution (" << i << "/" << tryNumber << ")" << endl;
            }

            const Solution solution = generateRandomSolution();
            const int score = solution.getScore();

            if (score > bestScore) {
                bestScore = score;
                bestSolution = solution;
            }
        }

        cout << "Best score found: " << bestScore << endl;
        savedSolution = bestSolution;
    }

    Solution generateRandomSolution() {
        Solution solution;
        PizzeriaInstance pizzeriaInstance(pizzeria);
        pizzeriaInstance.Shuffle();

        while (pizzeriaInstance.IsDeliveryPossible()) {
            const int maxRandom = min(int(pizzeriaInstance.availablePizzas.size()) - 2, 2) + 1;
            const int teamSize = rand() % maxRandom + 2;

            if (pizzeriaInstance.remainingTeam[teamSize] > 0) {
                pizzeriaInstance.remainingTeam[teamSize]--;
                Delivery delivery;
                delivery.teamSize = teamSize;

                for (int i = 0; i < teamSize; i++) {
                    delivery.pizzas.push_back(pizzeriaInstance.availablePizzas.back());
                    pizzeriaInstance.availablePizzas.pop_back();
                }

                solution.deliveries.push_back(delivery);
            }
        }

        return solution;
    }
};