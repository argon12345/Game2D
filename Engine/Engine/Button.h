#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "SFML\Graphics.hpp"
#endif // !SFML_GRAPHICS_HPP


namespace ctrl {
	class Button {
	public:
		size_t x, y, width, height;
		sf::Text title;
		Button(int, int, int, int, sf::String title, sf::Font *);
		bool checkPosition(sf::Vector2i);
	private:

	};
}


