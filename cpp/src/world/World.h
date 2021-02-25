#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Intersection.h"
#include "Map.h"
#include "Car.h"

using namespace std;

struct World {
    int duration;
    Map map;
    vector<Car*> cars;

    void LoadFromFile(const string &fileName) {
        cout << "Loading file " << fileName << "..." << endl;
        ifstream inputFile("../../input/" + fileName);

        int intersectionsNumber;
        int streetsNumber;
        int carsNumber;
        int bonusPoints;

        inputFile >> duration >> intersectionsNumber >> streetsNumber >> carsNumber >> bonusPoints;

        for (int i = 0; i < intersectionsNumber; i++) {
            Intersection *intersection = new Intersection();
            intersection->index = i;
            map.intersections.push_back(intersection);
        }

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

            map.streets[streetName] = street;
        }

        for (int i=0; i <carsNumber; i++)
        {
            int pathLength;
            string streetName;
            inputFile >> pathLength;
            Car* car = new Car();

            for (int j=0; j<pathLength; j++)
            {
                inputFile >> streetName;
                car->path.push_back(map.streets[streetName]);
            }

            cars.push_back(car);
        }

        inputFile.close();
        cout << "File loaded!" << endl;
    }
};