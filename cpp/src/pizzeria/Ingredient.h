#pragma once

#include <iostream>

using namespace std;

struct Ingredient {
    int index;
    string name;
    int deliveryUsed;
};

struct IngredientDatabase {
    map<string, Ingredient *> ingredients;
    int currentIndex = 0;

    Ingredient *getIngredient(const string &ingredientName) {
        if (ingredients.contains(ingredientName)) {
            return ingredients[ingredientName];
        }

        Ingredient *ingredient = new Ingredient{currentIndex++, ingredientName};
        ingredients[ingredientName] = ingredient;
        return ingredients[ingredientName];
    }
};