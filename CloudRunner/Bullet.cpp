#include "Bullet.h"

Bullet::Bullet(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite,float animSpeed, int quantityOfFrame):Entity(texture,x,y,xSprite,ySprite,wSprite,hSprite, animSpeed, quantityOfFrame)
{
    bulletScore = 0;
}

void Bullet::shoot(float& time)
{
    setDx(-0.15);
    setX(getX() + getDx() * time);

    setSpritePosition(getX(), getY());
    setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);
 
    if (getCurrentFrame() > getQuantityOfFrame())
    {
        setCurrentFrame(0);
    }
    else
    {
        setSpriteTextureRect(400, 300 +100* int(getCurrentFrame()), 100, 100);
        setSpriteScale(0.2);
        setCollision(getX() + 18*0.2, getY()+30/2, 60*0.2, 45*0.2);
    }

    if (getX() < 0) { setLife(false); }

}
