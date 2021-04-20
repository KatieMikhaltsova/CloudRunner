#pragma once
#include <SFML/Graphics.hpp>
#include<list>
using namespace sf;

class Entity
{
public:

    Entity(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite, float animSpeed,int quantityOfFrame);

    FloatRect getRect();
    void setSpriteTextureRect(int xSprite, int ySprite, int wSprite, int hSprite);
    void setSpritePosition(float x, float y);

    bool getLife();
    void setLife(bool life);

    Sprite getSprite();

    float getX();
    float getY();
    void setX(float x);
    void setY(float y);

    void setXSprite(int xSprite);
    void setYSprite(int ySprite);
    int getXSprite();
    int getYSprite();

    int getWSprite();
    int getHSprite();

    float getDx();
    float getDy();
    void setDx(float dx);
    void setDy(float dy);

    float getAnimSpeed();
    void setAnimSpeed(float animSpeed);

    bool getOnGround();
    void setOnGround(bool onGround);

    float getCurrentFrame();
    void setCurrentFrame(float currentFrame);

    float getHealth();
    int changeHealth(); 
    
    int getScore();
    void setScore(int score);
   
    void setSpriteScale(float scale);
    void setSpriteRotate(float angle);

    void setCollision(float xCollision, float yCollision, int wCollision, int hCollision);
    void setScoreCollision(float xScoreCollision, float yScoreCollision, int wScoreCollision, int hScoreCollision);

    FloatRect getCollision();
    FloatRect getScoreCollision();

    int getQuantityOfFrame();

private:
    float x, y, dx, dy;
    float animSpeed; 
    float currentFrame;
    int quantityOfFrame;
    int wSprite, hSprite, xSprite, ySprite;
    bool life, onGround;
    Texture texture;
    Sprite sprite;

    FloatRect collision;
    FloatRect scoreCollision;
    float xCollision, yCollision;
    int wCollision, hCollision;
    float xScoreCollision, yScoreCollision;
    int wScoreCollision, hScoreCollision;

    int health;
    static int score;
};




