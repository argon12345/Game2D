#include "GameTile.h"

model::GameTile::GameTile() {
	for (auto & var : boolMap) {
		for (auto & var2 : var) {
			var2 = false;
		}
	}
	createSector(START_SECTOR, START_SECTOR);
}

model::GameTile::~GameTile()
{
}

bool model::GameTile::createSector(size_t x, size_t y)
{
	if (boolMap[x][y] == false) {
		boolMap[x][y] = true;
		Map[x][y] = new Tile*[SECTOR_SIZE];
		for (size_t i = 0; i < SECTOR_SIZE; i++) {
			Map[x][y][i] = new Tile[SECTOR_SIZE];
		}
		for (size_t i = 0; i < SECTOR_SIZE; i++) {
			for (size_t j = 0; j < SECTOR_SIZE; j++) {
				Map[x][y][i][j] = Tile(x*SECTOR_SIZE + i, y*SECTOR_SIZE + j);
			}
		}

		return true;
	}
	return false;
}

model::Tile ** model::GameTile::getSector(size_t x, size_t y)
{
	if (boolMap[x][y] == false) {
		createSector(x, y);
		return Map[x][y];
	}
	else {
		return Map[x][y];
	}
}


