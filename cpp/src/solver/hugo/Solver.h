#pragma once

#include <iostream>
#include <algorithm>

#include "../../solution/Solution.h"
//#include "./Lib.h"
//#include "./Utils.h"

using namespace std;

struct Solver {
    World world;
    Solution *savedSolution;

    void Load(string fileName) {
        world.LoadFromFile(fileName);
    }

/*
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
*/

    void Solve() {
        int bestScore = 0;
        int tryNumber = 10;

        for (int i = 0; i < tryNumber; i++) {
            cout << "Generating random solution (" << i << "/" << tryNumber << ")" << endl;

            Solution *solution = generateRandomSolution();
            int score = solution->getScore();

            if (score > bestScore) {
                bestScore = score;
                cout << "Best score found: " << bestScore << endl;
                //delete savedSolution;
                savedSolution = solution;
            } else {
                //delete solution;
            }
        }
    }

    Solution *generateRandomSolution() {
        Solution *solution = new Solution(&world);

        for (auto &intersection : world.map.intersections) {
            LightCycle lightCycle;
            lightCycle.intersection = intersection;

            for (auto &street: intersection->inStreets) {
                LightTime lightTime{};
                lightTime.duration = 3;
                lightTime.street = street;
                lightCycle.lightTimes.push_back(lightTime);
            }

            solution->lightCycles.push_back(lightCycle);
        }

        return solution;
    }
};