#include "driver.h"
#include <time.h>
#include <random>
#include <string>

Driver::Driver(string Input)
{
	Cell* C;
	ifstream myfile(Input);
	string S;
	int i, j, k, w, h, temp, aid, acount;
	bool found;
	Animal* A;

	A = NULL;
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
		for (j = 0; j < Z->getWidth(); j++) {
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
	for (i = 0; i < Z->getHeight(); i++) {
		for (j = 0; j < Z->getWidth(); j++) {
			found = false;
			C = Z->getCell(i, j);
			if ((C->getCellID()>= 11) && (C->getCellID() <= 13)) {
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
				if (!(found)) {
					Z->addCage();
					Z->getCage(Z->getNCage() - 1)->addHabitat(Z->getCell(i, j));
				}
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
		k = 0;
		for (j = 0; j < acount; j++) {
			//NEW ANIMAL
			if (aid == 1) {
				A = new Pelican;
			}
			else if (aid == 2) {
				A = new Owl;
			}
			else if (aid == 3) {
				A = new Pigeon;
			}
			else if (aid == 4) {
				A = new Canary;
			}
			else if (aid == 5) {
				A = new Bat;
			}
			else if (aid == 6) {
				A = new Eagle;
			}
			else if (aid == 7) {
				A = new Toucan;
			}
			else if (aid == 8) {
				A = new Chicken;
			}
			else if (aid == 9) {
				A = new Cat;
			}
			else if (aid == 10) {
				A = new Cow;
			}
			else if (aid == 11) {
				A = new Mouse;
			}
			else if (aid == 12) {
				A = new Goat;
			}
			else if (aid == 13) {
				A = new Llama;
			}
			else if (aid == 14) {
				A = new Snake;
			}
			else if (aid == 15) {
				A = new Sheep;
			}
			else if (aid == 16) {
				A = new Chameleon;
			}
			else if (aid == 17) {
				A = new Salmon;
			}
			else if (aid == 18) {
				A = new Whale;
			}
			else if (aid == 19) {
				A = new Squid;
			}
			else if (aid == 20) {
				A = new Goldfish;
			}
			else if (aid == 21) {
				A = new Turtle;
			}
			else if (aid == 22) {
				A = new Seal;
			}
			else if (aid == 23) {
				A = new Dolphin;
			}
			else if (aid == 24) {
				A = new Penguin;
			}
			
			found = false;
			while ((!(found)) && (k < Z->getNCage())) {
				if ((A->getHabitat()[(((Z->getCage(k))->getCageType()) % 10) - 1]) && !(Z->getCage(k)->IsFull())) {
					found = true;
					(Z->getCage(k))->addAnimal(A);
				}
				k++;
			}
		}
	}
	myfile.close();
}

Driver::~Driver()
{
	delete Z;
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
					printStatus();
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
			choice = 0;
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
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j-1);
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
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i+1, j);
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
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i, j+1);
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
						A = Z->getCage(C->getCageID())->isSpaceOccupied(i-1, j);
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
