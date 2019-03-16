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
	static vector<string> getAllCities();
	static int detectChosenCity(int x, int y, sf::RenderWindow& window);
	static void pickFromAndToCity(int* numOfChosenCities, sf::Event event, int *firstCity, int *secondCity, CityMap *map, sf::RenderWindow& window);
};