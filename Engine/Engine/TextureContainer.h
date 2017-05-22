#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "SFML\Graphics.hpp"
#endif // !GRAPHICS_HPP


namespace model {
	class TextureContainer
	{
	public:
		static sf::Texture grass1;
		static sf::Texture grass2;
		TextureContainer();
		~TextureContainer();
	};

}