#include "cell.h"
Cell::Cell():cellID(0) {
	loc_x = 0;
	loc_y = 0;
	cage_id = -1;
}

void Cell::SetCageID(int n)
{
	cage_id = n;
}

Cell::Cell(int x, int y, int ID):cellID(ID)
{
	loc_x = x;
	loc_y = y;
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

void Cell::Render() {
	cout << code;
}

int Cell::GetCageID()
{
	return cage_id;
}

int Cell::GetCellID()
{
	return cellID;
}

int Cell::GetLocationX(){
	return (loc_x);
}

int Cell::GetLocationY(){
	return (loc_y);
}
