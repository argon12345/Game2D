#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "SFML\Graphics.hpp"
#endif // !GRAPHICS_H

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR

#define SECTOR_SIZE 128
#define NUMBER_OF_SECTORS 64
#define START_SECTOR NUMBER_OF_SECTORS/2
#define TEXTURE_SIZE_X 128
#define TEXTURE_SIZE_Y 128



namespace model {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	private:

	};

}