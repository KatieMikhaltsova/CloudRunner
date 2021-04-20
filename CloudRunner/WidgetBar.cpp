#include "WidgetBar.h"

WidgetBar::WidgetBar(RenderWindow& window)
{
	restart = false;
	currentFrame = 0;
	currentFrameHealth = 0;
}

bool WidgetBar::start = false;
bool WidgetBar::restart = false;
int WidgetBar::quantityHealth = 3;

void WidgetBar::drawPauseMenu(RenderWindow& window, Widget &wNewGame, Widget &wContinueGame, Widget& wBestScore, Widget& wNumbers)
{
	wNewGame.setSpritePosition((window.getSize().x - wNewGame.getWSprite()) / 2.f, (window.getSize().y - 2*wNewGame.getHSprite()) / 2.f);
	wContinueGame.setSpriteTextureRect(0,0,200,70);
	wContinueGame.setSpritePosition((window.getSize().x - wContinueGame.getWSprite()) / 2.f, (window.getSize().y - 4*wContinueGame.getHSprite()) / 2.f);
	
	////////////// get a better result
	saveScore.open("save.txt", std::fstream::in);

	if (saveScore.is_open())
	{
		while (saveScore.get(charScore))
		{
			bestScoreVector.push_back(charScore);
		}
	}
	saveScore.close();

	for (int i = 0; i < bestScoreVector.size(); i++) 
	{
		wNumbers.setSpriteTextureRect(wNumbers.getXSprite() + 20 * (bestScoreVector[i] - 48), wNumbers.getYSprite(), wNumbers.getWSprite(), wNumbers.getHSprite());
		wNumbers.setSpritePosition(((window.getSize().x)+ wBestScore.getWSprite()) / 2.f + 20 * i - 20 * bestScoreVector.size() / 2.f, window.getSize().y /2.f);
		window.draw(wNumbers.getSprite());
	}
	//////////////

	wBestScore.setSpritePosition((window.getSize().x - wBestScore.getWSprite()- bestScoreVector.size()*20) / 2.f, window.getSize().y / 2.f);
	
	bestScoreVector.clear();

	if (!wNewGame.getAnim()) { window.draw(wNewGame.getSprite()); }
	if (!wContinueGame.getAnim()){ window.draw(wContinueGame.getSprite());}
	window.draw(wBestScore.getSprite());
}

void WidgetBar::drawStartMenu(RenderWindow& window, Widget& wNewGame, Widget& wBestScore, Widget& wNumbers)
{
	wNewGame.setSpritePosition((window.getSize().x - wNewGame.getWSprite()) / 2.f, ( window.getSize().y - 2*wNewGame.getHSprite())/2.f);
	
	////////////// get a better result
	saveScore.open("save.txt", std::fstream::in);
	
	if (saveScore.is_open())
	{
		while (saveScore.get(charScore))
		{
			bestScoreVector.push_back (charScore);
		}
	}
	saveScore.close();

	for (int i = 0; i < bestScoreVector.size(); i++) //static_cast????
	{
		wNumbers.setSpriteTextureRect(wNumbers.getXSprite() + 20 * (static_cast<int>(bestScoreVector[i] - 48)),wNumbers.getYSprite(), wNumbers.getWSprite(), wNumbers.getHSprite());
		wNumbers.setSpritePosition(((window.getSize().x) + wBestScore.getWSprite()) / static_cast<float>(2) + 20 * i - static_cast<float>(20) * bestScoreVector.size() / 2, (window.getSize().y) / static_cast<float>(2));
		window.draw(wNumbers.getSprite());
	}
	
	wBestScore.setSpritePosition((window.getSize().x - wBestScore.getWSprite()-bestScoreVector.size()*20) / 2.f, (window.getSize().y) / 2.f);
	
	bestScoreVector.clear();
	////////////// 

	if (!wNewGame.getAnim()){ window.draw(wNewGame.getSprite());}
	window.draw(wBestScore.getSprite());
}

void WidgetBar::drawEndMenu(RenderWindow& window, Widget& wNewGame, Widget& wBestScore, Widget& wNumbers)
{
	wNewGame.setSpritePosition((window.getSize().x - wNewGame.getWSprite()) / 2.f, (window.getSize().y - 3 * wNewGame.getHSprite()) / 2.f);
	
	////////////// get a better result
	saveScore.open("save.txt", std::fstream::in);

	if (saveScore.is_open())
	{
		while (saveScore.get(charScore))
		{
			bestScoreVector.push_back(charScore);
		}
	}
	saveScore.close();

	for (int i = 0; i < bestScoreVector.size(); i++)
	{
		wNumbers.setSpriteTextureRect(wNumbers.getXSprite() + 20 * (bestScoreVector[i] - 48), wNumbers.getYSprite(), wNumbers.getWSprite(), wNumbers.getHSprite());
		wNumbers.setSpritePosition(((window.getSize().x) + wBestScore.getWSprite()) / 2.f + 20 * i - 20 * bestScoreVector.size() / 2.f, (window.getSize().y- wBestScore.getHSprite()) / 2.f);
		window.draw(wNumbers.getSprite());
	}

	wBestScore.setSpritePosition((window.getSize().x - wBestScore.getWSprite() - bestScoreVector.size() * 20) / 2.f, (window.getSize().y- wBestScore.getHSprite()) / 2.f);

	bestScoreVector.clear();
	//////////////

	if (!wNewGame.getAnim()) { window.draw(wNewGame.getSprite()); }
	window.draw(wBestScore.getSprite());
}

