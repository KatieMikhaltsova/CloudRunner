#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include<list>
#include <fstream>


class Enemy :public Entity {

public:

    enum State { DOWN_SHOOT, UP_SHOOT, STAY };

    Enemy(Texture& texture, float x, float y, int xSprite, int ySprite, int wSprite, int hSprite,float animSpeed, int quantityOfFrame);

    void update(float& time);
    void animDownShoot(float& time);
    void animUpShoot(float& time);
    void spawnBullet(float& time, Bullet bullet,Sound &shoot);
    void eraseBullet(float& time,Player& player);
    void drawBullet(RenderWindow &window);
    void hitPlayer(Player &player, Sound& soundHit);
    void scoring(Player& player);
    void saveBestScore();

    void setMinSpeedShoot(int minSpeedShoot);
    void setIntervalSpeedShoot(int intervalSpeedShoot);

    void setState(State state);
    State getState()
    {
        return enemyState;
    }

private:
    State enemyState;
    std::list<Bullet> bulletList;
    std::list<Bullet>::iterator itBullet;
    bool shootAbility;
    float spawnPossibilityTimer;
    int spawnBulletTimer;
    int minSpeedShoot;
    int intervalSpeedShoot;
    std::fstream saveScore;
    char charScore;
    int bestScore;
    std::vector <char> bestScoreVector;
};


