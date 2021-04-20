#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void SetPlayerCoordinateForView(float &x, float &y)
{
	view.setCenter(x,y);//следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо
}


/*
void ViewMap(float time) //функция для перемещения камеры по карте. принимает время sfml
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{view.move(0.1*time,0);}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{view.move(-0.1 * time, 0);}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{view.move(0,-0.1 * time);}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{view.move(0, 0.1 * time);}
}

void changeView()
{
	if (Keyboard::isKeyPressed(Keyboard::U))
	{view.zoom(1.01f);}

	if (Keyboard::isKeyPressed(Keyboard::R))
	{view.rotate(1);}

	if (Keyboard::isKeyPressed(Keyboard::P))
	{view.setSize(200,300);}

}*/