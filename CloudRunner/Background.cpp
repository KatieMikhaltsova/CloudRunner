#include "Background.h"
using namespace sf;

Background::Background(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite, float animSpeed, int quantityOfFrame) :Entity(texture, x, y, xSprite, ySprite, wSprite, hSprite, animSpeed, quantityOfFrame)
{
}

int Background::quantityCloud = 10;

void Background::animCloud(RenderWindow& window, float& time, Background& cloud)
{
    if (cloudVector.empty())
    {
        cloud.setSpriteScale(0.2);

        for (int i = 0; i < quantityCloud; i++)
        {
            cloud.setX(110*i);
            cloud.setY(100 + 50 * (i % 2));
            cloudVector.push_back(cloud);
        }
    }

    for (int i = 0; i < quantityCloud; i++)
    {
       cloudVector[i].setX(cloudVector[i].getX() - time * cloudVector[i].getAnimSpeed());
       cloudVector[i].setSpritePosition(cloudVector[i].getX(), cloudVector[i].getY());
       window.draw(cloudVector[i].getSprite());

       if (cloudVector[i].getX()<-70)
       {
           cloudVector[i].setX(window.getSize().x+ 70);
       }
    }
}

