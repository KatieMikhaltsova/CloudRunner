#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"


class Bullet:public Entity
{
public:
	Bullet(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite,float animSpeed, int quantityOfFrame);

	void shoot(float& time);

	int bulletScore;

private:

};

