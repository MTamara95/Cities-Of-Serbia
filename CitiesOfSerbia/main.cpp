#include "CityMap.h"
#include "City.h"
#include "Route.h"

const int INF = 9999;
const string TILESET_FILE_NAME = "tileset.png";

void createMatrixGraphRepresentation(int G[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES]);
void createCostMatrix(int cost[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES], int G[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES]);
void determinePredDistanceAndVisited(int pred[TOTAL_NUM_OF_CITIES], int distance[TOTAL_NUM_OF_CITIES], int visited[TOTAL_NUM_OF_CITIES], int cost[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES], int startnode);
vector<int> determineShortestDistance(int pred[TOTAL_NUM_OF_CITIES], int distance[TOTAL_NUM_OF_CITIES], int startnode, int endnode);
vector<int> dijkstra(int startnode, int endnode);
 
int main() {
	CityMap map;
	vector<vector<int>> level = CityMap::getCityMap();

	// forming a map from tiles in the picture "tileset.png":
	map.load(TILESET_FILE_NAME, level);

	sf::RenderWindow window(sf::VideoMode(CITY_SIZE*MAP_WIDTH, CITY_SIZE*MAP_HEIGHT), "Cities in Serbia");
	int numOfChosenCities = 0;
	int firstCity = 0, secondCity = 0;
	cout << "Choose two cities:" << endl;
	vector<string> allCities = City::getAllCities();
	for (int i = 0; i < TOTAL_NUM_OF_CITIES; i++) {
		cout << i + 1 << ". " << allCities[i] << endl;
	}

	// displaying window:
	while (window.isOpen()) {
		// handling an events:
		sf::Event event;
		while (window.pollEvent(event)) {
			// input - user chooses two cities:
			if (numOfChosenCities < 2) {
				City::pickFromAndToCity(&numOfChosenCities, event, &firstCity, &secondCity, &map, window);
			}

			// calling function for detect a shortest distance from one to another city:
			if (numOfChosenCities == 2) {
				vector<int> resultSetOfRoutes = dijkstra(firstCity, secondCity);
				vector<Route> allRoutes = Route::getAllRoutes();
				for (int i = 0; i < resultSetOfRoutes.size()-1; i++) {
					vector<pair<int, int>> currentPartOfRoute;
					for (int j = 0; j < allRoutes.size(); j++) {
						if ((resultSetOfRoutes[i] == allRoutes[j].getFromCity() && resultSetOfRoutes[i + 1] == allRoutes[j].getToCity()) ||
							(resultSetOfRoutes[i] == allRoutes[j].getToCity() && resultSetOfRoutes[i + 1] == allRoutes[j].getFromCity())) {
							currentPartOfRoute = allRoutes[j].getRouteFields();
							break;
						}
					}
					for (int k = 0; k < currentPartOfRoute.size(); k++) {
						level[currentPartOfRoute[k].first][currentPartOfRoute[k].second] = CURRENT_ROUTE;
					}
				}
				map.load(TILESET_FILE_NAME, level);
				numOfChosenCities = 0;
				level = CityMap::getCityMap();
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

void createMatrixGraphRepresentation(int G[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES]) {
	for (int i = 0; i < TOTAL_NUM_OF_CITIES; i++) {
		for (int j = 0; j < TOTAL_NUM_OF_CITIES; j++) {
			G[i][j] = 0;
		}
	}
	vector<Route> allRoutes = Route::getAllRoutes();
	for (Route route : allRoutes) {
		G[route.getFromCity()][route.getToCity()] = route.getRouteWeight();
		G[route.getToCity()][route.getFromCity()] = route.getRouteWeight(); // non oriented graph - values of routes weight are symmetric in matrix
	}
}

void createCostMatrix(int cost[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES], int G[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES]) {
	for (int i = 0; i < TOTAL_NUM_OF_CITIES; i++)
		for (int j = 0; j < TOTAL_NUM_OF_CITIES; j++)
			if (G[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = G[i][j];
}

void determinePredDistanceAndVisited(int pred[TOTAL_NUM_OF_CITIES], int distance[TOTAL_NUM_OF_CITIES], int visited[TOTAL_NUM_OF_CITIES], int cost[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES], int startnode) {
	// initialize pred[], distance[] and visited[]
	for (int i = 0; i < TOTAL_NUM_OF_CITIES; i++) {
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	int count = 1; // count gives the number of nodes seen so far
	int mindistance;
	int nextnode;
	while (count < TOTAL_NUM_OF_CITIES - 1) {
		mindistance = INF;
		// nextnode gives the node at minimum distance
		for (int i = 0; i < TOTAL_NUM_OF_CITIES; i++) {
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		}
		// check if a better path exists through nextnode			
		visited[nextnode] = 1;
		for (int i = 0; i < TOTAL_NUM_OF_CITIES; i++) {
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		}
		count++;
	}
}

vector<int> determineShortestDistance(int pred[TOTAL_NUM_OF_CITIES], int distance[TOTAL_NUM_OF_CITIES], int startnode, int endnode) {
	vector<int> res;
	vector<string> allCities = City::getAllCities();
	cout << "Shortest distance between " << allCities[startnode] << " and " << allCities[endnode] << " is " << distance[endnode] << " km." << endl;
	res.push_back(endnode);

	int j = endnode;
	while (j != startnode) {
		j = pred[j];
		res.push_back(j);
	}

	return res;
}

vector<int> dijkstra(int startnode, int endnode) {
	int G[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES];
	createMatrixGraphRepresentation(G);

	int cost[TOTAL_NUM_OF_CITIES][TOTAL_NUM_OF_CITIES];
	createCostMatrix(cost, G);

	int pred[TOTAL_NUM_OF_CITIES]; // pred[] stores the predecessor of each node
	int distance[TOTAL_NUM_OF_CITIES];
	int visited[TOTAL_NUM_OF_CITIES];
	determinePredDistanceAndVisited(pred, distance, visited, cost, startnode);

	return determineShortestDistance(pred, distance, startnode, endnode);
}
