#pragma once
#include "Tile.h"

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
		Tile ** Map[NUMBER_OF_SECTORS][NUMBER_OF_SECTORS];
		bool boolMap[NUMBER_OF_SECTORS][NUMBER_OF_SECTORS];
	};
}