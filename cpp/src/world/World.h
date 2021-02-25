#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "Intersection.h"
#include "Map.h"
#include "Car.h"

using namespace std;

struct World {
    int duration;
    int bonusPoints;
    Map map;
    vector<Car *> cars;

    void LoadFromFile(const string &fileName) {
        cout << "Loading file " << fileName << "..." << endl;
        ifstream inputFile("../../input/" + fileName);

        int intersectionsNumber;
        int streetsNumber;
        int carsNumber;

        inputFile >> duration >> intersectionsNumber >> streetsNumber >> carsNumber >> bonusPoints;

        for (int i = 0; i < intersectionsNumber; i++) {
            Intersection *intersection = new Intersection();
            intersection->index = i;
            map.intersections.push_back(intersection);
        }

        ::map<string, int> streetsDictionary;

        for (int i = 0; i < streetsNumber; i++) {
            int from, to;
            string streetName;
            int streetLength;

            inputFile >> from >> to >> streetName >> streetLength;

            Street *street = new Street();
            street->index = i;
            street->from = map.intersections[from];
            street->to = map.intersections[to];
            street->length = streetLength;
            street->name = streetName;

            map.intersections[from]->outStreets.push_back(street);
            map.intersections[to]->inStreets.push_back(street);

            map.streets.push_back(street);
            streetsDictionary[streetName] = i;
        }

        for (int i = 0; i < carsNumber; i++) {
            int pathLength;
            string streetName;
            inputFile >> pathLength;
            Car *car = new Car();

            car->index = i;

            for (int j = 0; j < pathLength; j++) {
                inputFile >> streetName;
                car->path.push_back(map.streets[streetsDictionary[streetName]]);
            }

            cars.push_back(car);
        }

        inputFile.close();
        cout << "File loaded!" << endl;
    }
};