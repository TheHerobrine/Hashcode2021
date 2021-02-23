#pragma once

#include <iostream>
#include <vector>
#include "./Ingredient.h"
using namespace std;

struct Pizza {
    int index;
    vector<Ingredient*> ingredients;
};