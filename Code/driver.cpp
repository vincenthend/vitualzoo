#include "driver.h"
#include <time.h>
#include <random>

Driver::Driver(int w, int h):Z(w,h)
{

}

void Driver::initZoo()
{
	Cell* C[5]; //Temporary storage

	C[0] = new Road();
	C[1] = new WaterHabitat();
	C[2] = new Resto();
	C[3] = new Park();
	C[4] = new Park();

	Z.addCell(0, 0, C[0]);
	Z.addCell(0, 1, C[1]);
	Z.addCell(1, 0, C[2]);
	Z.addCell(1, 1, C[3]);
	Z.addCell(1, 2, C[4]);
}

void Driver::startTour()
{
	int i, j, Tx[10], Ty[10], Tc, move, Tmove[4], cmove;
	Cell *C;
	Animal * A;
	Tc = 0;
	C = Z.getCell(0, 0); //Visstud error without this
	
	ClearScreen();
	printZoo();
	//printLegend();

	srand((unsigned int)time(NULL));
	for (i = 0; i < Z.getWidth(); i++) {
		for (j = 0; j < Z.getHeight(); j++) {
			C = Z.getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() == 210) {
					Tx[Tc] = i;
					Ty[Tc] = j;
					Tc++;
				}
			}
		}
	}
	move = 0;
	while (C->getCageID() != 211){
		//Random entrance yang dipake, simpen  x y di i j
		if (((j - 1) >= 0) && (move != 1)){
			C = Z.getCell(i, j - 1);
			if ((C->getCageID() >= 11) && (C->getCageID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z.getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		if (((i + 1) >= 0) && (move != 2)){
			C = Z.getCell(i + 1, j);
			if ((C->getCageID() >= 11) && (C->getCageID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z.getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		if (((j + 1) >= 0) && (move != 3)){
			C = Z.getCell(i, j + 1);
			if ((C->getCageID() >= 11) && (C->getCageID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z.getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		if (((i - 1) >= 0) && (move != 4)){
			C = Z.getCell(i - 1, j);
			if ((C->getCageID() >= 11) && (C->getCageID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z.getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		/*Metode gerak: 
		atas (y - 1): 1
		kanan (x + 1): 2
		bawah (y + 1): 3
		kiri (x - 1): 4
		*/
		cmove = 0;
		if (((j - 1) >= 0) && (move != 1)){
			C = Z.getCell(i, j - 1);
			if (C->getCellID() == 21){
				Tmove[cmove] = 1;
				cmove++;
			}
		}
		if (((i + 1) >= 0) && (move != 2)){
			C = Z.getCell(i + 1, j);
			if (C->getCellID() == 21){
				Tmove[cmove] = 2;
				cmove++;
			}
		}
		if (((j + 1) >= 0) && (move != 3)){
			C = Z.getCell(i, j + 1);
			if (C->getCellID() == 21){
				Tmove[cmove] = 3;
				cmove++;
			}
		}
		if (((i - 1) >= 0) && (move != 4)){
			C = Z.getCell(i - 1, j);
			if (C->getCellID() == 21){
				Tmove[cmove] = 4;
				cmove++;
			}
		}
		//Random jalan yang mungkin pake mod cmove, simpen di move
		move = (rand() % 4) + 1;

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

void Driver::printStatus()
{
	cout << "========================================" << endl;
	cout << "              - Food Count -" << endl;
	cout << "   Herbivore : " << Z.CountFoodHerbivore() << endl;
	cout << "   Carnivore : " << Z.CountFoodCarnivore() << endl;
	cout << "   Omnivore  : " << Z.CountFoodOmnivore() << endl;
	cout << "========================================" << endl;
}
