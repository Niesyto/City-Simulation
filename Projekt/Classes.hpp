#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>

class Car;
class Crossroads;
class Block;


enum direction { u, l, r, d, n, tl, tr, bl, br };  //normal, up, down, left, right, top-left, top-right, bottom-left, bottom-right
//Te bottom i top na koñcu s¹ do obs³ugi naro¿ników, cudowny enum s³u¿y do wszystkiego co zwi¹zanego z kierunkami
using namespace std;
using namespace sf;


class City
{
	int numberOfCars, blockWidth, size, numberOfBlocks; //Iloœæ bloków w rzêdzie
	vector<Car*> vecCars;
	vector<Crossroads*> vecCrossroads;
	vector<Block*> vecBlocks;
	vector <vector<int>> map; //To jest tylko pomocnicze, ¿eby mi by³o ³atwiej autka porozmieszczaæ 

public:
	City(); //Konstruktor z coutami
	City(int nOC, int nOB, int bW); //Konatruktor bez tych cout 
	void Initialize(); //Inicjalizuje miasto, wpisuje wszyskie te rzeczy do wektorków itd.
	void Simulate(); //W³aœciwa graficzna symulacja
	void checkCrossroads(); //sprawdzaco wjecha³o na skrzy¿owania

};

class GraphicObject:public sf::Drawable
{
	
public:
	RectangleShape rect;
	virtual void setShape() = 0;
	int x, y;   //wspó³rzêdne lewego górnego rogu, w przypadku auta wspó³rzêdne auta
};

class Car : public GraphicObject
{
	
public:
	void newDirection(direction from,direction crossType);
	direction direct;
	Car(int i, int j, direction dir);
	void setShape();
	bool onCrossroad=0;
	void draw(RenderTarget & target, RenderStates state) const override;
	void move();
	void Car::refresh(); //takie cudo, powinno byæ odpalane po ka¿dym ruchu aut, zmienia im siê pozycja x,y ale wektor od kwadrata nie jest aktualizowany


};

class Block: public GraphicObject
{
	int size;

public:
	void setShape();
	void draw(RenderTarget & target, RenderStates state) const override;
	Block(int i,int j,int width);
};

class Crossroads 
{
	Car *tl, *bl, *tr, *br;			//Œrodek Skrzy¿owania
	Car *inu, *ind, *inl, *inr;		//Wjazdy

public:
	direction type;
	int x, y;
	void CheckCrossroad(Car* c);
	Crossroads(int i,int j, direction typ);
	void movement();


};