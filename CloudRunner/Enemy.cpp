#include "Enemy.h"

Enemy::Enemy(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite,float animSpeed, int quantityOfFrame) :Entity(texture, x, y,xSprite,ySprite,wSprite,hSprite, animSpeed,quantityOfFrame)
{
        enemyState = STAY;
        shootAbility = true;
        spawnPossibilityTimer = 0;
        bestScore = 0;
        minSpeedShoot = 11;
        intervalSpeedShoot = 10;
}

void Enemy::update(float& time)
{
    switch (enemyState)
    {
    case DOWN_SHOOT: 
        animDownShoot(time);
        break;

    case UP_SHOOT:
        animUpShoot(time);
        break;

    case STAY:
        setSpriteTextureRect(0, 0, getWSprite(), getHSprite());
        setSpritePosition(getX(), getY());
        break;
    }
}

void Enemy::animDownShoot(float& time)
{
    setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);

    if (getCurrentFrame() > getQuantityOfFrame())
    {
        shootAbility = true;
        setCurrentFrame(0);
    }
    else
    {
        setSpriteTextureRect(100 * int(getCurrentFrame()), 100, getWSprite(), getHSprite());
        setSpritePosition(getX(), getY());
    }
}

void Enemy::animUpShoot(float& time)
{
    setCurrentFrame(getCurrentFrame() + getAnimSpeed() * time);
    if (getCurrentFrame() > getQuantityOfFrame())
    {
        shootAbility = true;
        setCurrentFrame(0);
    }
    else
    {
        setSpriteTextureRect(100 * int(getCurrentFrame()), 0, getWSprite(), getHSprite());
        setSpritePosition(getX(), getY());
    }
}

void Enemy::spawnBullet(float& time, Bullet bullet, Sound& shoot)
{
    if (shootAbility && enemyState==UP_SHOOT)
    {
        bullet.setY(215);
        bulletList.push_back(bullet);
        shoot.play();
        shootAbility=false;
        enemyState=STAY;
    }

    if (shootAbility && enemyState == DOWN_SHOOT)
    {
        bullet.setY(270);
        bulletList.push_back(bullet);
        shoot.play();
        shootAbility = false;
        enemyState = STAY;
    }

    if (enemyState == STAY)
    {
            if (spawnPossibilityTimer ==0)
            {
                srand(std::time(NULL));
                spawnBulletTimer =  rand() %(intervalSpeedShoot) + (minSpeedShoot);
            }

            spawnPossibilityTimer += 0.015;
           
            if (spawnPossibilityTimer > spawnBulletTimer)
            {
                srand(std::time(NULL));
                enemyState =static_cast<State>(std::rand() % 2);
                spawnPossibilityTimer = 0;
            }
    }

    for (itBullet = bulletList.begin(); itBullet != bulletList.end();++itBullet){itBullet->shoot(time);}
}

void Enemy::eraseBullet(float& time, Player& player)
{
    for (itBullet = bulletList.begin(); itBullet != bulletList.end();)
    {
        if (!itBullet->getLife() || player.getState()==Player::REBIRTH) {itBullet = bulletList.erase(itBullet);}
        else { ++itBullet; }
    }
}

void Enemy::drawBullet(RenderWindow& window)
{
    for (itBullet = bulletList.begin(); itBullet != bulletList.end(); ++itBullet)
    {
        window.draw(itBullet->getSprite());
    }
}

void Enemy::hitPlayer(Player& player, Sound& soundHit)
{
    for (itBullet = bulletList.begin(); itBullet != bulletList.end();)
    {
        if (itBullet->getCollision().intersects(player.getCollision()))
        {
            itBullet = bulletList.erase(itBullet);
            player.changeHealth();
            soundHit.setVolume(200);
            soundHit.play();
        }
        else { ++itBullet; }
    }
}

void Enemy::scoring(Player& player)
{
    player.setScoreCollision(player.getX(), player.getY(), 1, 200);

    for (itBullet = bulletList.begin(); itBullet != bulletList.end(); ++itBullet)
    {
       if(player.getScoreCollision().intersects(itBullet->getCollision()))
       { 
           if (itBullet->bulletScore ==0)
           {
               itBullet->bulletScore = 1;
               player.setScore(getScore()+1);
           }
       }
    }
}

void Enemy::saveBestScore()
{
    saveScore.open("save.txt", std::fstream::in);

    while (saveScore.get(charScore))
    {
        bestScoreVector.push_back(charScore);
    }

    for (int i = 0; i < bestScoreVector.size(); i++)
    {
        bestScore = bestScore + (static_cast<int>(bestScoreVector[i] - 48)) * pow(10, (bestScoreVector.size() - 1 - i));
    }

    saveScore.close();
    bestScoreVector.clear();

    if (getScore() > bestScore)
    {
        saveScore.open("save.txt", std::fstream::out);
        saveScore << getScore();
        saveScore.close();
    }
}

void Enemy::setMinSpeedShoot(int minSpeedShoot)
{
    this->minSpeedShoot = minSpeedShoot;
}

void Enemy::setIntervalSpeedShoot(int intervalSpeedShoot)
{
    this->intervalSpeedShoot = intervalSpeedShoot;
}

void Enemy::setState(State state)
{
    enemyState = state;
}

