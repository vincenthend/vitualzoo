#include "habitat.h"

LandHabitat::LandHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 11;
	Cell::setCode(defaultCode);
}

LandHabitat::LandHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 11;
	Cell::setCode(defaultCode);
}

WaterHabitat::WaterHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 13;
	Cell::setCode(defaultCode);
}

WaterHabitat::WaterHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 13;
	Cell::setCode(defaultCode);
}

AirHabitat::AirHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 12;
	Cell::setCode(defaultCode);
}

AirHabitat::AirHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 12;
	Cell::setCode(defaultCode);
}

void AirHabitat::render()
{
	cout << "A";
}

void Habitat::setCageID(int n)
{
	cageID = n;
}

int Habitat::getCageID()
{
	return cageID;
}
