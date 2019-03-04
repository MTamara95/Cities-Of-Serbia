#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

const int CITY_WIDTH = 20;
const int CITY_HEIGHT = 20;
const int TOTAL_NUM_OF_CITIES = 27;

class City
{
public:
	City(int topLeftCornerX, int topLeftCornerY, string name);
	~City();

	int GetTopLeftCornerX();
	int GetTopLeftCornerY();
	string GetName();

	static vector<City> GetAllCities();
	static int DetectChosenCity(int x, int y);

private:
	int _topLeftCornerX;
	int _topLeftCornerY;
	string _name;
};