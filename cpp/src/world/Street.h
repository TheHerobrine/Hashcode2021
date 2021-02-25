#pragma once

#include <iostream>
#include <vector>
using namespace std;

struct Intersection;

struct Street {
    int index;
    string name;
    int length;
    Intersection* from;
    Intersection* to;
};