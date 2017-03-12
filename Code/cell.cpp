#include "cell.h"

Cell::Cell()
{
	locX = 0;
	locY = 0;
	cellID = 0;
}

Cell::Cell(int x, int y, int ID)
{
	locX = x;
	locY = y;
	cellID = ID;
}
