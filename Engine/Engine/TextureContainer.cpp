#include "TextureContainer.h"


using namespace model;
TextureContainer::TextureContainer() {
	grass1.loadFromFile("grass1.bmp");
	grass2.loadFromFile("grass2.bmp");
}


TextureContainer::~TextureContainer() {

}

sf::Texture TextureContainer::grass1 = sf::Texture();
sf::Texture TextureContainer::grass2 = sf::Texture();