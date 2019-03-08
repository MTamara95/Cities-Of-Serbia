#include "CityMap.h"

bool CityMap::load(const std::string& tileset, vector<vector<int>> tiles)
{
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);

	// populate the vertex array, with one quad per tile
	for (int i = 0; i < MAP_HEIGHT; i++){
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[4*(MAP_WIDTH*i+j)]; // 2D array -> 1D array

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

vector<vector<int>> CityMap::GetCityMap() {
	vector<vector<int>> level = { {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS,    00, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS,  ROAD,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS,  ROAD, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,    02, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS,    01, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS, GRASS,  ROAD, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS, GRASS, GRASS,  ROAD,  ROAD, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT, GRASS, GRASS, GRASS, GRASS,    03, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS, GRASS,  ROAD, GRASS,  ROAD, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS,  ROAD, GRASS, GRASS, GRASS,    05,  ROAD,  ROAD,    04,  ROAD,  ROAD,  ROAD,  ROAD,    06, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,    07, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS,     9,  ROAD,  ROAD,  ROAD,     8,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,    10, GRASS,   OUT,   OUT, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS,   OUT,   OUT, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS,   OUT, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    14, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT, GRASS, GRASS, GRASS, GRASS,    11, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,   12, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,    13,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,    15, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,    16, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    17,  ROAD,  ROAD,  ROAD,  ROAD,    18, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    19,  ROAD,  ROAD,  ROAD,  ROAD,    20, GRASS, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,    22, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,    21, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,    23, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS,    24,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,    25, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,  ROAD, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,    26, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS, GRASS, GRASS, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, GRASS,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT},
								  {  OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT,   OUT, OUT} };

	return level;
}

void CityMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}