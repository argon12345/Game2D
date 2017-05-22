#include "GameModel.h"

model::GameModel::GameModel()
{
}

model::GameModel::~GameModel()
{
}

void model::GameModel::run() {

}

void model::GameModel::update() {

}

model::Tile** model::GameModel::getTileToDraw(sf::Vector2f vec) {
	int x, y;
	x = int(vec.x / SECTOR_SIZE);
	y = int(vec.y / SECTOR_SIZE);
	return gameTile.getSector(x, y);
}
