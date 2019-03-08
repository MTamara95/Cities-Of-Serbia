#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

#include "CityMap.h"

using namespace std;

const int CITY_SIZE = 20;
const int TOTAL_NUM_OF_CITIES = 27;


class City
{
public:
	City(int topLeftCornerX, int topLeftCornerY, string name);
	~City();

	static vector<string> GetAllCities();
	static int DetectChosenCity(int x, int y);

private:
	int _topLeftCornerX;
	int _topLeftCornerY;
	string _name;
};