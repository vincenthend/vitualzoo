#include "driver.h"
#include <time.h>
#include <random>
#include <string>

Driver::Driver(string Input)
{
	Cell* C;
	ifstream myfile(Input);
	string S;
	int i, j, k, l, w, h, temp, aid, acount;
	bool found, enemy;
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
	for (i = 0; i < Z->GetHeight(); i++) {
		getline(myfile, S);
		for (j = 0; j <= Z->GetWidth(); j++) {
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
			Z->AddCell(i, j, C);
		}
	}
	for (i = 0; i < Z->GetHeight(); i++) {
		for (j = 0; j < Z->GetWidth(); j++) {
			found = false;
			C = Z->GetCell(i, j);
			cout << "Cek " << (C->GetCellID()) << endl;
			if ((C->GetCellID()>= 11) && (C->GetCellID() <= 13)) {
				if (((j - 1) >= 0) && (!(found))) {
					if (((Z->GetCell(i, j)->GetCellID()) == (Z->GetCell(i, j - 1)->GetCellID()))) {
						Z->GetCage(Z->GetCell(i, j - 1)->GetCageID())->AddHabitat(Z->GetCell(i, j));
						found = true;
					}
				}
				if (((i - 1) >= 0) && (!(found))) {
					if (((Z->GetCell(i, j)->GetCellID()) == (Z->GetCell(i - 1, j)->GetCellID()))) {
						Z->GetCage(Z->GetCell(i - 1, j)->GetCageID())->AddHabitat(Z->GetCell(i, j));
						found = true;
					}
				}
				if (!(found)) {
					Z->AddCage();
					Z->GetCage(Z->GetNCage() - 1)->AddHabitat(Z->GetCell(i, j));
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
		k = 0;
		for (j = 0; j < acount; j++) {
			A = new Animal(aid);
			found = false;
			while ((!(found)) && (k < Z->GetNCage())) {
				if ((A->GetHabitat()[(((Z->GetCage(k))->GetCageType()) % 10) - 1]) && !(Z->GetCage(k)->IsFull())) {
					l = 0;
					enemy = false;
					while (l < A->GetCEnemy()){
						if (Z->GetCage(k)->IsExist(A->GetEnemyList()[l])){
							enemy = true;
						}
						l++;
					}
					if (!(enemy)){
						found = true;
						(Z->GetCage(k))->AddAnimal(A);
					}
				}
				k++;
			}
		}
	}
	myfile.close();
}

void Driver::PrintMenu()
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
					PrintZoo();
				}
				else if (choice == 2) {
					ClearScreen();
					cout << "Masukkan ukuran" << endl;
					cout << "X(0 - " << Z->GetWidth() - 1 <<")"<<endl;
					cout << "Y(0 - " << Z->GetHeight() - 1 << ")"<<endl;
					cout << "X1 :";
					cin >> x1;
					cout << "Y1 :";
					cin >> y1;
					cout << "X2 :";
					cin >> x2;
					cout << "Y2 :";
					cin >> y2;
					PrintZoo(x1, y1, x2, y2);
					cout << endl;
					
		choice = 0;
				}
			} while (choice != 9);
		}
		else if (choice == 2) {
			StartTour();
			ClearScreen();
		}

	} while (choice != 9);
}

