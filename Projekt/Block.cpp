#include "Classes.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


Block::Block(int i, int j,int width)
{
	size = width;
	x = i;
	y = j;
}


void Block::setShape() 
{
	rect.setSize(sf::Vector2f(size, size));
	rect.setPosition(sf::Vector2f(x, y));
	sf::Color gray(255, 255, 255, 100);
	rect.setFillColor(gray);
}


void Block::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(rect, state);
}