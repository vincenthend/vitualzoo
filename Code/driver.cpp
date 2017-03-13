#include "driver.h"
#include <time.h>
#include <random>

Driver::Driver(string Input)
{
	Cell* C;
	ifstream myfile(Input);
	string S;
	int i, j, w, h, temp;
	getline(myfile,S);
	i = 0;
	cout << S[i] << endl;
	while ((S[i] >= '0') && (S[i] <= '9')) {
		cout << i << endl;
		temp = (temp * 10) + (S[i] - '0');
		i++;
	}
	h = temp;
	getline(myfile,S);
	i = 0;
	while ((S[i] >= '0') && (S[i] <= '9')) {
		temp = (temp * 10) + (S[i] - '0');
		i++;
	}
	w = temp;
	Z = new Zoo(w, h);
	for (i = 0; i < Z->getHeight(); i++) {
		for (j = 0; j <= Z->getWidth(); j++) {
			cout << "Cek " << i << "," << j << endl;
			getline(myfile,S);
			if (S[j] == 'L'){
				C = new LandHabitat(i, j);
			}
			else {
				if (S[j] == 'W'){
					C = new WaterHabitat(i, j);
				}
				else {
					if (S[j] == 'A'){
						C = new AirHabitat(i, j);
					}
					else {
						if (S[j] == 'S'){
							C = new Road(i, j, true);
						}
						else {
							if (S[j] == 'F'){
								C = new Road(i, j, false);
							}
							else {
								if (S[j] == 'X'){
									C = new Road(i, j);
								}
								else {
									if (S[j] == 'R'){
										C = new Resto(i, j);
									}
									else {
										if (S[j] == 'P'){
											C = new Park(i, j);
										}
									}
								}
							}
						}
					}
				}
			}
			Z->addCell(i, j, C);
		}
	}
}

Driver::~Driver() {
	delete Z;
}

void Driver::startTour()
{
	int i, j, Tx[10], Ty[10], Tc, move, Tmove[4], cmove;
	Cell *C;
	Animal * A;
	Tc = 0;
	C = Z->getCell(0, 0); //Visstud error without this
	
	ClearScreen();
	printZoo();
	//printLegend();

	srand((unsigned int)time(NULL));
	for (i = 0; i < Z->getWidth(); i++) {
		for (j = 0; j < Z->getHeight(); j++) {
			C = Z->getCell(i, j);
			if (C != NULL) {
				if (C->getCellID() == 210) {
					Tx[Tc] = i;
					Ty[Tc] = j;
					Tc++;
				}
			}
		}
	}
	move = 0;
	while (C->getCellID() != 211){
		//Random entrance yang dipake, simpen  x y di i j
		Tc = rand() % (Tc);
		i = Tx[Tc];
		j = Ty[Tc];
		if (((j - 1) >= 0) && (move != 1)){
			C = Z->getCell(i, j - 1);
			if ((C->getCellID() >= 11) && (C->getCellID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		if (((i + 1) < Z->getHeight()) && (move != 2)) {
			C = Z->getCell(i + 1, j);
			if ((C->getCellID() >= 11) && (C->getCellID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		if (((j + 1) < Z->getWidth()) && (move != 3)) {
			C = Z->getCell(i, j + 1);
			if ((C->getCellID() >= 11) && (C->getCellID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->interact();
						}
					}
				}
			}
		}
		if (((i - 1) >= 0) && (move != 4)){
			C = Z->getCell(i - 1, j);
			if ((C->getCellID() >= 11) && (C->getCellID() <= 13)) {
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
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
			C = Z->getCell(i, j - 1);
			if (C->getCellID() == 21){
				Tmove[cmove] = 1;
				cmove++;
			}
		}
		if (((i + 1) < Z->getHeight()) && (move != 2)){
			C = Z->getCell(i + 1, j);
			if (C->getCellID() == 21){
				Tmove[cmove] = 2;
				cmove++;
			}
		}
		if (((j + 1) <= Z->getWidth()) && (move != 3)){
			C = Z->getCell(i, j + 1);
			if (C->getCellID() == 21){
				Tmove[cmove] = 3;
				cmove++;
			}
		}
		if (((i - 1) >= 0) && (move != 4)){
			C = Z->getCell(i - 1, j);
			if (C->getCellID() == 21){
				Tmove[cmove] = 4;
				cmove++;
			}
		}
		//Random jalan yang mungkin pake mod cmove, simpen di move
		move = Tmove[(rand() % cmove) + 1];

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
		C = Z->getCell(i, j);
	}
	cout << "Tur selesai :D" << endl;
}

void Driver::printZoo()
{
	int i, j;
	Cell* C;
	Animal* A;

	for (i = 0; i < Z->getWidth(); i++) {
		cout << "|";
		for (j = 0; j < Z->getHeight(); j++) {
			C = Z->getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() > -1) {
					A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
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
			C = Z->getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() > -1) {
					A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
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
	cout << "   Herbivore : " << Z->CountFoodHerbivore() << endl;
	cout << "   Carnivore : " << Z->CountFoodCarnivore() << endl;
	cout << "   Omnivore  : " << Z->CountFoodOmnivore() << endl;
	cout << "========================================" << endl;
}
