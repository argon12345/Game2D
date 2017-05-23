#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "SFML\Graphics.hpp"
#endif // !GRAPHICS_H

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR

#define SECTOR_SIZE 256
#define NUMBER_OF_SECTORS 256
#define START_SECTOR NUMBER_OF_SECTORS/2
#define TEXTURE_SIZE_X 64
#define TEXTURE_SIZE_Y 64
#define SCALE_MAX 1.0f
#define SCALE_MIN 0.125f



namespace model {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	private:

	};

}