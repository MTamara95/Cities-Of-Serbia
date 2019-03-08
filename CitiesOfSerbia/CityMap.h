#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "City.h"

using namespace std;

const int MAP_WIDTH = 29;
const int MAP_HEIGHT = 43;
const int OUT = 27;
const int GRASS = 28;
const int ROAD = 29;

class CityMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, vector<vector<int>> tiles);
	static vector<vector<int>> GetCityMap();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};