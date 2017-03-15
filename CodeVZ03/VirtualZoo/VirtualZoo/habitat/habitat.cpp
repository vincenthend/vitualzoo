#include "habitat.h"

LandHabitat::LandHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 11;
	Cell::SetCode(default_code);
}

LandHabitat::LandHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 11;
	Cell::SetCode(default_code);
}

WaterHabitat::WaterHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 13;
	Cell::SetCode(default_code);
}

WaterHabitat::WaterHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 13;
	Cell::SetCode(default_code);
}

AirHabitat::AirHabitat()
{
	locX = 0;
	locY = 0;
	cellID = 12;
	Cell::SetCode(default_code);
}

AirHabitat::AirHabitat(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 12;
	Cell::SetCode(default_code);
}

void AirHabitat::Render()
{
	cout << "A";
}

void Habitat::SetCageID(int n)
{
	cageID = n;
}

int Habitat::GetCageID()
{
	return cageID;
}