void WidgetBar::drawWidgetsScore(RenderWindow& window, Widget& wNumbers, Widget& wScore,Player& player)
{
	if (player.getScore()>0)
	{lenScore = int(log10(player.getScore())) + 1;}
	else{lenScore = 1;}

	for (int i = 0; i < lenScore; i++) 
	{
		wNumbers.setSpriteTextureRect(wNumbers.getXSprite() + wNumbers.getWSprite() *( (int(player.getScore()/pow(10,lenScore-1-i)))%(10)), wNumbers.getYSprite(), wNumbers.getWSprite(), wNumbers.getHSprite());
		
		if (WidgetBar::start){wNumbers.setSpritePosition(window.getSize().x - 85 + wNumbers.getWSprite() * i, 0);}
		else 
		{
			if (menuState == WidgetBar::PAUSE || menuState == WidgetBar::START) { wNumbers.setSpritePosition((window.getSize().x + wScore.getWSprite()) / 2.f + wNumbers.getWSprite() * i, (window.getSize().y + 2 * wScore.getHSprite()) / 2.f); }
			if (menuState == WidgetBar::END) { wNumbers.setSpritePosition((window.getSize().x + wScore.getWSprite()) / 2.f + wNumbers.getWSprite() * i, (window.getSize().y + wScore.getHSprite()) / 2.f); }
		}

		window.draw(wNumbers.getSprite());
	}

	if (WidgetBar::start) { wScore.setSpritePosition(window.getSize().x - 200, 0);}
	else 
	{
		if (menuState == WidgetBar::PAUSE || menuState == WidgetBar::START) { wScore.setSpritePosition((window.getSize().x - wScore.getWSprite() - lenScore * 20) / 2.f, (window.getSize().y + 2 * wScore.getHSprite()) / 2.f); }
		if (menuState == WidgetBar::END) { wScore.setSpritePosition((window.getSize().x - wScore.getWSprite() - lenScore * 20) / 2.f, (window.getSize().y + wScore.getHSprite()) / 2.f); }
	}

	window.draw(wScore.getSprite());
}

void WidgetBar::drawWidgetsHealth(RenderWindow& window, Widget& wHealth)
{
	if (wHealthVector.empty())
	{
		wHealth.setSpriteScale(0.5);

		for (int i = 0; i < quantityHealth; i++)
		{
			wHealthVector.push_back(wHealth);
		}
	}

	if (quantityHealth > 0)
	{
		for (int i = 0; i < quantityHealth; i++)
		{
			wHealthVector[i].setSpritePosition(window.getSize().x / 2.f- 75 + (50) * i, 10);
			window.draw(wHealthVector[i].getSprite());
		}
	}
}

void WidgetBar::pressButtonMenu(RenderWindow& window, float& time, Widget& wNewGame, Widget& wContinueGame, Sound& pressButton)
{
	if (IntRect(wNewGame.getSprite().getPosition().x, wNewGame.getSprite().getPosition().y, wNewGame.getWSprite(), wNewGame.getHSprite()).contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
	{
		pressButton.play();
		wNewGame.setAnim(true);
	}

	if (IntRect(wContinueGame.getSprite().getPosition().x, wContinueGame.getSprite().getPosition().y, wContinueGame.getWSprite(), wContinueGame.getHSprite()).contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
	{
		pressButton.play();
		wContinueGame.setAnim(true);
	}
}

void WidgetBar::animWidgetsHealth(RenderWindow& window,float &time)
{
	currentFrameHealth += 0.025 * time;

	if (currentFrameHealth < 3)
	{
		wHealthVector[quantityHealth].setSpriteTextureRect(400, 100*int(currentFrameHealth), 100, 100);
		wHealthVector[quantityHealth].setSpritePosition(window.getSize().x / 2.f-75+ (50) * (quantityHealth), 10);
		wHealthVector[quantityHealth].setSpriteScale(0.5);
		window.draw(wHealthVector[quantityHealth].getSprite());
	}
}

void WidgetBar::animWidgetsButton(RenderWindow& window, float& time, Widget& wButton)
{
	if (currentFrame < 2)
	{
		currentFrame += 0.02 * time;
		wButton.setSpriteTextureRect(200, 70 - 70 * int(currentFrame), 200, 70);
		window.draw(wButton.getSprite());
	}
	else 
	{
		start = true;
		currentFrame =0;
		wButton.setAnim(false);
		if (wButton.getState() == Widget::NEW_GAME) { restart = true; }
	}
}

void WidgetBar::setCurrentFrame(float currentFrame)
{
	this->currentFrame = currentFrame;
}

void WidgetBar::setCurrentFrameHealth(float currentFrameHealth)
{
	this->currentFrameHealth = currentFrameHealth;
}

