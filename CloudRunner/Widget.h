#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Widget 
{
public:
    enum State {NEW_GAME, CONTINUE_GAME, QUIT, HEALTH, BEST_SCORE, SCORE};

    Widget(Texture& texture, int xSprite, int ySprite, int wSprite, int hSprite, State state);

    Sprite getSprite();
    void setSpritePosition(float x, float y);

    void setSpriteScale(float scale);
   
    void setSpriteTextureRect(int xSprite, int ySprite, int wSprite, int hSprite);

    int getWSprite();
    int getHSprite();

    float getCurrentFrame();
    void setCurrentFrame(float currentFrame);

    void setXSprite(int xSprite);
    void setYSprite(int ySprite);
    int getXSprite();
    int getYSprite();

    bool getAnim();
    void setAnim(bool animWidget);
   
    State getState() { return stateWidget; };

private:

   int xSprite, ySprite, wSprite, hSprite;
   float x, y;
   Texture texture;
   Sprite sprite;
   State stateWidget;
   float currentFrame;
   bool animWidget;
};

