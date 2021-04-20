#include "Game.h"

bool gameRunning(RenderWindow& window)
{
    ////////////// loading music and sound
    Music music;
    music.openFromFile("Music/music.wav");
    music.setVolume(30);

    SoundBuffer buffer;
    buffer.loadFromFile("Music/shoot.wav");
    Sound shoot;
    shoot.setBuffer(buffer);

    SoundBuffer bJump;
    bJump.loadFromFile("Music/jump.wav");
    Sound soundJump;
    soundJump.setBuffer(bJump);

    SoundBuffer bCrouch;
    bCrouch.loadFromFile("Music/crouch.wav");
    Sound soundCrouch;
    soundCrouch.setBuffer(bCrouch);

    SoundBuffer bDown;
    bDown.loadFromFile("Music/down.wav");
    Sound soundDown;
    soundDown.setBuffer(bDown);

    SoundBuffer bHit;
    bHit.loadFromFile("Music/hit.wav");
    Sound soundHit;
    soundHit.setBuffer(bHit);

    SoundBuffer bDeath;
    bDeath.loadFromFile("Music/death.wav");
    Sound soundDeath;
    soundDeath.setBuffer(bDeath);

    ////////////// loading background
    Texture tBackgroun;
    tBackgroun.loadFromFile("images/sky.jpg");
    Sprite sBackgroun;
    sBackgroun.setTexture(tBackgroun);

    Texture tBackground;
    tBackground.loadFromFile("images/background.png");

    Sprite sEnemyPlatform;
    sEnemyPlatform.setTexture(tBackground);
    sEnemyPlatform.setTextureRect(IntRect(360, 115, 140, 385));
    sEnemyPlatform.setPosition(813,290);
    sEnemyPlatform.setScale(0.6,0.6);
    
    Sprite sPlayerRightPlatform;
    sPlayerRightPlatform.setTexture(tBackground);
    sPlayerRightPlatform.setTextureRect(IntRect(193, 115, 160, 385));
    sPlayerRightPlatform.setPosition(660, 290);
    sPlayerRightPlatform.setScale(0.6, 0.6);

    Sprite sPlayerMiddlePlatform;
    sPlayerMiddlePlatform.setTexture(tBackground);
    sPlayerMiddlePlatform.setTextureRect(IntRect(7, 115, 168, 385));
    sPlayerMiddlePlatform.setScale(0.6, 0.6);

    Sprite sPlayerLeftPlatform;
    sPlayerLeftPlatform.setTexture(tBackground);
    sPlayerLeftPlatform.setTextureRect(IntRect(353, 115, -160, 385));;
    sPlayerLeftPlatform.setPosition(-35, 290);
    sPlayerLeftPlatform.setScale(0.6, 0.6);

    ////////////// loading shadow and cloud
    Sprite sShadowPlayer;
    sShadowPlayer.setTexture(tBackground);
    sShadowPlayer.setTextureRect(IntRect(370, 90, 130, 20));
   
    Sprite sShadowEnemy;
    sShadowEnemy.setTexture(tBackground);
    sShadowEnemy.setTextureRect(IntRect(370, 90, 130, 20));
    sShadowEnemy.setScale(0.5,0.4);
    sShadowEnemy.setPosition(825,290);

    Background cloud(tBackground, 0, 0, 0, 0, 350, 100, 0.05, 1);
    
    ////////////// creating of the player,enemy and bullet
    Texture tSprite;
    tSprite.loadFromFile("images/sprite.png");
    Player player(tSprite, 10, 200, 0,200,100, 100,0.005,4);
    Enemy enemy(tSprite, 800, 198, 0,0,100, 100, 0.005,4);
    Bullet bullet(tSprite, 820, 0, 400, 300, 100, 100, 0.005, 2);

    ////////////// creating of the widgets
    Texture tWidget;
    tWidget.loadFromFile("images/widget.png");
    Widget wNewGame(tWidget, 0, 70, 200,70, Widget::State::NEW_GAME);
    Widget wContinueGame(tWidget, 0, 0, 200, 70, Widget::State::CONTINUE_GAME);
    Widget wQuit(tWidget, 0, 0, 20, 20, Widget::State::QUIT);
    Widget wHealth(tSprite,400, 0,100, 100, Widget::HEALTH);
    Widget wBestScore(tWidget, 0, 130, 200, 70, Widget::BEST_SCORE);
    Widget wScore(tWidget, 84, 130, 116, 70, Widget::SCORE);
    Widget wNumbers(tWidget, 200, 130, 20, 70, Widget::BEST_SCORE);
    WidgetBar wBar(window);

    Clock clock;
  
    //////////////  game loop
    while (window.isOpen())
    {
      float time = clock.getElapsedTime().asMicroseconds();
      clock.restart();
      time = time / 800;
      Event event;

      while (window.pollEvent(event))
      { 
        if (event.type == Event::Closed) { window.close(); }
        if (event.type == Event::Resized) { window.setSize(Vector2u(960, 542)); }
      }
     
     //////////////  reloading the game
        if (WidgetBar::restart)
        {
            player.setScore(0);
            WidgetBar::quantityHealth = 3;
            WidgetBar::restart = false;
            return false;
        }

     //////////////  menu output
        if (!WidgetBar::start && !WidgetBar::restart)
        {
            window.setMouseCursorVisible(true);
            music.pause();
            window.clear();
            window.draw(sBackgroun);
           
            if (wBar.getState() == WidgetBar::START) { wBar.drawStartMenu(window, wNewGame,  wBestScore,wNumbers); }
            if (wBar.getState() == WidgetBar::PAUSE){ wBar.drawPauseMenu(window, wNewGame, wContinueGame,  wBestScore, wNumbers); wBar.drawWidgetsScore(window, wNumbers, wScore, player); }
            if (wBar.getState() == WidgetBar::END) { wBar.drawEndMenu(window, wNewGame,  wBestScore, wNumbers); wBar.drawWidgetsScore(window, wNumbers, wScore, player);}

            if (wNewGame.getAnim()) { wBar.animWidgetsButton(window, time, wNewGame);}
            if (wContinueGame.getAnim()){ wBar.animWidgetsButton(window, time, wContinueGame); }
            
            window.display();

            while (window.pollEvent(event)) 
            {
                if (event.type == Event::Closed) { window.close(); }
                if (event.type == Event::Resized) { window.setSize(Vector2u(960, 542)); }
                if (event.type == Event::MouseButtonPressed) { wBar.pressButtonMenu(window,time, wNewGame, wContinueGame, soundHit); }
            }
        }

     //////////////  start the game
        if (WidgetBar::start && !WidgetBar::restart ) 
        {
            window.setMouseCursorVisible(false);

            if (music.getStatus() != Music::Playing)
            {
                music.play();
                music.setLoop(true);
            }

            if (music.getStatus()==Music::Paused)
            {
                music.play();
            }
            
            enemy.spawnBullet(time, bullet,shoot);
            enemy.scoring(player);
            player.control(time,soundJump, soundCrouch,soundDown);
            player.update(time, window);
            player.rebirth(enemy, window);

            if (player.getState()==Player::REBIRTH){ enemy.setState(Enemy::STAY);}

            ////////// changing frequency of shoot
            switch (player.getQuantityOfRebirth())
            {
            case 1:
                enemy.setMinSpeedShoot(9);
                break;
            case 2:
                enemy.setMinSpeedShoot(7);
                break;
            case 3:
                enemy.setMinSpeedShoot(5);
                break;
            case 4:
                enemy.setMinSpeedShoot(3);
                break;
            case 5:
                enemy.setIntervalSpeedShoot(5);
                enemy.setMinSpeedShoot(1);
                break;
            }

            enemy.update(time);
            enemy.eraseBullet(time, player);
            enemy.hitPlayer(player,soundHit);

            window.clear();

            ////////// drawing background
            window.draw(sBackgroun);
            window.draw(sEnemyPlatform);
            window.draw(sPlayerRightPlatform);
            cloud.animCloud(window, time, cloud);
            window.draw(sPlayerLeftPlatform);
            for (int i = 0; i <6; i++)
            {
                sPlayerMiddlePlatform.setPosition(560-100*i, 290);
                window.draw(sPlayerMiddlePlatform);
            }
        
            ////////////// drawing enemy, player and bullet
            window.draw(enemy.getSprite());
            enemy.drawBullet(window);
            window.draw(player.getSprite());

            ////////////// drawing shadow
            if (player.getState()== Player::RIGHT )
            {
                sShadowPlayer.setScale(0.3, 0.3);
                sShadowPlayer.setPosition(player.getX()+30,292);
                window.draw(sShadowPlayer);
            }
            if (player.getState() == Player::CROUCH)
            {
                sShadowPlayer.setScale(0.5,0.3);
                sShadowPlayer.setPosition(player.getX()+20, 292);
                window.draw(sShadowPlayer);
            }
            if (player.getState() == Player::DEATH)
            {
                sShadowPlayer.setPosition(player.getX(), 287);
                sShadowPlayer.setScale(0.7, 0.7);
                window.draw(sShadowPlayer);
            }
            window.draw(sShadowEnemy);

            ////////////// drawing score and health
            wBar.drawWidgetsScore(window, wNumbers, wScore, player);
            wBar.drawWidgetsHealth(window, wHealth);

            ////////////// animation health
            if (player.getHealth() == 2)
            {
                WidgetBar::quantityHealth = 2;
                wBar.animWidgetsHealth(window, time);
            }
            else
            {
                if (player.getHealth() == 1)
                {
                    if (WidgetBar::quantityHealth != 1)
                    {
                        wBar.setCurrentFrameHealth(0);
                    }

                    WidgetBar::quantityHealth = 1;
                    wBar.animWidgetsHealth(window, time);
                }
                else
                {
                    if (player.getHealth() == 0)
                    {

                        if (WidgetBar::quantityHealth != 0)
                        {
                            wBar.setCurrentFrameHealth(0);
                        }
                        WidgetBar::quantityHealth = 0;
                        wBar.animWidgetsHealth(window, time);
                    }
                }
            }

            window.display();

            ////////////// exit to the menu
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                enemy.saveBestScore();
                WidgetBar::start = false;
                wBar.setState(WidgetBar::PAUSE);
            }

            ////////////// player death
            if (!player.getLife())
            {
                if (player.getState()!= Player::DEATH)
                {
                    music.stop();
                    soundDeath.setVolume(30);
                    soundDeath.play();
                }

                enemy.saveBestScore();
                enemy.setState(Enemy::STAY);
                player.setState(Player::DEATH);
                
                player.update(time, window);

                if (player.getCurrentFrame() > 8)
                {
                    player.setCurrentFrame(0);
                    WidgetBar::start = false;
                    wBar.setState(WidgetBar::END);
                }
            }
        }
    }
  
    return true;
}
