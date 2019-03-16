#include "CityMap.h"

bool CityMap::load(const std::string& tileset, vector<vector<int>> tiles) {
	_tileset.loadFromFile(tileset);

	// resize the vertex array to fit the level size
	_vertices.setPrimitiveType(sf::Quads);
	_vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);

	// populate the vertex array, with one quad per tile
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			// get a pointer to the current tile's quad (2D array -> 1D array)
			sf::Vertex* quad = &_vertices[4*(MAP_WIDTH*i+j)];

			// define its 4 corners
			quad[0].position = sf::Vector2f(j * CITY_SIZE, (i+1) * CITY_SIZE);
			quad[1].position = sf::Vector2f((j + 1) * CITY_SIZE, (i+1) * CITY_SIZE);
			quad[2].position = sf::Vector2f((j + 1) * CITY_SIZE, i * CITY_SIZE);
			quad[3].position = sf::Vector2f(j * CITY_SIZE, i * CITY_SIZE);

			// define its 4 texture coordinates
			int tileNumber = tiles[i][j];
			quad[0].texCoords = sf::Vector2f(tileNumber * CITY_SIZE, CITY_SIZE);
			quad[1].texCoords = sf::Vector2f((tileNumber + 1) * CITY_SIZE, CITY_SIZE);
			quad[2].texCoords = sf::Vector2f((tileNumber + 1) * CITY_SIZE, 0);
			quad[3].texCoords = sf::Vector2f(tileNumber * CITY_SIZE, 0);
		}
	}

	return true;
}

vector<vector<int>> CityMap::getCityMap() {
	vector<vector<int>> level = { {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS,    00, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS,  ROUTE,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS,  ROUTE, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,    02, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS,    01, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS, GRASS,  ROUTE, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS, GRASS, GRASS,  ROUTE,  ROUTE, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS, GRASS, GRASS, GRASS,    03, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS, GRASS,  ROUTE, GRASS,  ROUTE, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS,  ROUTE, GRASS, GRASS, GRASS,    05,  ROUTE,  ROUTE,    04,  ROUTE,  ROUTE,  ROUTE,  ROUTE,    06, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,    07, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS,     9,  ROUTE,  ROUTE,  ROUTE,     8,  ROUTE,  ROUTE,  ROUTE,  ROUTE,  ROUTE,  ROUTE,    10, GRASS,   OUT,   OUT, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS,   OUT,   OUT, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS,   OUT, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    14, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT, GRASS, GRASS, GRASS, GRASS,    11, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,   12, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,    13,  ROUTE,  ROUTE,  ROUTE,  ROUTE,  ROUTE,    15, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,    16, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    17,  ROUTE,  ROUTE,  ROUTE,  ROUTE,    18, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    19,  ROUTE,  ROUTE,  ROUTE,  ROUTE,    20, GRASS, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,    22, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    21, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,    23, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,    24,  ROUTE,  ROUTE,  ROUTE,  ROUTE,  ROUTE,  ROUTE,    25, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROUTE, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,    26, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT} };

	return level;
}

void CityMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// apply the texture
	states.texture = &_tileset;

	// draw the vertex array
	target.draw(_vertices, states);
}