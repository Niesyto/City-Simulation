#include "Classes.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <random>
#include <ctime>

void Car::refresh()
{
	rect.setPosition(sf::Vector2f(x, y));
}

void Car::setShape()
{
	rect.setSize(sf::Vector2f(1, 1));
	rect.setPosition(sf::Vector2f(x, y));
	rect.setFillColor(sf::Color::Green);
}

void Car::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(rect, state);
}

void Car :: move()
{
	if (onCrossroad == 0)
	{
		if (direct == u)
			y--;
		else if (direct == l)
			x--;
		else if (direct == r)
			x++;
		else if (direct == d)
			y++;
	}
}

Car::Car(int i, int j, direction dir)
{
	direct = dir;
	x = i;
	y = j;
}

void Car::newDirection(direction from, direction crossType)
{

	int buffer;
	

	if (crossType == bl)
	{
		if (from == u)
			direct = r;
		else if (from == r)
			direct = u;
	}
	else if (crossType == br)
	{
		if (from == u)
			direct = l;
		else if (from == l)
			direct = u;
	}
	else if (crossType == tl)
	{
		if (from == d)
			direct = r;
		else if (from == r)
			direct = d;
	}
	else if (crossType == tr)
	{
		if (from == d)
			direct = l;
		else if (from == l)
			direct = d;
	}


	else if (crossType == n)
	{
		buffer = rand() % 3;
		if (from == d)
		{
			if (buffer == 0)
				direct = r;
			else if (buffer == 1)
				direct = l;
			else if (buffer == 2)
				direct = u;
		}		
		else if (from == l)
		{
			if (buffer == 0)
				direct = r;
			else if (buffer == 1)
				direct = u;
			else if (buffer == 2)
				direct = d;
		}
		else if (from == r)
		{
			if (buffer == 0)
				direct = u;
			else if (buffer == 1)
				direct = d;
			else if (buffer == 2)
				direct = l;
		}
		else if (from == u)
		{
			if (buffer == 0)
				direct = l;
			else if (buffer == 1)
				direct = r;
			else if (buffer == 2)
				direct = d;
		}	
	}
	else if (crossType == l)
	{
		buffer = rand() % 2;
		if (from == d)
		{
			if (buffer == 0)
				direct = r;
			else if (buffer == 1)
				direct = u;
		}
		else if (from == r)
		{
			if (buffer == 0)
				direct = u;
			else if (buffer == 1)
				direct = d;
		}
		else if (from == u)
		{
			if (buffer == 0)
				direct = d;
			else if (buffer == 1)
				direct = r;
		}
	}
	else if (crossType == r)
	{
		buffer = rand() % 2;
		if (from == d)
		{
			if (buffer == 0)
				direct = u;
			else if (buffer == 1)
				direct = l;
		}
		else if (from == l)
		{
			if (buffer == 0)
				direct = u;
			else if (buffer == 1)
				direct = d;
		}
		else if (from == u)
		{
			if (buffer == 0)
				direct = d;
			else if (buffer == 1)
				direct = l;
		}
	}
	else if (crossType == u)
	{
		buffer = rand() % 2;
		if (from == d)
		{
			if (buffer == 0)
				direct = r;
			else if (buffer == 1)
				direct = l;
		}
		else if (from == l)
		{
			if (buffer == 0)
				direct = d;
			else if (buffer == 1)
				direct = r;
		}
		else if (from == r)
		{
			if (buffer == 0)
				direct = d;
			else if (buffer == 1)
				direct = l;
		}
	}
	else if (crossType == d)
	{
		buffer = rand() % 2;
		if (from == l)
		{
			if (buffer == 0)
				direct = u;
			else if (buffer == 1)
				direct = r;
		}
		else if (from == r)
		{
			if (buffer == 0)
				direct = u;
			else if (buffer == 1)
				direct = l;
		}
		else if (from == u)
		{
			if (buffer == 0)
				direct = r;
			else if (buffer == 1)
				direct = l;
		}
	}
}