#include "Entity.h"
#include <iostream>

int Entity::score = 0;

Entity::Entity(Texture& texture, float x, float y,int xSprite, int ySprite,int wSprite, int hSprite, float animSpeed, int quantityOfFrame)
{
    this->x = x; this->y = y; 
    this->wSprite = wSprite; this->hSprite = hSprite;
    this->xSprite = xSprite; this->ySprite = ySprite;
    this->animSpeed = animSpeed;
    this->quantityOfFrame = quantityOfFrame;
    dx = 0; dy = 0;
    life = true; onGround = true;  currentFrame = 0;
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(xSprite,ySprite,wSprite,hSprite));
    health = 3;
    
}

FloatRect Entity::getRect()
{
    return FloatRect(x, y, wSprite, hSprite);
}

bool Entity::getLife()
{
    return life;
}

void Entity::setLife(bool life)
{
    this->life = life;
}

void Entity::setSpriteTextureRect(int xSprite, int ySprite, int wSprite, int hSprite)
{
    sprite.setTextureRect(IntRect(xSprite, ySprite, wSprite, hSprite));
    this->xSprite = xSprite;
    this->ySprite = ySprite;
    this->wSprite = wSprite;
    this->hSprite = hSprite;
}

void Entity::setSpritePosition(float x, float y)
{
    sprite.setPosition(x, y);
    this->x = x;
    this->y = y;
}

Sprite Entity::getSprite()
{
    return sprite;
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

void Entity::setX(float x)
{
    this->x = x;
}

void Entity::setY(float y)
{
    this->y = y;
}

void Entity::setXSprite(int xSprite)
{
    this->xSprite = xSprite;
}

void Entity::setYSprite(int ySprite)
{
    this->ySprite = ySprite;
}

int Entity::getXSprite()
{
    return xSprite;
}

int Entity::getYSprite()
{
    return ySprite;
}

int Entity::getWSprite()
{
    return wSprite;
}

int Entity::getHSprite()
{
    return hSprite;
}

float Entity::getDx()
{
    return dx;
}

float Entity::getDy()
{
    return dy;
}

void Entity::setDx(float dx)
{
    this->dx = dx;
}

void Entity::setDy(float dy)
{
    this->dy = dy;
}

float Entity::getAnimSpeed()
{
    return animSpeed;
}

void Entity::setAnimSpeed(float animSpeed)
{
    this->animSpeed = animSpeed;
}

bool Entity::getOnGround()
{
    return onGround;
}

void Entity::setOnGround(bool onGround)
{
    this->onGround = onGround;
}

float Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::setCurrentFrame(float currentFrame)
{
    this->currentFrame = currentFrame;
}

int Entity::changeHealth()
{
    return this->health -= 1;
}

int Entity::getScore()
{
    return score;
}

void Entity::setScore(int score)
{
    this->score = score;
}

void Entity::setSpriteScale(float scale)
{
    sprite.setScale(scale,scale);
}

void Entity::setSpriteRotate(float angle)
{
    sprite.setRotation(angle);
}

void Entity::setCollision(float xCollision, float yCollision, int wCollision, int hCollision)
{
    this->xCollision = xCollision;
    this->yCollision = yCollision;
    this->wCollision = wCollision;
    this->hCollision = hCollision;
}

void Entity::setScoreCollision(float xScoreCollision, float yScoreCollision, int wScoreCollision, int hScoreCollision)
{
    this->xScoreCollision = xScoreCollision;
    this->yScoreCollision = yScoreCollision;
    this->wScoreCollision = wScoreCollision;
    this->hScoreCollision = hScoreCollision;
}

FloatRect Entity::getCollision()
{
    return FloatRect(xCollision, yCollision, wCollision,hCollision);
}

FloatRect Entity::getScoreCollision()
{
    return FloatRect(xScoreCollision, yScoreCollision, wScoreCollision, hScoreCollision);
}

int Entity::getQuantityOfFrame()
{
    return quantityOfFrame;
}

float Entity::getHealth()
{
    return health;
}



