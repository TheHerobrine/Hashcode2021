#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Intersection.h"
#include "Street.h"

using namespace std;

struct Car {
    int index;
    vector<Street*> path;
};