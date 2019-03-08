#include "CityMap.h"
#include "City.h"

using namespace std;

const int INF = 9999;

void PickFromAndToCity(int* numOfChosenCities, sf::Event event, int *firstCity, int *secondCity) {
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

vector<int> dijkstra(int startnode, int endnode)
{
	int G[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES] = {{0, 58, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {58, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {65, 52, 0, 0, 0, 43, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 56, 0, 0, 48, 93, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 43, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 82, 0, 0, 0, 0, 77, 80, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 77, 0, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 67, 0, 0, 0, 0, 0, 0, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95, 0, 0, 0, 0, 114, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93, 0, 0, 55, 0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 0, 61, 0, 0, 0, 102, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70, 55, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55, 0, 0, 0, 0, 0, 69, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 44, 0, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 0, 40, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 62, 84},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 62, 0, 0},
													   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0}
	};
	int cost[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES];
	int i, j;

	//create the cost matrix
	for (i = 0; i < TOTAL_NUM_OF_CITIES; i++)
		for (j = 0; j < TOTAL_NUM_OF_CITIES; j++)
			if (G[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = G[i][j];

	int distance[TOTAL_NUM_OF_CITIES];
	int pred[TOTAL_NUM_OF_CITIES]; //pred[] stores the predecessor of each node
	int visited[TOTAL_NUM_OF_CITIES];
	
	//initialize pred[],distance[] and visited[]
	for (i = 0; i < TOTAL_NUM_OF_CITIES; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	int count = 1; //count gives the number of nodes seen so far
	int mindistance;
	int nextnode;

	while (count < TOTAL_NUM_OF_CITIES - 1)
	{
		mindistance = INF;

		//nextnode gives the node at minimum distance
		for (i = 0; i < TOTAL_NUM_OF_CITIES; i++)
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}

		//check if a better path exists through nextnode			
		visited[nextnode] = 1;
		for (i = 0; i < TOTAL_NUM_OF_CITIES; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	//print the path and distance from startnode to endnode
	vector<int> res;

	vector<string> allCities = City::GetAllCities();
	cout << "Shortest distance between " << allCities[startnode] << " and " << allCities[endnode] << " is " << distance[endnode] << " km." << endl;
	cout << "Shortest path: " << flush;
	res.push_back(endnode+1); //cout << endnode << flush;

	j = endnode;
	while (j != startnode) {
		j = pred[j];
		res.push_back(j+1); // cout << " <- " << j;
	}

	return res;
}

int main()
{
	CityMap map;
	vector<vector<int>> level = CityMap::GetCityMap();

	// forming a map from tiles in the picture "tileset.png":
	if (!map.load("tileset.png", level))
		return -1;

	sf::RenderWindow window(sf::VideoMode(CITY_SIZE*MAP_WIDTH, CITY_SIZE*MAP_HEIGHT), "Cities in Serbia");
	int numOfChosenCities = 0;
	int firstCity = 0, secondCity = 0;
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
				PickFromAndToCity(&numOfChosenCities, event, &firstCity, &secondCity);
			}

			// calling function for detect a shortest distance from one to another city:
			if (numOfChosenCities == 2) {
				for (int el : dijkstra(firstCity, secondCity)) {
					cout << el << " <- " << flush;
				}
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