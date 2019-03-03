#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CityMap.h"

using namespace std;

const int MAP_WIDTH = 29;
const int MAP_HEIGHT = 43;

enum mapNumberToCityName {
	Subotica = 1,
	Sombor = 2,
	Kikinda = 3,
	Vrbas = 4,
	Zrenjanin = 5,
	NoviSad = 6,
	Vrsac = 7,
	Sid = 8,
	Beograd = 9,
	Sabac = 10,
	Pozarevac = 11,
	Valjevo = 12,
	Negotin = 13,
	Jagodina = 14,
	Kragujevac = 15,
	Zajecar = 16,
	Cacak = 17,
	Kraljevo = 18,
	Krusevac = 19,
	Nis = 20,
	Pirot = 21,
	Leskovac = 22,
	NoviPazar = 23,
	KosovskaMitrovica = 24,
	Pristina = 25,
	Vranje = 26,
	Prizren = 27
};

string GetCityName(mapNumberToCityName city) {
	switch (city)
	{
	case Subotica:
		return "Subotica";
	case Sombor:
		return "Sombor";
	case Kikinda:
		return "Kikinda";
	case Vrbas:
		return "Vrbas";
	case Zrenjanin:
		return "Zrenjanin";
	case NoviSad:
		return "Novi Sad";
	case Vrsac:
		return "Vrsac";
	case Sid:
		return "Sid";
	case Beograd:
		return "Beograd";
	case Sabac:
		return "Sabac";
	case Pozarevac:
		return "Pozarevac";
	case Valjevo:
		return "Valjevo";
	case Negotin:
		return "Negotin";
	case Jagodina:
		return "Jagodina";
	case Kragujevac:
		return "Kragujevac";
	case Zajecar:
		return "Zajecar";
	case Cacak:
		return "Cacak";
	case Kraljevo:
		return "Kraljevo";
	case Krusevac:
		return "Krusevac";
	case Nis:
		return "Nis";;
	case Pirot:
		return "Pirot";
	case Leskovac:
		return "Leskovac";
	case NoviPazar:
		return "Novi Pazar";
	case KosovskaMitrovica:
		return "Kosovska Mitrovica";
	case Pristina:
		return "Pristina";
	case Vranje:
		return "Vranje";
	case Prizren:
		return "Prizren";
	default:
		break;
	}
}

void FormMapFromTiles(int *level) {

	// reading the whole content of the file "level.txt":
	stringstream str;
	ifstream stream("level.txt");
	if (stream.is_open())
	{
		while (stream.peek() != EOF)
		{
			str << (char)stream.get();
		}
		stream.close();
	}

	// forming a string from ridden context, and removing all white spaces:
	string levelString = str.str();
	levelString.erase(remove_if(levelString.begin(), levelString.end(), isspace), levelString.end());

	// forming an int array from a string:
	std::string delimiter = ",";
	size_t pos = 0;
	int i = 0;
	std::string token;
	while ((pos = levelString.find(delimiter)) != std::string::npos) {
		token = levelString.substr(0, pos);
		level[i++] = stoi(token);
		levelString.erase(0, pos + delimiter.length());
	}

	return;
}

