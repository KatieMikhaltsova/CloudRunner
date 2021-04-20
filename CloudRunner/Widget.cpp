#include "Widget.h"

Widget::Widget(Texture& texture, int xSprite, int ySprite, int wSprite, int hSprite, State state)
{
    this->xSprite = xSprite; this->ySprite = ySprite; this->wSprite = wSprite; this->hSprite = hSprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(xSprite, ySprite,wSprite, hSprite));
    currentFrame = 0;
    stateWidget = state;
    animWidget = false;
}

Sprite Widget::getSprite()
{
    return this->sprite;
}

void Widget::setSpritePosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Widget::setSpriteScale(float scale)
{
    sprite.setScale(scale, scale);
}

void Widget::setSpriteTextureRect(int xSprite, int ySprite, int wSprite, int hSprite)
{
    sprite.setTextureRect(IntRect(xSprite, ySprite, wSprite, hSprite));
}

int Widget::getWSprite()
{
    return this->wSprite;
}

int Widget::getHSprite()
{
    return this->hSprite;
}

float Widget::getCurrentFrame()
{
    return currentFrame;
}

void Widget::setCurrentFrame(float currentFrame)
{
    this->currentFrame = currentFrame;
}

void Widget::setXSprite(int xSprite)
{
    this->xSprite=xSprite;
}

void Widget::setYSprite(int ySprite)
{
    this->ySprite = ySprite;
}

int Widget::getXSprite()
{
    return xSprite;
}

int Widget::getYSprite()
{
    return ySprite;
}

bool Widget::getAnim()
{
    return animWidget;
}

void Widget::setAnim(bool animWidget)
{
    this->animWidget = animWidget;
}


