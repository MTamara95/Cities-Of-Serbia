#include "City.h"

vector<string> City::getAllCities() {
	vector<string> allCities = { "Subotica", "Sombor", "Kikinda", "Vrbas", "Zrenjanin", "Novi Sad", "Vrsac", "Sid", "Beograd", "Sabac",  "Pozarevac", "Valjevo", "Negotin", "Jagodina",
								 "Kragujevac", "Zajecar", "Cacak", "Kraljevo", "Krusevac", "Nis", "Pirot", "Leskovac", "Novi Pazar", "Kosovska Mitrovica", "Pristina", "Vranje", "Prizren" };

	return allCities;
}

int City::detectChosenCity(int x, int y) {
	int k = 0;
	vector<vector<int>> level = CityMap::getCityMap();

	// detecting chosen city:

	// pixelTopLeftX := j*CITY_SIZE
	// pixelTopLeftY := i*CITY_SIZE
	// (x, y) - coordinates of a chosen pixel; (pixelTopLeftX, pixelTopLeftY) - coordinates of pixel value of city which is on level[i][j] position

	// we checking if (x, y) belongs to a square with TopLeftCoordinates (pixelTopLeftX, pixelTopLeftY):
	// (pixelTopLeftX, pixelTopLeftY+CITY_SIZE), (pixelTopLeftX+CITY_SIZE, pixelTopLeftY+CITY_SIZE), (pixelTopLeftX+CITY_SIZE, pixelTopLeftY), (pixelTopLeftX, pixelTopLeftY)
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			k = level[i][j];
			if (x >= j*CITY_SIZE && x <= j*CITY_SIZE+CITY_SIZE && y >= i*CITY_SIZE && y <= i*CITY_SIZE+CITY_SIZE) {
				return k;
			}
		}
	}
}

void City::pickFromAndToCity(int* numOfChosenCities, sf::Event event, int *firstCity, int *secondCity, CityMap *map, sf::RenderWindow& window) {
	vector<string> allCities = City::getAllCities();

	if ((*numOfChosenCities) == 0) {
		if (event.type == sf::Event::MouseButtonPressed) {
			*firstCity = City::detectChosenCity(event.mouseButton.x, event.mouseButton.y);
			if (*firstCity < TOTAL_NUM_OF_CITIES) {
				(*numOfChosenCities)++;
				// restart previous current route:
				vector<vector<int>> level = CityMap::getCityMap();
				map->load("tileset.png", level);
				cout << "\nFrom: " << allCities[*firstCity] << " (" << *firstCity + 1 << ")" << endl;
				window.clear();
				window.draw(*map);
				window.display();
			}
		}
	}
	else if ((*numOfChosenCities) == 1) {
		while (true) {
			window.pollEvent(event);
			if (event.type == sf::Event::MouseButtonPressed) {
				*secondCity = City::detectChosenCity(event.mouseButton.x, event.mouseButton.y);
				// disable user to choose two same cities:
				if (*firstCity == *secondCity) {
					continue;
				}
				if (*secondCity < TOTAL_NUM_OF_CITIES) {
					cout << "To: " << allCities[*secondCity] << " (" << *secondCity + 1 << ")" << endl;
					(*numOfChosenCities)++;
				}
			}
			break;
		}
		
	}
}