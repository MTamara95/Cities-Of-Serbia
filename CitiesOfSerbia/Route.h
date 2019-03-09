#pragma once

#include "City.h"
#include <utility>

class Route
{
public:
	Route(int fromCity, int toCity, int weight, vector<pair<int,int>> fields);
	~Route();

	int GetFromCity();
	int GetToCity();
	int GetRouteWeight();
	vector<pair<int, int>> GetRouteFields();

	static vector<Route> GetAllRoutes();
	
private:
	int _fromCity;
	int _toCity;
	int _routeWeight;
	vector<pair<int, int>> _routeFields;
};