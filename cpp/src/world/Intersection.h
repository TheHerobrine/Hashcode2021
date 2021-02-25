#pragma once

#include <iostream>
#include <vector>

#include "Street.h"

using namespace std;

struct Intersection {
    int index;
    vector<Street*> inStreets;
    vector<Street*> outStreets;
};