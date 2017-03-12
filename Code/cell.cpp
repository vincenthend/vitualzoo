#include "cell.h"
Cell::Cell() {
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
