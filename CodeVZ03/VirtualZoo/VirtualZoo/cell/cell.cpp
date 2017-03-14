#include "cell.h"
Cell::Cell() {
	cellID = 0;
	locX = 0;
	locY = 0;
	code = 0;
	cageID = -1;
}

void Cell::setCode(char c) {
	code = c;
}

void Cell::render() {
	cout << code;
}

int Cell::getCellID()
{
	return cellID;
}

int Cell::getLocationX() {
	return (locX);
}

int Cell::getLocationY() {
	return (locY);
}