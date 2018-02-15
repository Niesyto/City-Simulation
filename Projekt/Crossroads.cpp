#include "Classes.hpp"
#include <vector>
#include <iostream>


Crossroads::Crossroads(int i, int j, direction typ)
{
	x = i;
	y = j;
	type = typ;
}

void Crossroads::CheckCrossroad(Car* c)
{
	//Sprawdza wjazdy na skrzy¿owania, szalone ale najwyraŸniej dzia³a
	if (type == n)
	{
		if (c->x == x && c->y == y - 1)
		{
			//górny wjazd
			c->onCrossroad = true;
			inu = c;
		}
		else if (c->x == x - 1 && c->y == y + 1)
		{
			//lewy
			c->onCrossroad = true;
			inl = c;
		}
		else if (c->x == x + 2 && c->y == y)
		{
			//prawy
			c->onCrossroad = true;
			inr = c;
		}
		else if (c->x == x + 1 && c->y == y + 2)
		{
			//dolny
			c->onCrossroad = true;
			ind = c;
		}
	}
	else if (type == u)
		{
		   if (c->x == x - 1 && c->y == y + 1)
			{
				//lewy
				c->onCrossroad = true;
				inl = c;
			}
			else if (c->x == x + 2 && c->y == y)
			{
				//prawy
				c->onCrossroad = true;
				inr = c;
			}
			else if (c->x == x + 1 && c->y == y + 2)
			{
				//dolny
				c->onCrossroad = true;
				ind = c;
			}
		}
	else if (type == l)
	{
		if (c->x == x && c->y == y - 1)
		{
			//górny wjazd
			c->onCrossroad = true;
			inu = c;
		}
		else if (c->x == x + 2 && c->y == y)
		{
			//prawy
			c->onCrossroad = true;
			inr = c;
		}
		else if (c->x == x + 1 && c->y == y + 2)
		{
			//dolny
			c->onCrossroad = true;
			ind = c;
		}
	}
	else if (type == r)
	{
		if (c->x == x && c->y == y - 1)
		{
			//górny wjazd
			c->onCrossroad = true;
			inu = c;
		}
		else if (c->x == x - 1 && c->y == y + 1)
		{
			//lewy
			c->onCrossroad = true;
			inl = c;
		}
		else if (c->x == x + 1 && c->y == y + 2)
		{
			//dolny
			c->onCrossroad = true;
			ind = c;
		}
	}
	else if (type == d)
	{
		if (c->x == x && c->y == y - 1)
		{
			//górny wjazd
			c->onCrossroad = true;
			inu = c;
		}
		else if (c->x == x - 1 && c->y == y + 1)
		{
			//lewy
			c->onCrossroad = true;
			inl = c;
		}
		else if (c->x == x + 2 && c->y == y)
		{
			//prawy
			c->onCrossroad = true;
			inr = c;
		}
	}
	else if (type == 5)
	{
		if (c->x == x + 2 && c->y == y)
		{
			//prawy
			c->onCrossroad = true;
			inr = c;
		}
		else if (c->x == x + 1 && c->y == y + 2)
		{
			//dolny
			c->onCrossroad = true;
			ind = c;
		}
	}
	else if (type == 6)
	{
		if (c->x == x - 1 && c->y == y + 1)
		{
			//lewy
			c->onCrossroad = true;
			inl = c;
		}
		else if (c->x == x + 1 && c->y == y + 2)
		{
			//dolny
			c->onCrossroad = true;
			ind = c;
		}
	}
	else if (type == 7)
	{
		if (c->x == x && c->y == y - 1)
		{
			//górny wjazd
			c->onCrossroad = true;
			inu = c;
		}
		else if (c->x == x + 2 && c->y == y)
		{
			//prawy
			c->onCrossroad = true;
			inr = c;
		}
	}
	else if (type == 8)
	{
		if (c->x == x && c->y == y - 1)
		{
			//górny wjazd
			c->onCrossroad = true;
			inu = c;
		}
		else if (c->x == x - 1 && c->y == y + 1)
		{
			//lewy
			c->onCrossroad = true;
			inl = c;
		}
	}
}

void Crossroads::movement()
{
	if (bl)
	{
		if (bl->direct == d)
		{
			bl->y++;
			bl->direct = d;
			bl->onCrossroad = false;
			bl = nullptr;

		}
		else if (bl->direct == r)
		{
			if (!br && !ind)
			{
				bl->x++;
				br = bl;
				bl = nullptr;
			}
		}
		else if (bl->direct == u)
		{
			if (!br && !ind && !inr)
			{
				bl->x++;
				br = bl;
				bl = nullptr;
			}
		}

	}

	if (br)
	{
		if (br->direct == u)
		{
			if (!tr && !inr)
			{
				br->y--;
				tr = br;
				br = nullptr;
			}
		}
		else if (br->direct == r)
		{
			br->x++;
			br->direct = r;
			br->onCrossroad = false;
			br = nullptr;

		}
		else if (br->direct == l)
		{
			if (!tr && !inr && !inu)
			{
				br->y--;
				tr = br;
				br = nullptr;
			}
		}
	}

	if (tl)
	{
		if (tl->direct == l)
		{
			tl->x--;
			tl->direct = l;
			tl->onCrossroad = false;
			tl = nullptr;
		}
		else if (tl->direct == r)
		{
			if (!inl && !bl && !ind)
			{
				tl->y++;
				bl = tl;
				tl = nullptr;
			}
		}
		else if (tl->direct == d)
		{
			if (!inl && !bl)
			{
				tl->y++;
				bl = tl;
				tl = nullptr;
			}
		}
	}

	if (tr)
	{
		if (tr->direct == d)
		{
			if (!inu && !inl && !tl)
			{
				tr->x--;
				tl = tr;
				tr = nullptr;
			}
		}
		else if (tr->direct == l)
		{
			if (!tl && !inu)
			{
				tr->x--;
				tl = tr;
				tr = nullptr;
			}
		}
		else if (tr->direct == u)
		{
			tr->y--;
			tr->direct = u;
			tr->onCrossroad = false;
			tr = nullptr;
		}

	}



	if (inu)
	{
		inu->newDirection(u, type);
		if (!tl)
		{
			inu->y++;
			tl = inu;
			inu = nullptr;
		}
	}
	else if (inl)
	{
		inl->newDirection(l, type);
		if (!bl)
		{
			inl->x++;
			bl = inl;
			inl = nullptr;
		}
	}
	else if (inr)
	{
		inr->newDirection(r, type);
		if (!tr)
		{
			inr->x--;
			tr = inr;
			inr = nullptr;
		}
	}
	else if (ind)
	{
		ind->newDirection(d, type);
		if (!br)
		{
			ind->y--;
			br = ind;
			ind = nullptr;
		}
	}
}


