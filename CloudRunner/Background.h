#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>

using namespace sf;

class Background:public Entity
{
public:
	Background(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite, float animSpeed, int quantityOfFrame);

	static int quantityCloud;

	void animCloud(RenderWindow& window, float& time, Background& cloud);

private:
	std::vector <Background> cloudVector;
};