mapNumberToCityName DetectChosenCity(sf::Event event) {
	if (event.mouseButton.x >= 100.f && event.mouseButton.x <= 120.f && event.mouseButton.y >= 40.f && event.mouseButton.y <= 60.f) {
		return Subotica;
	}
	if (event.mouseButton.x >= 40.f && event.mouseButton.x <= 60.f && event.mouseButton.y >= 100.f && event.mouseButton.y <= 120.f) {
		return Sombor;
	}
	if (event.mouseButton.x >= 200.f && event.mouseButton.x <= 220.f && event.mouseButton.y >= 80.f && event.mouseButton.y <= 100.f) {
		return Kikinda;
	}
	if (event.mouseButton.x >= 100.f && event.mouseButton.x <= 120.f && event.mouseButton.y >= 160.f && event.mouseButton.y <= 180.f) {
		return Vrbas;
	}
	if (event.mouseButton.x >= 200.f && event.mouseButton.x <= 220.f && event.mouseButton.y >= 200.f && event.mouseButton.y <= 220.f) {
		return Zrenjanin;
	}
	if (event.mouseButton.x >= 140.f && event.mouseButton.x <= 160.f && event.mouseButton.y >= 200.f && event.mouseButton.y <= 220.f) {
		return NoviSad;
	}
	if (event.mouseButton.x >= 300.f && event.mouseButton.x <= 320.f && event.mouseButton.y >= 200.f && event.mouseButton.y <= 220.f) {
		return Vrsac;
	}
	if (event.mouseButton.x >= 40.f && event.mouseButton.x <= 60.f && event.mouseButton.y >= 220.f && event.mouseButton.y <= 240.f) {
		return Sid;
	}
	if (event.mouseButton.x >= 200.f && event.mouseButton.x <= 220.f && event.mouseButton.y >= 260.f && event.mouseButton.y <= 280.f) {
		return Beograd;
	}
	if (event.mouseButton.x >= 120.f && event.mouseButton.x <= 140.f && event.mouseButton.y >= 260.f && event.mouseButton.y <= 280.f) {
		return Sabac;
	}
	if (event.mouseButton.x >= 340.f && event.mouseButton.x <= 360.f && event.mouseButton.y >= 260.f && event.mouseButton.y <= 280.f) {
		return Pozarevac;
	}
	if (event.mouseButton.x >= 120.f && event.mouseButton.x <= 140.f && event.mouseButton.y >= 380.f && event.mouseButton.y <= 400.f) {
		return Valjevo;
	}
	if (event.mouseButton.x >= 460.f && event.mouseButton.x <= 480.f && event.mouseButton.y >= 380.f && event.mouseButton.y <= 400.f) {
		return Negotin;
	}
	if (event.mouseButton.x >= 340.f && event.mouseButton.x <= 360.f && event.mouseButton.y >= 420.f && event.mouseButton.y <= 440.f) {
		return Jagodina;
	}
	if (event.mouseButton.x >= 300.f && event.mouseButton.x <= 320.f && event.mouseButton.y >= 360.f && event.mouseButton.y <= 380.f) {
		return Kragujevac;
	}
	if (event.mouseButton.x >= 460.f && event.mouseButton.x <= 480.f && event.mouseButton.y >= 420.f && event.mouseButton.y <= 440.f) {
		return Zajecar;
	}
	if (event.mouseButton.x >= 200.f && event.mouseButton.x <= 220.f && event.mouseButton.y >= 460.f && event.mouseButton.y <= 480.f) {
		return Cacak;
	}
	if (event.mouseButton.x >= 240.f && event.mouseButton.x <= 260.f && event.mouseButton.y >= 500.f && event.mouseButton.y <= 520.f) {
		return Kraljevo;
	}
	if (event.mouseButton.x >= 340.f && event.mouseButton.x <= 360.f && event.mouseButton.y >= 500.f && event.mouseButton.y <= 520.f) {
		return Krusevac;
	}
	if (event.mouseButton.x >= 420.f && event.mouseButton.x <= 440.f && event.mouseButton.y >= 560.f && event.mouseButton.y <= 580.f) {
		return Nis;
	}
	if (event.mouseButton.x >= 520.f && event.mouseButton.x <= 540.f && event.mouseButton.y >= 560.f && event.mouseButton.y <= 580.f) {
		return Pirot;
	}
	if (event.mouseButton.x >= 420.f && event.mouseButton.x <= 440.f && event.mouseButton.y >= 600.f && event.mouseButton.y <= 620.f) {
		return Leskovac;
	}
	if (event.mouseButton.x >= 240.f && event.mouseButton.x <= 260.f && event.mouseButton.y >= 600.f && event.mouseButton.y <= 620.f) {
		return NoviPazar;
	}
	if (event.mouseButton.x >= 280.f && event.mouseButton.x <= 300.f && event.mouseButton.y >= 640.f && event.mouseButton.y <= 660.f) {
		return KosovskaMitrovica;
	}
	if (event.mouseButton.x >= 280.f && event.mouseButton.x <= 300.f && event.mouseButton.y >= 680.f && event.mouseButton.y <= 700.f) {
		return Pristina;
	}
	if (event.mouseButton.x >= 420.f && event.mouseButton.x <= 440.f && event.mouseButton.y >= 680.f && event.mouseButton.y <= 700.f) {
		return Vranje;
	}
	if (event.mouseButton.x >= 280.f && event.mouseButton.x <= 300.f && event.mouseButton.y >= 780.f && event.mouseButton.y <= 800.f) {
		return Prizren;
	}
}

void PickFromAndToCity(int* numOfChosenCities, sf::Event event) {
	mapNumberToCityName firstCity, secondCity;

	if ((*numOfChosenCities) == 0) {
		if (event.type == sf::Event::MouseButtonPressed) {
			firstCity = DetectChosenCity(event);
			cout << "From: " << GetCityName(firstCity) << " (" << firstCity << ")" << endl;
			(*numOfChosenCities)++;
		}
	}
	else if ((*numOfChosenCities) == 1) {
		if (event.type == sf::Event::MouseButtonPressed) {
			secondCity = DetectChosenCity(event);
			cout << "To: " << GetCityName(secondCity) << " (" << secondCity << ")" << endl;
			(*numOfChosenCities)++;
		}
	}
}

int main()
{
	int level[MAP_WIDTH*MAP_HEIGHT];
	CityMap map;
	// forming a map from tiles in the picture "tileset.png":
	FormMapFromTiles(level);
	if (!map.load("tileset.png", sf::Vector2u(20, 20), level, MAP_WIDTH, MAP_HEIGHT))
		return -1;

	sf::RenderWindow window(sf::VideoMode(580, 860), "Cities in Serbia");
	int numOfChosenCities = 0;
	cout << "Choose two cities:" << endl;
	// displaying window:
	while (window.isOpen())
	{
		// handling an events:
		sf::Event event;
		while (window.pollEvent(event))
		{
			// input - user chooses two cities:
			if (numOfChosenCities < 2) {
				PickFromAndToCity(&numOfChosenCities, event);
			}

			// calling function for detect a shortest distance from one to another city:
			if (numOfChosenCities == 2) {
				// f...
				numOfChosenCities++;
			}

			// closing the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(map);
		window.display();
	}

	return 0;
}