#include "driver.h"

Driver::Driver(int w, int h):Z(w,h)
{

}

void Driver::initZoo()
{
	Cell* C[4]; //Temporary storage

	C[0] = new Road();
	C[1] = new waterHabitat();
	C[2] = new Resto();
	C[3] = new Park();

	Z.addCell(0, 0, C[0]);
	Z.addCell(0, 1, C[1]);
	Z.addCell(1, 0, C[2]);
	Z.addCell(1, 1, C[3]);
}

void Driver::startTour()
{
}

void Driver::printZoo()
{
	int i, j;
	Cell* C;
	for (i = 0; i < Z.getWidth(); i++) {
		cout << "|";
		for (j = 0; j < Z.getHeight(); j++) {
			C = Z.getCell(i, j);
			if (C != NULL) {
				if (C->getCellID() == 11 || C->getCellID() == 12 || C->getCellID() == 13) {
					if (C->getCageID() > -1) {
					
					}
				}
				else {
					C->Render();
				}
			}
			else {
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
}

void Driver::printZoo(int x1, int y1, int x2, int y2)
{
	int i, j;
	Cell* C;
	for (i = x1; i < x2; i++) {
		cout << "|";
		for (j = y1; j < y2; j++) {
			C = Z.getCell(i, j);
			if (C != NULL) {
				C->Render();
			}
			else {
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
}
