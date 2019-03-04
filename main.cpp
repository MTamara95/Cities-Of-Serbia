#include "CityMap.h"
#include "City.h"

using namespace std;

const int MAP_WIDTH = 29;
const int MAP_HEIGHT = 43;

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

void PickFromAndToCity(int* numOfChosenCities, sf::Event event) {
	int firstCity, secondCity;
	vector<City> allCities = City::GetAllCities();

	if ((*numOfChosenCities) == 0) {
		if (event.type == sf::Event::MouseButtonPressed) {
			firstCity = City::DetectChosenCity(event.mouseButton.x, event.mouseButton.y);
			cout << "From: " << allCities[firstCity].GetName() << " (" << firstCity+1 << ")" << endl;
			(*numOfChosenCities)++;
		}
	}
	else if ((*numOfChosenCities) == 1) {
		if (event.type == sf::Event::MouseButtonPressed) {
			secondCity = City::DetectChosenCity(event.mouseButton.x, event.mouseButton.y);
			cout << "To: " << allCities[secondCity].GetName() << " (" << secondCity+1 << ")" << endl;
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