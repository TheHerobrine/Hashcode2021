#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "Intersection.h"
#include "Street.h"

using namespace std;

struct Map {
    vector<Intersection*> intersections;
    vector<Street*> streets;
};