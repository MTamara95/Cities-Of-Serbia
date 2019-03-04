#include "City.h"

City::City(int topLeftCornerX, int topLeftCornerY, string name) {
	_topLeftCornerX = topLeftCornerX;
	_topLeftCornerY = topLeftCornerY;
	_name = name;
}


City::~City()
{
}


int City::GetTopLeftCornerX() {
	return _topLeftCornerX;
}

int City::GetTopLeftCornerY() {
	return _topLeftCornerY;
}

string City::GetName() {
	return _name;
}

vector<City> City::GetAllCities() {
	vector<City> allCities = { City(100, 40, "Subotica"), City(40, 100, "Sombor"), City(200, 80, "Kikinda") , City(100, 160, "Vrbas"), City(200, 200, "Zrenjanin"), City(140, 200, "Novi Sad"),
					   City(300, 200, "Vrsac"), City(40, 220, "Sid"), City(200, 260, "Beograd"), City(120, 260, "Sabac"), City(340, 260, "Pozarevac"), City(120, 380, "Valjevo"),
					   City(460, 380, "Negotin"), City(340, 420, "Jagodina"), City(300, 360, "Kragujevac"), City(460, 420, "Zajecar"), City(200, 460, "Cacak"), City(240, 500, "Kraljevo"),
					   City(340, 500, "Krusevac"), City(420, 560, "Nis"), City(520, 560, "Pirot"), City(420, 600, "Leskovac"), City(240, 600, "Novi Pazar"), City(280, 640, "Kosovska Mitrovica"),
					   City(280, 680, "Pristina"), City(420, 680, "Vranje"), City(280, 780, "Prizren") };

	return allCities;
}

int City::DetectChosenCity(int x, int y) {
	int i = 0;
	vector<City> allCities = GetAllCities();

	for (i = 0; i < TOTAL_NUM_OF_CITIES; i++) {
		if (x >= allCities[i].GetTopLeftCornerX() && x <= allCities[i].GetTopLeftCornerX() + CITY_WIDTH && y >= allCities[i].GetTopLeftCornerY() && y <= allCities[i].GetTopLeftCornerY() + CITY_HEIGHT) {
			break;
		}
	}

	return i;
}