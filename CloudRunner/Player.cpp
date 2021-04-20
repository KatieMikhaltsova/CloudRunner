#include "Player.h"

using namespace sf;

Player::Player(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite,float animSpeed, int quantityOfFrame) :Entity(texture, x, y, xSprite, ySprite, wSprite, hSprite, animSpeed, quantityOfFrame)
{
    playerState =RIGHT;
    quantityOfRebirth = 0;
}

void Player::update(float& time, RenderWindow& window)
{
    switch (playerState)
    {
    case RIGHT:
        moveForward(time);
        break;
    case JUMP:
        moveUp(time);
        break;
    case CROUCH:
        moveDown(time);
        break;
    case REBIRTH:
        moveRebirth(time, window);
        break;
    case DEATH:
        endGame(time);
        break;
    };

    setX(getX() + getDx() * time);
    setY(getY() + getDy() * time);
    setSpritePosition(getX(), getY());

    setScoreCollision(getX(), getY(), 1, 100);

    if (getHealth() == 0) { setLife(false); }
}

void Player::control(float& time, Sound& soundJump, Sound& soundCrouch, Sound& soundDown)
{
    if ((Keyboard::isKeyPressed(Keyboard::Up)) && (getOnGround())) {
        soundJump.play();
        playerState =JUMP;
        setCurrentFrame(0);
        setOnGround(false);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) && (getOnGround())) {
  
        soundDown.play();
        playerState = CROUCH;
        setCurrentFrame(0);
        setOnGround(false);
    }
}

void Player::moveForward(float& time)
{
    setAnimSpeed(0.005);
    setDx(0.02);
    setDy(0);

    setCurrentFrame(getCurrentFrame() +getAnimSpeed() * time);

    if (getCurrentFrame() >getQuantityOfFrame())
    { 
        setCurrentFrame(0);
    }
    else
    { 
        setSpriteTextureRect(100 * int(getCurrentFrame()), 200,getWSprite(), getHSprite());
        setCollision(getX() + 40, getY(), 32, getHSprite()); 
    }
}

void Player::moveUp(float& time)
{
    setAnimSpeed(0.009);
    
    if (getCurrentFrame()==0)
    {
        setDy(0);
        setDx(0);
        setSpriteTextureRect(0, 300, getWSprite(), getHSprite());
        setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);
        setCollision(getX() + 35, getY(), 32,getHSprite());
    }
    else 
    {
        setDy(-0.3);
        setDx(0.015);

        setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);

        if (getCurrentFrame() > 3)
        {
            setDy(0.65);
            setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);

            if (getY() > 200) 
            {
                setCurrentFrame(0);
                setY(200);
                setDy(0);
                playerState = RIGHT;
                setOnGround(true);
            }
        }
        else
        {
            setSpriteTextureRect(100 * int(getCurrentFrame()), 300, getWSprite(), getHSprite());
            setCollision(getX() + 35, getY(), 32, getHSprite());
        }
    }
}

void Player::moveDown(float& time)
{
    setDy(0);
    if (getX()>10) { setDx(-0.05); }
    else { setDx(0); }
   
    if (getCurrentFrame() <2.1)
    {
        setCurrentFrame(getCurrentFrame() + 0.003 * time);
        
        setSpriteTextureRect(100 * int(getCurrentFrame()), 400, 100, 100);
        setCollision(getX() +40, getY(), 32, 100);
    }

    if ((getCurrentFrame() > 2.1) && Keyboard::isKeyPressed(Keyboard::Down))
    {
       setSpriteTextureRect(200, 400, 100,100);
       setCollision(getX() + 40, getY()+50, 32, 50);
    }
    else { if (getCurrentFrame() < 4)
        {
            setCurrentFrame(getCurrentFrame() + 0.008 * time);
            setSpriteTextureRect(100 * int(getCurrentFrame()), 400, 100, 100);
            setCollision(getX() + 40, getY()+50, 32, 50);
        }
    }
    if(getCurrentFrame() > 4)
     {
        setCurrentFrame(getCurrentFrame() - 4);
        playerState = RIGHT;
        setOnGround(true);
     }
}

void Player::moveRebirth(float& time, RenderWindow& window)
{
    setAnimSpeed(0.2);
    
    if (getX() > 10)
    {
        setDy(getAnimSpeed());
        setDx(0);
        setSpriteTextureRect(200, 300, getWSprite(), getHSprite());

        if (getY() > window.getSize().y)
        {
            setSpritePosition(10, 0);
        }
    }

    if (getX()==10)
    {
        setDy(getAnimSpeed());
        
        if (getY()>200)
        {
            setY(200);
            playerState = RIGHT;
            setOnGround(true);
            quantityOfRebirth ++;
            setScore(getScore() + quantityOfRebirth * 10);
        } 
    }
    setCollision(getX() + 40, getY(), 32, getHSprite());
}

void Player::endGame(float& time)
{
    if (getCurrentFrame() < 8)
    {
        setAnimSpeed(0.005);
        setDx(-getAnimSpeed());
        setDy(0);
        setSpriteTextureRect(300, 300, getWSprite(), getHSprite());
        setY(202);
        setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);
    }
}

void Player::rebirth(Entity& enemy, RenderWindow& window)
{
    if (getCollision().intersects(FloatRect(enemy.getX()-25,enemy.getY(), getWSprite(), getHSprite())))
    {
        playerState = REBIRTH;
        setOnGround(false);
    }
}

int Player::getQuantityOfRebirth()
{
    return quantityOfRebirth;
}

void Player::setQuantityOfRebirth(int quantityOfRebirth)
{
    this->quantityOfRebirth = quantityOfRebirth;
}

void Player::setState(State playerState)
{
    this->playerState = playerState;
}



