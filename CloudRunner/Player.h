#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"

    class Player :public Entity
    {
    public:

        enum State {RIGHT,JUMP,CROUCH,DEATH,REBIRTH};

        Player(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite,float animSpeed, int quantityOfFrame);


        void update(float& time, RenderWindow& window);

        void control(float& time, Sound& soundJump,Sound& soundCrouch, Sound& soundDown);

        void moveForward(float& time);

        void moveUp(float& time);
       
        void moveDown(float& time);

        State getState(){ return playerState;}

        void setState(State playerState);

        void moveRebirth(float& time, RenderWindow& window);

        void endGame(float& time);
  
        void rebirth(Entity& enemy, RenderWindow& window);

        int getQuantityOfRebirth();

        void setQuantityOfRebirth(int quantityOfRebirth);

    private:

        State playerState;
        int quantityOfRebirth;
    };


