#pragma once
#include <SFML/Graphics.hpp>

const int HEIGHT_MAP = 9;
const int WIDTH_MAP = 30;
int RandomTileMapX, RandomTileMapY, CountStone;

sf::String TileMap[HEIGHT_MAP] = {
	"000000000000000000000000000000",
	"0                            0",
	"0                            0",
	"0                            0",
	"0                            0",
	"0                            0",
	"0                            0",
	"0                            0",
	"0                            0",
};

/*
void RandomTileMap()
{
	srand(time(NULL));

	CountStone = 8;

	while (CountStone>0)
	{
		RandomTileMapX = 1 + rand()%(WIDTH_MAP - 1);
		RandomTileMapY = 1 + rand()%(HEIGHT_MAP - 1);

		if (TileMap[RandomTileMapY][RandomTileMapX]==' ')
		{
		TileMap[RandomTileMapY][RandomTileMapX] = 's';
		CountStone--;
		}
	}
};*/

