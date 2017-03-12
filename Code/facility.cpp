#include "facility.h"

Road::Road()
{
	locX = 0;
	locY = 0;
	cellID = 21;
	type = 0;
}

Road::Road(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 21;
	type = 0;
}

Road::Road(int x, int y, int type)
{
	locX = x;
	locY = y;
	cellID = 21;
	this->type = type;
}

void Road::Render()
{
	cout << "X";
}

Resto::Resto()
{
	locX = 0;
	locY = 0;
	cellID = 22;
}

Resto::Resto(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 22;
}

void Resto::Render()
{
	cout << "R";
}

Park::Park()
{
	locX = 0;
	locY = 0;
	cellID = 23;
}

Park::Park(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 23;
}

void Park::Render()
{
	cout << "P";
}
