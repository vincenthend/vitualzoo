#include "habitat.h"

landHabitat::landHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 11;
}

landHabitat::landHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 11;
}

void landHabitat::Render()
{
	cout << "L";
}

airHabitat::airHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 12;
}

airHabitat::airHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 12;
}

void airHabitat::Render()
{
	cout << "A";
}

waterHabitat::landHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 13;
}

waterHabitat::landHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 13;
}

void waterHabitat::Render()
{
	cout << "W";
}
