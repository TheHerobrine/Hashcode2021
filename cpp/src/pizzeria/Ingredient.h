#pragma once

#include <iostream>

using namespace std;

struct Ingredient {
    int index;
    string name;
    int deliveryUsed;
};

struct IngredientDatabase {
    vector<Ingredient*> ingredients;

    Ingredient *getIngredient(const string &ingredientName) {
        for (auto &ingredient : ingredients) {
            if (ingredient->name == ingredientName) {
                return ingredient;
            }
        }
        const int nextIndex = ingredients.size();
        Ingredient* ingredient = new Ingredient{nextIndex, ingredientName};

        ingredients.push_back(ingredient);
        return ingredients.back();
    }
};