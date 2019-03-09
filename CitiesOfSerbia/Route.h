#pragma once

#include <utility>

#include "City.h"

class Route
{
public:
	Route(int fromCity, int toCity, int weight, vector<pair<int,int>> fields);
	~Route();

	int getFromCity();
	int getToCity();
	int getRouteWeight();
	vector<pair<int, int>> getRouteFields();

	static vector<Route> getAllRoutes();
	
private:
	int _fromCity;
	int _toCity;
	int _routeWeight;
	vector<pair<int, int>> _routeFields;
};