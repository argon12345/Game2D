#include "Tile.h"

using namespace model;
model::Tile::Tile()
{
	type = &TextureContainer::grass1;
}
Tile::Tile(int x, int y) {
	if (rand() % 2 == 1) {
		type = &TextureContainer::grass1;
	}
	else {
		type = &TextureContainer::grass2;
	}
	
	position.x = x;
	position.y = y;
}

Tile::~Tile()
{
}


