#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Widget.h"
#include <fstream>
#include "Player.h"
using namespace sf;

class WidgetBar
{
public:

    enum State {START, PAUSE, ANIM, END};

    static bool start;
    static bool restart;
    static int quantityHealth;

    WidgetBar(RenderWindow& window);
   
    void drawPauseMenu(RenderWindow& window,Widget &wNewGame,Widget &wContinueGame,Widget& wBestScore, Widget& wNumbers);
    void drawStartMenu(RenderWindow& window, Widget& wNewGame, Widget& wBestScore, Widget& wNumbers);
    void drawEndMenu(RenderWindow& window, Widget& wNewGame, Widget& wBestScore, Widget& wNumbers);

    void pressButtonMenu(RenderWindow& window, float& time,Widget& wNewGame, Widget& wContinueGame, Sound& pressButton);

    void drawWidgetsScore(RenderWindow& window, Widget& wNumbers, Widget& wScore,Player& player);
    void drawWidgetsHealth(RenderWindow& window, Widget& wHealth);

    void animWidgetsHealth(RenderWindow& window,float &time);
    void animWidgetsButton(RenderWindow& window, float& time, Widget& wButton);

    State getState(){ return menuState; } 
    void setState(State state) { menuState=state;}

    void setCurrentFrame(float currentFrame);
    void setCurrentFrameHealth(float currentFrameHealth);

private:
	std::vector <Widget> wHealthVector;
    State menuState;
    float currentFrame;
    float currentFrameHealth;
    std::fstream saveScore;
    char charScore;
    std::vector <char> bestScoreVector;
    Clock clock;
    int lenScore;
    
};






