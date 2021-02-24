#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include "./Delivery.h"

using namespace std;
namespace fs = std::filesystem;

struct Solution {
    vector<Delivery> deliveries;

    int getScore() const {
        int score = 0;

        for (auto &delivery : deliveries) {

            set<int> ingredientsIndex;

            for (auto &pizza : delivery.pizzas) {
                for (auto &ingredient : pizza->ingredients) {
                    ingredientsIndex.insert(ingredient->index);
                }
            }

            const int numberOfIngredients = ingredientsIndex.size();
            score += numberOfIngredients * numberOfIngredients;
        }

        return score;
    }

    void writeSolution(string fileName) const {
        cout << "Saving file " << fileName << "..." << endl;
        const string outputPath = "../../output/";

        fs::create_directory(outputPath);
        fs::remove(outputPath + fileName);
        ofstream outputFile(outputPath + fileName);

        const int numberOfDelivery = deliveries.size();

        outputFile << numberOfDelivery << endl;

        for (auto &delivery : deliveries) {
            outputFile << delivery.teamSize;

            for (auto &pizza : delivery.pizzas) {
                outputFile << " " << pizza->index;
            }

            outputFile << endl;
        }

        outputFile.close();
        cout << "File saved!" << endl;
    }
};