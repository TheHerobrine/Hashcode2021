#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Intersection.h"
#include "Street.h"

using namespace std;

struct Car {
    vector<Street*> path;
};