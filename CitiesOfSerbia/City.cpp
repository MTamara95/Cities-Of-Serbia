#include "City.h"

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

void City::PickFromAndToCity(int* numOfChosenCities, sf::Event event, int *firstCity, int *secondCity) {
	vector<string> allCities = City::GetAllCities();

	if ((*numOfChosenCities) == 0) {
		if (event.type == sf::Event::MouseButtonPressed) {
			*firstCity = City::DetectChosenCity(event.mouseButton.x, event.mouseButton.y);
			if (*firstCity < TOTAL_NUM_OF_CITIES) {
				cout << "From: " << allCities[*firstCity] << " (" << *firstCity + 1 << ")" << endl;
				(*numOfChosenCities)++;
			}
		}
	}
	else if ((*numOfChosenCities) == 1) {
		if (event.type == sf::Event::MouseButtonPressed) {
			*secondCity = City::DetectChosenCity(event.mouseButton.x, event.mouseButton.y);
			if (*secondCity < TOTAL_NUM_OF_CITIES) {
				cout << "To: " << allCities[*secondCity] << " (" << *secondCity + 1 << ")" << endl;
				(*numOfChosenCities)++;
			}
		}
	}
}