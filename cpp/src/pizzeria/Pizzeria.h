#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Ingredient.h"
#include "Pizza.h"

using namespace std;

struct Pizzeria {
    int teamsNumber[5];
    vector<Pizza*> pizzas;
    IngredientDatabase ingredientDatabase;

    void LoadFromFile(const string &fileName) {
        cout << "Loading file " << fileName << "..." << endl;
        ifstream inputFile("../../input/" + fileName);

        int pizzaNumber = 0;
        int ingredientsNumber = 0;

        inputFile >> pizzaNumber;
        inputFile >> teamsNumber[2] >> teamsNumber[3] >> teamsNumber[4];

        for (int i=0; i<pizzaNumber; i++)
        {
            Pizza* pizza = new Pizza();
            pizza->index = i;
            inputFile >> ingredientsNumber;

            for (int j=0; j<ingredientsNumber; j++)
            {
                string ingredientName;
                inputFile >> ingredientName;

                Ingredient* ingredient = ingredientDatabase.getIngredient(ingredientName);
                pizza->ingredients.push_back(ingredient);
            }

            pizzas.push_back(pizza);
        }

        inputFile.close();
        cout << "File loaded!" << endl;
    }
};