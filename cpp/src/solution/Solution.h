#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include "./LightCycle.h"
#include "../world/WorldSimulation.h"

using namespace std;
namespace fs = std::filesystem;

struct Solution {
    World *world;
    vector<LightCycle> lightCycles;

    Solution(World *world) {
        this->world = world;
    }

    int getScore() {
        WorldSimulation simulation(world, lightCycles);

        return 0;
    }

    void writeSolution(string fileName) const {
        cout << "Saving file " << fileName << "..." << endl;
        const string outputPath = "../../output/";

        fs::create_directory(outputPath);
        fs::remove(outputPath + fileName);
        ofstream outputFile(outputPath + fileName);

        const int numberOfIntersections = lightCycles.size();

        outputFile << numberOfIntersections << endl;

        for (auto &lightCycle : lightCycles) {
            outputFile << lightCycle.intersection->index << endl;
            outputFile << lightCycle.lightTimes.size() << endl;

            for (auto &lightTime : lightCycle.lightTimes) {
                outputFile << lightTime.street->name << " " << lightTime.duration << endl;
            }
        }

        outputFile.close();
        cout << "File saved!" << endl;
    }

    void LoadFromFile(const string &fileName, const World &world) {
        cout << "Loading solution file " << fileName << "..." << endl;
        ifstream inputFile("../../output/" + fileName);


        inputFile.close();
        cout << "Solution file loaded! (score:" << getScore() << ")" << endl;
    }
};