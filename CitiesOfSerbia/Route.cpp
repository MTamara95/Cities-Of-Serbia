#include "Route.h"

Route::Route(int fromCity, int toCity, int weight, vector<pair<int, int>> fields)
{
	_fromCity = fromCity;
	_toCity = toCity;
	_routeWeight = weight;
	_routeFields = fields;
}

Route::~Route()
{
}

int Route::getFromCity() {
	return _fromCity;
}

int Route::getToCity() {
	return _toCity;
}

int Route::getRouteWeight() {
	return _routeWeight;
}

vector<pair<int, int>> Route::getRouteFields() {
	return _routeFields;
}

vector<Route> Route::getAllRoutes() {
		vector<Route> allRoutes = { Route(0, 1, 58, {make_pair(4,3), make_pair(3,4)}),
									Route(0, 3, 65, {make_pair(3,5), make_pair(4,5), make_pair(5,5), make_pair(6,5), make_pair(7,5)}),
									Route(1, 3, 52, {make_pair(6,3), make_pair(7,4)}),
									Route(2, 4, 56, {make_pair(5,10), make_pair(6,10), make_pair(7,10), make_pair(8,10), make_pair(9,10)}),
									Route(3, 5, 43, {make_pair(9,6)}),
									Route(3, 7, 120, {make_pair(10,3), make_pair(9,4)}),
									Route(4, 5, 48, {make_pair(10,8), make_pair(10,9)}),
									Route(4, 6, 93, {make_pair(10,11), make_pair(10,12), make_pair(10,13), make_pair(10,14)}),
									Route(4, 8, 82, {make_pair(11,10), make_pair(12,10)}),
									Route(8, 9, 77, {make_pair(13,7), make_pair(13,8), make_pair(13,9)}),
									Route(8, 10, 80, {make_pair(13,11), make_pair(13,12), make_pair(13,13), make_pair(13,14), make_pair(13,15), make_pair(13,16)}),
									Route(8, 14, 141, {make_pair(14,11), make_pair(15,12), make_pair(16,13), make_pair(17,14)}),
									Route(9, 11, 67, {make_pair(14,6), make_pair(15,6), make_pair(16,6), make_pair(17,6), make_pair(18,6)}),
									Route(10, 13, 95, {make_pair(14,17), make_pair(15,17), make_pair(16,17), make_pair(17,17), make_pair(18,17), make_pair(19,17), make_pair(20,17)}),
									Route(11, 16, 93, {make_pair(20,7), make_pair(21,8), make_pair(22,9)}),
									Route(12, 15, 56, {make_pair(20,23)}),
									Route(13, 15, 114, {make_pair(21,18), make_pair(21,19), make_pair(21,20), make_pair(21,21), make_pair(21,22)}),
									Route(13, 18, 64, {make_pair(22,17), make_pair(23,17), make_pair(24,17)}),
									Route(14, 16, 55, {make_pair(22,11), make_pair(21,12), make_pair(20,13), make_pair(19,14)}),
									Route(16, 17, 39, {make_pair(24,11)}),
									Route(17, 18, 61, {make_pair(25,13), make_pair(25,14), make_pair(25,15), make_pair(25,16)}),
									Route(17, 22, 102, {make_pair(26,12), make_pair(27,12), make_pair(28,12), make_pair(29,12)}),
									Route(19, 20, 70, {make_pair(28,22), make_pair(28,23), make_pair(28,24), make_pair(28,25)}),
									Route(19, 21, 55, {make_pair(29,21)}),
									Route(21, 25, 69, {make_pair(31,21), make_pair(32,21), make_pair(33,21)}),
									Route(22, 23, 44, {make_pair(31,13)}),
									Route(23, 24, 40, {make_pair(33,14)}),
									Route(24, 25, 62, {make_pair(34,15), make_pair(34,16), make_pair(34,17), make_pair(34,18), make_pair(34,19), make_pair(34,20)}),
									Route(24, 26, 84, {make_pair(35,14), make_pair(36,14), make_pair(37,14), make_pair(38,14)}),
		};

	return allRoutes;
}