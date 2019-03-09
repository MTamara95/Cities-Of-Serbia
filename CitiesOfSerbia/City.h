#pragma once

#include <iostream>
#include <vector>

#include "CityMap.h"

using namespace std;

const int CITY_SIZE = 20;
const int TOTAL_NUM_OF_CITIES = 27;

// forward declaration
class CityMap;

class City
{
public:
	static vector<string> GetAllCities();
	static int DetectChosenCity(int x, int y);
	static void PickFromAndToCity(int* numOfChosenCities, sf::Event event, int *firstCity, int *secondCity, CityMap *map, sf::RenderWindow& window);
};