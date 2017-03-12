#include "driver.h"
#include <random>
#include <time.h>

Driver::Driver(int w, int h):Z(w,h)
{

}

void Driver::initZoo()
{
	Cell* C[4]; //Temporary storage

	C[0] = new Road();
	C[1] = new WaterHabitat();
	C[2] = new Resto();
	C[3] = new Park();

	Z.addCell(0, 0, C[0]);
	Z.addCell(0, 1, C[1]);
	Z.addCell(1, 0, C[2]);
	Z.addCell(1, 1, C[3]);
}

void Driver::startTour()
{
	srand(time(NULL));
	int i, j, Tx[10], Ty[10], Tc, move, Tmove[4], cmove;
	Cell *C;
	Tc = 0;
	for (i = 0; i < Z.getWidth(); i++) {
		for (j = 0; j < Z.getHeight(); j++) {
			C = Z.getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() == /*entranceID*/) {
					Tx[Tc] = i;
					Ty[Tc] = j;
					Tc++;
				}
			}
		}
	}
	move = 0;
	while (C->getCageID() != /*exitID*/){
		//Random entrance yang dipake, simpen  x y di i j
		interactSurrounding(i, j);//Interact sekitar dia
		/*Metode gerak: 
		atas (y - 1): 1
		kanan (x + 1): 2
		bawah (y + 1): 3
		kiri (x - 1): 4
		*/
		cmove = 0;
		if (((j - 1) >= 0) && (move != 1)){
			Tmove[cmove] = 1;
			cmove++;
		}
		if (((i + 1) >= 0) && (move != 2)){
			Tmove[cmove] = 2;
			cmove++;
		}
		if (((j + 1) >= 0) && (move != 3)){
			Tmove[cmove] = 3;
			cmove++;
		}
		if (((i - 1) >= 0) && (move != 4)){
			Tmove[cmove] = 4;
			cmove++;
		}

		move == (rand() % 4) + 1;

		//Random jalan yang mungkin pake mod cmove, simpen di move
		if (move == 1) {
			j--;
		}
		else {
			if (move == 2) {
				i++;
			}
			else {
				if (move == 3) {
					j++;
				}
				else {
					i--;
				}
			}
		}
		C = Z.getCell(i, j);
	}
	cout << "Tur selesai :D" << endl;
}

void Driver::printZoo()
{
	int i, j;
	Cell* C;
	Animal* A;

	for (i = 0; i < Z.getWidth(); i++) {
		cout << "|";
		for (j = 0; j < Z.getHeight(); j++) {
			C = Z.getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() > -1) {
					A = Z.getCage(C->getCageID())->isSpaceOccupied(i, j);
					if (A != NULL) {
						A->render();
					}
				}
				else {
					C->render();
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
	Animal* A;

	for (i = x1; i <= y1; i++) {
		cout << "|";
		for (j = x2; j <= y2; j++) {
			C = Z.getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() > -1) {
					A = Z.getCage(C->getCageID())->isSpaceOccupied(i, j);
					if (A != NULL) {
						A->render();
					}
				}
				else {
					C->render();
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
