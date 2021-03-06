#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "City.h"

using namespace std;

const int MAP_WIDTH = 29;
const int MAP_HEIGHT = 43;
const int OUT = 27;
const int GRASS = 28;
const int ROUTE = 29;
const int CURRENT_ROUTE = 30;

class CityMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, vector<vector<int>> tiles);
	static vector<vector<int>> getCityMap();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray _vertices;
	sf::Texture _tileset;
};