#include "Classes.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

City::City()
{
	cout << "Podaj ilosc aut w miejsce"<<endl;
	cin >> numberOfCars;
	cout << "Podaj ilosc blokow w rzedzie" << endl;
	cin >> numberOfBlocks;
	cout << "Podaj szerokosc bloku" << endl;
	cin >> blockWidth;
	size = numberOfBlocks*blockWidth + (2 * (numberOfBlocks+1));

	map.assign(size, vector<int>(size));
	for (int i = 0; i<size; i++)
		for (int j = 0; j < size; j++)
			map[i][j] = 0;
}

City::City(int nOC, int nOB, int bW)
{
	numberOfBlocks = nOB;
	numberOfCars = nOC;
	blockWidth = bW;
	size = numberOfBlocks*blockWidth + (2 * (numberOfBlocks + 1));



	map.assign(size, vector<int>(size));
	for (int i = 0; i<size; i++)
		for (int j = 0; j < size; j++)
			map[i][j] = 0;
}

void City::checkCrossroads()
{
	for (int i = 0; i < vecCars.size(); i++)
	{
		for (int j = 0; j < vecCrossroads.size(); j++)
		{
			vecCrossroads[j]->CheckCrossroad(vecCars[i]);
		}

	}
}

void City::Initialize()
{
	for (int i = 2; i < size; i = i + blockWidth + 2)
		for (int j = 2; j < size; j = j + blockWidth + 2)
		{
			vecBlocks.push_back(new Block(i, j, blockWidth));

			for (int a = i; a < i + blockWidth; a++)
				for (int b = j; b < j + blockWidth; b++)
					map[a][b] = 1;
		}
	for (int i = 0; i < vecBlocks.size(); i++)
		vecBlocks[i]->setShape();


	/*
	Generowanie blokow
	----------------------------------------------------------------------
	generowanie aut
	*/
	srand(time(NULL));

	int xaut, yaut, cardir;
	for (int counter = 0; counter < numberOfCars; counter++)
	{
		cardir = n;
		xaut = rand() % (size - 2) + 1;
		yaut = rand() % (size - 2) + 1;
		if (map[xaut][yaut] == 0)
		{
			if (map[xaut + 1][yaut + 1] == 1 && map[xaut + 1][yaut - 1] == 1)
			{
				vecCars.push_back(new Car(xaut, yaut, u));
				map[xaut][yaut] = 2;
			}
			else if (map[xaut - 1][yaut + 1] == 1 && map[xaut - 1][yaut - 1] == 1)
			{
				vecCars.push_back(new Car(xaut, yaut, d));
				map[xaut][yaut] = 2;
			}
			else if (map[xaut + 1][yaut - 1] == 1 && map[xaut - 1][yaut - 1] == 1)
			{
				vecCars.push_back(new Car(xaut, yaut, l));
				map[xaut][yaut] = 2;
			}
			else if (map[xaut + 1][yaut + 1] == 1 && map[xaut - 1][yaut + 1] == 1)
			{
				vecCars.push_back(new Car(xaut, yaut, r));
				map[xaut][yaut] = 2;
			}
			else if (cardir == n)
				counter--;
		}
		else
			counter--;
	}


	for (int i = 0; i < vecCars.size(); i++)
		vecCars[i]->setShape();

	/*
	Generowanie aut
	----------------------------------------------------------------------
	generowanie skrzyzowan
	*/

		for (int i = 0; i < size; i = i + blockWidth + 2)
			for (int j = 0; j < size; j = j + blockWidth + 2)
			{
				direction type = n;
				if (i == 0 && j == 0)
					type = tl;
				else if (i == size - 2 && j == size - 2)
					type = br;
				else if (i == 0 && j == size - 2)
					type = bl;
				else if (i == size - 2 && j == 0)
					type = tr;
			
				else
				{
					if (j == 0)
						type = u;
					if (j == size - 2)
						type = d;
					if (i == 0)
						type = l;
					if (i == size - 2)
						type = r;
				}
				vecCrossroads.push_back(new Crossroads(i, j, type));
			}
		
}

void City::Simulate()
{
	sf::RenderWindow okno(sf::VideoMode(size, size), "Miasto");
	sf::Clock stoper;
	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();

		}

		okno.clear();

	
		for each (Block *b in vecBlocks)	//Rysowanie blokow
			okno.draw(*b);

		for each (Car *c in vecCars)		//Rysowanie autek
			okno.draw(*c);

		for each (Car *c in vecCars)		//Ruch autek nie na skrzyzowaniach
			c->move();

		srand(time(NULL));
		for each (Crossroads *cross in vecCrossroads)		//Ruch autek na skrzyzowaniach
			cross->movement();
	
		checkCrossroads();					//Sprawdzenie co wjechalo na skrzyzowania

		for each (Car *c in vecCars)		//Odœwie¿enie autek
			c->refresh();




		okno.display();
	}

}