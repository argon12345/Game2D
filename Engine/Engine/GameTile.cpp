#include "GameTile.h"

model::GameTile::GameTile() {
	Map = new Tile***[NUMBER_OF_SECTORS];
	for (size_t i = 0; i < NUMBER_OF_SECTORS; i++)
	{	
		Map[i] = new Tile**[NUMBER_OF_SECTORS];

	}
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

void model::GameTile::generateFractal(float a, float b, float c, float d, unsigned int size)
{
	fractalMap[0][0] = a;
	fractalMap[size - 1][0] = b;
	fractalMap[0][size - 1] = c;
	fractalMap[size - 1][size - 1] = d;
	int var = --size;
	size /= 2;
	for (; size > 1;) {
		for (int i = size; i < var; i += size * 2) {
			for (int j = size; j < var; j += size * 2) {
				int loga = std::log((double)size);
				if (loga % 2 == 0) {
					double cc = xrand();
					fractalMap[i][j] = (1 - 2 * W(size)) * cc + W(size) * a + W(size) * b;
				}
				else {
					double cc = xrand();
					fractalMap[i][j] = (1 - 4 * Wc(size)) * cc + Wc(size) * a + Wc(size) * b + Wc(size) * c + Wc(size) * d;
				}
			}
		}
		size /= 2;
	}
}

inline double model::GameTile::W(double x) { // Funkcja W(x)
	int y = x;
	return 1 / pow(2, pow(1.0045, x));
}

inline double model::GameTile::Wc(double x) { // Funkcja Wc(x)
	int y = x;
	return 1 / pow(4, pow(1.0045, y));
}

inline double model::GameTile::xrand() {
	return rand()*1.0 / RAND_MAX;
}


