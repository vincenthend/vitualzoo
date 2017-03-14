#include "driver.h"
#include <time.h>
#include <random>

Driver::Driver(string Input)
{
	cout << "Ceks 1" << endl;
	Cell* C;
	ifstream myfile(Input);
	string S;
	int i, j, k, w, h, temp, aid, acount;
	bool found;
	Animal* A;

	getline(myfile,S);
	i = 0;
	temp = 0;
	C = NULL;
	while ((S[i] >= '0') && (S[i] <= '9')) {
		temp = (temp * 10) + (S[i] - '0');
		i++;
	}
	h = temp;
	getline(myfile,S);
	i = 0;
	temp = 0;
	while ((S[i] >= '0') && (S[i] <= '9')) {
		temp = (temp * 10) + (S[i] - '0');
		i++;
	}
	w = temp;
	Z = new Zoo(w, h);
	for (i = 0; i < Z->getHeight(); i++) {
		getline(myfile, S);
		for (j = 0; j <= Z->getWidth(); j++) {
			if (S[j] == 'L'){
				C = new Cell(i, j, 11);
			}
			else {
				if (S[j] == 'W'){
					C = new Cell(i, j, 12);
				}
				else {
					if (S[j] == 'A'){
						C = new Cell(i, j, 13);
					}
					else {
						if (S[j] == 'S'){
							C = new Cell(i, j, 210);
						}
						else {
							if (S[j] == 'F'){
								C = new Cell(i, j, 211);
							}
							else {
								if (S[j] == 'X'){
									C = new Cell(i, j, 21);
								}
								else {
									if (S[j] == 'R'){
										C = new Cell(i, j, 22);
									}
									else {
										if (S[j] == 'P'){
											C = new Cell(i, j, 23);
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
	for (i = 0; i < Z->getHeight(); i++) {
		for (j = 0; j <= Z->getWidth(); j++) {
			found = false;
			C = Z->getCell(i, j);
			if (((j - 1) >= 0) && (!(found))) {
				if (((Z->getCell(i, j)->getCellID()) == (Z->getCell(i, j - 1)->getCellID()))) {
					Z->getCage(Z->getCell(i, j - 1)->getCageID())->addHabitat(Z->getCell(i, j));
					found = true;
				}
			}
			if (((i - 1) >= 0) && (!(found))) {
				if (((Z->getCell(i, j)->getCellID()) == (Z->getCell(i - 1, j)->getCellID()))) {
					Z->getCage(Z->getCell(i - 1, j)->getCageID())->addHabitat(Z->getCell(i, j));
					found = true;
				}
			}
			if (!(found)){
				Z->addCage();
				Z->getCage(Z->getNCage()-1)->addHabitat(Z->getCell(i, j));
			}
		}
	}
	getline(myfile,S);
	i = 0;
	temp = 0;
	while ((S[i] >= '0') && (S[i] <= '9')) {
		temp = (temp * 10) + (S[i] - '0');
		i++;
	}
	for (i = 0; i < temp; i++) {
		getline(myfile,S);
		cout << "String S = " << S << endl;
		aid = 0;
		j = 0;
		while ((S[j] >= '0') && (S[j] <= '9')) {
			aid = (aid * 10) + (S[j] - '0');
			j++;
		}
		j++;
		acount = 0;
		while ((S[j] >= '0') && (S[j] <= '9')) {
			acount = (acount * 10) + (S[j] - '0');
			j++;
		}
		cout << "Animal " << aid << " ada " << acount << endl; /*TBD*/
		//getchar();
		for (j = 0; j < acount; j++) {
			cout << "Cek" << endl;
			A = new Animal(aid);
			found = false;
			k = 0;
			cout << "Cek 1" << endl;
			while ((!(found)) && (k < Z->getNCage())) {
				cout << "Cek 1.1" << endl;
				if ((A->getHabitat()[(((Z->getCage(k))->getCageType()) % 10) - 1]) && (Z->getCage(k)->IsFull())) {
					found = true;
					cout << "Cek 1.2" << endl;
					(Z->getCage(k))->addAnimal(A);
					cout << "Cek 1.3" << endl;
				}
				cout << "Cek 1.4" << endl;
				k++;
			}
		}
	}
	myfile.close();
}

void Driver::printMenu()
{
	int choice, x1, y1, x2, y2;

	choice = 0;
	do {
		
		cout << "=========================================" << endl;
		cout << "|               VIRTUAL ZOO             |" << endl;
		cout << "=========================================" << endl;
		cout << "Menu :" << endl << "1. Tampilkan Zoo" << endl << "2. Mulai Tour";
		cout << endl << "9. Keluar" << endl << "Pilihan : ";
		cin >> choice;


		if (choice == 1) {
			ClearScreen();
			do {				
				cout << "=========================================" << endl;
				cout << "|               VIRTUAL ZOO             |" << endl;
				cout << "=========================================" << endl;
				cout << "1. Tampilkan seluruhnya" << endl << "2. Tampilkan sebagian";
				cout << endl << "9. Keluar" << endl << "Pilihan : ";
				cin >> choice;
				if (choice == 1) {
					ClearScreen();
					printZoo();
				}
				else if (choice == 2) {
					ClearScreen();
					cout << "Masukkan ukuran" << endl;
					cout << "X(0 - " << Z->getWidth() - 1 <<")"<<endl;
					cout << "Y(0 - " << Z->getHeight() - 1 << ")"<<endl;
					cout << "X1 :";
					cin >> x1;
					cout << "Y1 :";
					cin >> y1;
					cout << "X2 :";
					cin >> x2;
					cout << "Y2 :";
					cin >> y2;
					printZoo(x1, y1, x2, y2);
					cout << endl;
				}
			} while (choice != 9);
		}
		else if (choice == 2) {
			startTour();
			ClearScreen();
		}

	} while (choice != 9);
}

void Driver::startTour()
{
	int i, j, Tx[10], Ty[10], Tc, move, Tmove[4], cmove;
	int temp;
	Cell *C;
	Animal * A;
	Tc = 0;
	C = Z->getCell(0, 0); //Visstud error without this
	
	ClearScreen();
	printZoo();
	printStatus();

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
	//Random entrance yang dipake, simpen  x y di i j
	temp = (rand() % (Tc));
	i = Tx[temp];
	j = Ty[temp];

	while (C->getCellID() != 211) {

		//Print Zoo
		ClearScreen();
		printZoo(j,i);
		printStatus();

		cout << "(" << i << "," << j << ")" << C->getCellID()<< endl;
		//Interact
		if (((j - 1) >= 0) && (move != 3)) {
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
		if (((i + 1) < Z->getHeight()) && (move != 4)) {
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
		if (((j + 1) < Z->getWidth()) && (move != 1)) {
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
		if (((i - 1) >= 0) && (move != 2)) {
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
		atas (x - 1): 1
		kanan (y + 1): 2
		bawah (x + 1): 3
		kiri (y - 1): 4
		*/
		cmove = 0;
		if (((j - 1) >= 0) && (move != 3)){
			C = Z->getCell(i, j - 1);
			if (C->getCellID() == 21 || C->getCellID() == 211 ){
				Tmove[cmove] = 1;
				cmove++;
			}
		}
		if (((i + 1) < Z->getHeight()) && (move != 4)){
			C = Z->getCell(i + 1, j);
			if (C->getCellID() == 21 || C->getCellID() == 211){
				Tmove[cmove] = 2;
				cmove++;
			}
		}
		if (((j + 1) < Z->getWidth()) && (move != 1)){
			C = Z->getCell(i, j + 1);
			if (C->getCellID() == 21 || C->getCellID() == 211){
				Tmove[cmove] = 3;
				cmove++;
			}
		}
		if (((i - 1) >= 0) && (move != 2)){
			C = Z->getCell(i - 1, j);
			if (C->getCellID() == 21 || C->getCellID() == 211){
				Tmove[cmove] = 4;
				cmove++;
			}
		}
		//Random jalan yang mungkin pake mod cmove, simpen di move
		if (cmove > 0) {
			move = Tmove[(rand() % cmove)];
		}
		else {
			move = (move + 2) % 4;
		}

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
		Delay(500);
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
					else {
						C->render();
					}
				}
				else {
					C->render();
				}
			}
			else {
				cout << "?";
			}
			cout << "|";
		}
		cout << endl;
	}
}

void Driver::printZoo(int x, int y)
{
	int i, j;
	Cell* C;
	Animal* A;

	for (i = 0; i < Z->getWidth(); i++) {
		cout << "|";
		for (j = 0; j < Z->getHeight(); j++) {
			if (x == j && y == i) {
				cout << "X";
			}
			else {
				C = Z->getCell(i, j);
				if (C != NULL) {
					if (C->getCageID() > -1) {
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
						if (A != NULL) {
							A->render();
						}
						else {
							C->render();
						}
					}
					else {
						C->render();
					}
				}
				else {
					cout << "?";
				}
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

	for (i = y1; i <= y2; i++) {
		cout << "|";
		for (j = x1; j <= x2; j++) {
			C = Z->getCell(i, j);
			if (C != NULL) {
				if (C->getCageID() > -1) {
					A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j);
					if (A != NULL) {
						A->render();
					}
					else {
						C->render();
					}
				}
				else {
					C->render();
				}
			}
			else {
				cout << "?";
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
