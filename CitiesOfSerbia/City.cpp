#include "City.h"

City::City(int topLeftCornerX, int topLeftCornerY, string name) {
	_topLeftCornerX = topLeftCornerX;
	_topLeftCornerY = topLeftCornerY;
	_name = name;
}


City::~City()
{
}

vector<string> City::GetAllCities() {
	vector<string> allCities = { "Subotica", "Sombor", "Kikinda", "Vrbas", "Zrenjanin", "Novi Sad", "Vrsac", "Sid", "Beograd", "Sabac",  "Pozarevac", "Valjevo", "Negotin", "Jagodina",
								 "Kragujevac", "Zajecar", "Cacak", "Kraljevo", "Krusevac", "Nis", "Pirot", "Leskovac", "Novi Pazar", "Kosovska Mitrovica", "Pristina", "Vranje", "Prizren" };

	return allCities;
}

int City::DetectChosenCity(int x, int y) {
	int k = 0;
	vector<vector<int>> level = CityMap::GetCityMap();

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			k = level[i][j];
			if (x >= j*CITY_SIZE && x <= j*CITY_SIZE+CITY_SIZE && y >= i*CITY_SIZE && y <= i*CITY_SIZE+CITY_SIZE) {
				return k;
			}
		}
	}
}