#pragma once

#include <iostream>
#include <vector>
#include "../pizzeria/Pizza.h"
using namespace std;

struct Delivery {
    int teamSize = 0;
    vector<Pizza*> pizzas;
};