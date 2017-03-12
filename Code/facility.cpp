#include "facility.h"

Road::Road()
{
	locX = 0;
	locY = 0;
	cellID = 21;
	type = 0;
	Cell::setCode(defaultCode);
}

Road::Road(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 21;
	type = 0;
	Cell::setCode(defaultCode);
}

Road::Road(int x, int y, bool isEntrance)
{	
	locX = x;
	locY = y;

	if (isEntrance) {
		type = 210;
	}
	else {
		type = 211;
	}
	Cell::setCode(defaultCode);
}

Resto::Resto()
{
	locX = 0;
	locY = 0;
	cellID = 22;
	Cell::setCode(defaultCode);
}

Resto::Resto(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 22;
	Cell::setCode(defaultCode);
}

Park::Park()
{
	locX = 0;
	locY = 0;
	cellID = 23;
	Cell::setCode(defaultCode);
}

Park::Park(int x, int y)
{
	locX = x;
	locY = y;
	cellID = 23;
	Cell::setCode(defaultCode);
}

void Facility::setCageID(int n)
{
	cageID = n;
}

int Facility::getCageID()
{
	return cageID;
}