void Driver::StartTour()
{
	int i, j, Tx[10], Ty[10], Tc, Move, TMove[4], cMove;
	int temp;
	Cell *C;
	Animal * A;
	bool walk = true;
	Tc = 0;
	C = Z->GetCell(0, 0); //Visstud error without this
	
	ClearScreen();
	PrintZoo();
	PrintZoo();

	srand((unsigned int)time(NULL));
	for (i = 0; i < Z->GetWidth(); i++) {
		for (j = 0; j < Z->GetHeight(); j++) {
			C = Z->GetCell(i, j);
			if (C != NULL) {
				if (C->GetCellID() == 210) {
					Tx[Tc] = i;
					Ty[Tc] = j;
					Tc++;
				}
			}
		}
	}
	Move = 0;
	//Random entrance yang dipake, simpen  x y di i j
	temp = (rand() % (Tc));
	i = Tx[temp];
	j = Ty[temp];

<<<<<<< HEAD
	while (C->GetCellID() != 211) {
=======
	while (C->getCellID() != 211 && walk) {
>>>>>>> a98f20e937916fdae2f4440129c5fe4e2fa2f88d
		//Print Zoo
		ClearScreen();
		PrintZoo(j,i);
		PrintZoo();

		cout << "(" << i << "," << j << ")" << C->GetCellID()<< endl;
		//Interact
		if (((j - 1) >= 0) && (Move != 3)) {
			C = Z->GetCell(i, j - 1);
			if ((C->GetCellID() >= 11) && (C->GetCellID() <= 13)) {
				if (C != NULL) {
					if (C->GetCageID() > -1) {
						A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i, j-1);
						if (A != NULL) {
							A->Interact();
						}
					}
				}
			}
		}
		if (((i + 1) < Z->GetHeight()) && (Move != 4)) {
			C = Z->GetCell(i + 1, j);
			if ((C->GetCellID() >= 11) && (C->GetCellID() <= 13)) {
				if (C != NULL) {
					if (C->GetCageID() > -1) {
						A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i+1, j);
						if (A != NULL) {
							A->Interact();
						}
					}
				}
			}
		}
		if (((j + 1) < Z->GetWidth()) && (Move != 1)) {
			C = Z->GetCell(i, j + 1);
			if ((C->GetCellID() >= 11) && (C->GetCellID() <= 13)) {
				if (C != NULL) {
					if (C->GetCageID() > -1) {
						A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i, j+1);
						if (A != NULL) {
							A->Interact();
						}
					}
				}
			}
		}
		if (((i - 1) >= 0) && (Move != 2)) {
			C = Z->GetCell(i - 1, j);
			if ((C->GetCellID() >= 11) && (C->GetCellID() <= 13)) {
				if (C != NULL) {
					if (C->GetCageID() > -1) {
						A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i-1, j);
						if (A != NULL) {
							A->Interact();
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
		cMove = 0;
		if (((j - 1) >= 0) && (Move != 3)){
			C = Z->GetCell(i, j - 1);
			if (C->GetCellID() == 21 || C->GetCellID() == 211 ){
				TMove[cMove] = 1;
				cMove++;
			}
		}
		if (((i + 1) < Z->GetHeight()) && (Move != 4)){
			C = Z->GetCell(i + 1, j);
			if (C->GetCellID() == 21 || C->GetCellID() == 211){
				TMove[cMove] = 2;
				cMove++;
			}
		}
		if (((j + 1) < Z->GetWidth()) && (Move != 1)){
			C = Z->GetCell(i, j + 1);
			if (C->GetCellID() == 21 || C->GetCellID() == 211){
				TMove[cMove] = 3;
				cMove++;
			}
		}
		if (((i - 1) >= 0) && (Move != 2)){
			C = Z->GetCell(i - 1, j);
			if (C->GetCellID() == 21 || C->GetCellID() == 211){
				TMove[cMove] = 4;
				cMove++;
			}
		}
<<<<<<< HEAD
		//Random jalan yang mungkin pake mod cMove, simpen di Move
		if (cMove > 0) {
			Move = TMove[(rand() % cMove)];
		}
		else {
			Move = (Move + 2) % 4;
		}

		if (Move == 1) {
			j--;
		}
		else {
			if (Move == 2) {
				i++;
			}
			else {
				if (Move == 3) {
					j++;
=======
		//Random jalan yang mungkin pake mod cmove, simpen di move
		if (cmove > 0) {
			move = Tmove[(rand() % cmove)];
			if (move == 1) {
				j--;
			}
			else {
				if (move == 2) {
					i++;
>>>>>>> a98f20e937916fdae2f4440129c5fe4e2fa2f88d
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
		}
<<<<<<< HEAD
		C = Z->GetCell(i, j);
=======
		else {
			walk = false;
		}

		
		C = Z->getCell(i, j);
>>>>>>> a98f20e937916fdae2f4440129c5fe4e2fa2f88d
		Delay(500);
	}
	cout << "Tur selesai :D" << endl;
}

void Driver::PrintZoo()
{
	int i, j;
	Cell* C;
	Animal* A;

	for (i = 0; i < Z->GetWidth(); i++) {
		cout << "|";
		for (j = 0; j < Z->GetHeight(); j++) {
			C = Z->GetCell(i, j);
			if (C != NULL) {
				if (C->GetCageID() > -1) {
					A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i, j);
					if (A != NULL) {
						A->Render();
					}
					else {
						C->Render();
					}
				}
				else {
					C->Render();
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

void Driver::PrintZoo(int x, int y)
{
	int i, j;
	Cell* C;
	Animal* A;

	for (i = 0; i < Z->GetWidth(); i++) {
		cout << "|";
		for (j = 0; j < Z->GetHeight(); j++) {
			if (x == j && y == i) {
				cout << "X";
			}
			else {
				C = Z->GetCell(i, j);
				if (C != NULL) {
					if (C->GetCageID() > -1) {
						A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i, j);
						if (A != NULL) {
							A->Render();
						}
						else {
							C->Render();
						}
					}
					else {
						C->Render();
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

void Driver::PrintZoo(int x1, int y1, int x2, int y2)
{
	int i, j;
	Cell* C;
	Animal* A;

	for (i = y1; i <= y2; i++) {
		cout << "|";
		for (j = x1; j <= x2; j++) {
			C = Z->GetCell(i, j);
			if (C != NULL) {
				if (C->GetCageID() > -1) {
					A = Z->GetCage(C->GetCageID())->IsSpaceOccupied(i, j);
					if (A != NULL) {
						A->Render();
					}
					else {
						C->Render();
					}
				}
				else {
					C->Render();
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

void Driver::PrintZoo()
{
	cout << "========================================" << endl;
	cout << "              - Food Count -" << endl;
	cout << "   Herbivore : " << Z->CountFoodHerbivore() << endl;
	cout << "   Carnivore : " << Z->CountFoodCarnivore() << endl;
	cout << "   Omnivore  : " << Z->CountFoodOmnivore() << endl;
	cout << "========================================" << endl;
}
