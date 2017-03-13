#include "cell.h"
Cell::Cell():cellID(0) {
	locX = 0;
	locY = 0;
	cageID = -1;
}

void Cell::setCageID(int n)
{
	cageID = n;
}

Cell::Cell(int x, int y, int ID):cellID(ID)
{
	locX = x;
	locY = y;
	if (cellID == 11) {
		code = 'L'; //Code Land Habitat
	}
	else if (cellID == 12) {
		code = 'A'; //Code Air Habitat
	}
	else if (cellID == 13) {
		code = 'W'; //Code Water Habitat
	}
	else if (cellID == 21 || cellID == 210 || cellID == 211) {
		code = ' '; //Code Road
	}
	else if (cellID == 22) {
		code = 'R'; //Code Resto
	}
	else if (cellID == 23) {
		code = 'P'; //Code Park
	}
}

void Cell::render() {
	cout << code;
}

int Cell::getCageID()
{
	return cageID;
}

int Cell::getCellID()
{
	return cellID;
}
