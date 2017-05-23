#pragma once
#include "Tile.h"
#include <math.h>

namespace model {
	class GameTile :
		public Tile
	{
	public:
		GameTile();
		~GameTile();
		bool createSector(size_t, size_t);
		Tile** getSector(size_t, size_t);
	private:
		void generateFractal(float, float, float, float, unsigned int);
		double W(double x);
		double Wc(double x);
		double xrand();

		float fractalMap[NUMBER_OF_SECTORS][NUMBER_OF_SECTORS];
		Tile **** Map;
		bool boolMap[NUMBER_OF_SECTORS][NUMBER_OF_SECTORS];
	};
}