#include "driver.h"
#include <time.h>
#include <random>
#include <string>

Driver::Driver(string Input)
{
	Cell* c;
	ifstream myfile(Input);
	string s;
	int i, j, k, l, w, h, temp, a_id, a_count;
	bool found, enemy;
	Animal* a;

	a = NULL;
	getline(myfile, s);
	i = 0;
	temp = 0;
	c = NULL;
	while ((s[i] >= '0') && (s[i] <= '9')) {
		temp = (temp * 10) + (s[i] - '0');
		i++;
	}
	h = temp;
	getline(myfile, s);
	i = 0;
	temp = 0;
	while ((s[i] >= '0') && (s[i] <= '9')) {
		temp = (temp * 10) + (s[i] - '0');
		i++;
	}
	w = temp;
	z = new Zoo(w, h);
	for (i = 0; i < z->GetHeight(); i++) {
		getline(myfile, s);
		for (j = 0; j <= z->GetWidth(); j++) {
			if (s[j] == 'L'){
				c = new LandHabitat(i, j);
			}
			else {
				if (s[j] == 'W'){
					C = new WaterHabitat(i, j);
				}
				else {
					if (s[j] == 'A'){
						C = new AirHabitat(i, j);
					}
					else {
						if (s[j] == 'S'){
							c = new Road(i, j, true);
						}
						else {
							if (s[j] == 'F'){
								c = new Road(i, j, false);
							}
							else {
								if (s[j] == 'X'){
									c = new Road(i, j);
								}
								else {
									if (s[j] == 'R'){
										c = new Resto(i, j);
									}
									else {
										if (s[j] == 'P'){
											c = new Park(i, j);
										}
									}
								}
							}
						}
					}
				}
			}
			z->AddCell(i, j, c);
		}
	}
	for (i = 0; i < z->GetHeight(); i++) {
		for (j = 0; j < z->GetWidth(); j++) {
			found = false;
			c = z->GetCell(i, j);
			if ((c->GetCellID()>= 11) && (c->GetCellID() <= 13)) {
				if (((j - 1) >= 0) && (!(found))) {
					if (((z->GetCell(i, j)->GetCellID()) == (z->GetCell(i, j - 1)->GetCellID()))) {
						z->GetCage(z->GetCell(i, j - 1)->GetCageID())->AddHabitat(z->GetCell(i, j));
						found = true;
					}
				}
				if (((i - 1) >= 0) && (!(found))) {
					if (((z->GetCell(i, j)->GetCellID()) == (z->GetCell(i - 1, j)->GetCellID()))) {
						z->GetCage(z->GetCell(i - 1, j)->GetCageID())->AddHabitat(z->GetCell(i, j));
						found = true;
					}
				}
				if (!(found)) {
					z->AddCage();
					z->GetCage(z->GetNCage() - 1)->AddHabitat(z->GetCell(i, j));
				}
			}
		}
	}

	getline(myfile, s);
	i = 0;
	temp = 0;
	while ((s[i] >= '0') && (s[i] <= '9')) {
		temp = (temp * 10) + (s[i] - '0');
		i++;
	}
	for (i = 0; i < temp; i++) {
		getline(myfile, s);
		a_id = 0;
		j = 0;
		while ((s[j] >= '0') && (s[j] <= '9')) {
			a_id = (a_id * 10) + (s[j] - '0');
			j++;
		}
		j++;
		a_count = 0;
		while ((s[j] >= '0') && (s[j] <= '9')) {
			a_count = (a_count * 10) + (s[j] - '0');
			j++;
		}
		k = 0;
		for (j = 0; j < a_count; j++) {
			//NEW ANIMAL
			if (a_id == 1) {
				a = new Pelican;
			}
			else if (aid == 2) {
				a = new Owl;
			}
			else if (aid == 3) {
				a = new Pigeon;
			}
			else if (aid == 4) {
				a = new Canary;
			}
			else if (aid == 5) {
				a = new Bat;
			}
			else if (aid == 6) {
				a = new Eagle;
			}
			else if (aid == 7) {
				a = new Toucan;
			}
			else if (aid == 8) {
				a = new Chicken;
			}
			else if (aid == 9) {
				a = new Cat;
			}
			else if (aid == 10) {
				a = new Cow;
			}
			else if (aid == 11) {
				a = new Mouse;
			}
			else if (aid == 12) {
				a = new Goat;
			}
			else if (aid == 13) {
				a = new Llama;
			}
			else if (aid == 14) {
				a = new Snake;
			}
			else if (aid == 15) {
				a = new Sheep;
			}
			else if (aid == 16) {
				a = new Chameleon;
			}
			else if (aid == 17) {
				a = new Salmon;
			}
			else if (aid == 18) {
				a = new Whale;
			}
			else if (aid == 19) {
				a = new Squid;
			}
			else if (aid == 20) {
				a = new Goldfish;
			}
			else if (aid == 21) {
				a = new Turtle;
			}
			else if (aid == 22) {
				a = new Seal;
			}
			else if (aid == 23) {
				a = new Dolphin;
			}
			else if (aid == 24) {
				a = new Penguin;
			}
			
			found = false;
			while ((!(found)) && (k < z->GetNCage())) {
				if ((a->GetHabitat()[(((z->GetCage(k))->GetCageType()) % 10) - 1]) && !(z->GetCage(k)->IsFull())) {
					l = 0;
					enemy = false;
					while (l < a->GetCEnemy()){
						if (z->GetCage(k)->IsExist(a->GetEnemyList()[l])){
							enemy = true;
						}
						l++;
					}
					if (!(enemy)){
						found = true;
						(z->GetCage(k))->AddAnimal(a);
					}
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
					printZoo(x1, y1, x2, y2);
					cout << endl;
				}
			} while (choice != 9);
			choice = 0;
		}
		else if (choice == 2) {
			StartTour();
			ClearScreen();
		}

	} while (choice != 9);
}

void Driver::StartTour()
{
	int i, j, tx[10], ty[10], tc, move, t_move[4], c_move;
	int temp;
	Cell* c;
	Animal* a;
	bool walk = true;
	tc = 0;
	c = z->GetCell(0, 0); //Visstud error without this
	
	ClearScreen();
	PrintZoo();
	PrintStatus();

	srand((unsigned int)time(NULL));
	for (i = 0; i < z->GetWidth(); i++) {
		for (j = 0; j < z->GetHeight(); j++) {
			c = z->GetCell(i, j);
			if (c != NULL) {
				if (c->GetCellID() == 210) {
					tx[tc] = i;
					ty[tc] = j;
					tc++;
				}
			}
		}
	}
	move = 0;
	//Random entrance yang dipake, simpen  x y di i j
	temp = (rand() % (tc));
	i = tx[temp];
	j = ty[temp];

	while (c->GetCellID() != 211 && walk) {
		//Print Zoo
		ClearScreen();
		PrintZoo(j,i);
		PrintStatus();

		cout << "(" << i << "," << j << ")" << c->GetCellID()<< endl;
		//Interact
		if (((j - 1) >= 0) && (move != 3)) {
			c = z->GetCell(i, j - 1);
			if ((c->GetCellID() >= 11) && (c->GetCellID() <= 13)) {
				if (c != NULL) {
					if (c->GetCageID() > -1) {
						a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i, j-1);
						if (a != NULL) {
							a->Interact();
						}
					}
				}
			}
		}
		if (((i + 1) < z->GetHeight()) && (move != 4)) {
			c = z->GetCell(i + 1, j);
			if ((c->GetCellID() >= 11) && (c->GetCellID() <= 13)) {
				if (c != NULL) {
					if (c->GetCageID() > -1) {
						a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i+1, j);
						if (a != NULL) {
							a->Interact();
						}
					}
				}
			}
		}
		if (((j + 1) < z->GetWidth()) && (move != 1)) {
			c = z->GetCell(i, j + 1);
			if ((c->GetCellID() >= 11) && (c->GetCellID() <= 13)) {
				if (c != NULL) {
					if (c->GetCageID() > -1) {
						a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i, j+1);
						if (a != NULL) {
							a->Interact();
						}
					}
				}
			}
		}
		if (((i - 1) >= 0) && (move != 2)) {
			c = z->GetCell(i - 1, j);
			if ((c->GetCellID() >= 11) && (c->GetCellID() <= 13)) {
				if (c != NULL) {
					if (c->GetCageID() > -1) {
						a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i-1, j);
						if (a != NULL) {
							a->Interact();
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
		c_move = 0;
		if (((j - 1) >= 0) && (move != 3)){
			c = z->GetCell(i, j - 1);
			if (c->GetCellID() == 21 || c->GetCellID() == 211 ){
				t_move[c_move] = 1;
				c_move++;
			}
		}
		if (((i + 1) < z->GetHeight()) && (move != 4)){
			c = z->GetCell(i + 1, j);
			if (c->GetCellID() == 21 || c->GetCellID() == 211){
				t_move[c_move] = 2;
				c_move++;
			}
		}
		if (((j + 1) < z->GetWidth()) && (move != 1)){
			c = z->GetCell(i, j + 1);
			if (c->GetCellID() == 21 || c->GetCellID() == 211){
				t_move[c_move] = 3;
				c_move++;
			}
		}
		if (((i - 1) >= 0) && (move != 2)){
			c = z->GetCell(i - 1, j);
			if (c->GetCellID() == 21 || c->GetCellID() == 211){
				t_move[c_move] = 4;
				c_move++;
			}
		}

		//Random jalan yang mungkin pake mod cmove, simpen di move
		if (c_move > 0) {
			move = t_move[(rand() % c_move)];
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
		}
		else {
			walk = false;
		}		
		c = z->GetCell(i, j);
		Delay(500);
	}
	cout << "Tur selesai :D" << endl;
}

void Driver::printZoo()
{
	int i, j;
	Cell* c;
	Animal* a;

	for (i = 0; i < z->GetWidth(); i++) {
		cout << "|";
		for (j = 0; j < z->GetHeight(); j++) {
			c = z->GetCell(i, j);
			if (c != NULL) {
				if (c->GetCageID() > -1) {
					a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i, j);
					if (a != NULL) {
						a->Render();
					}
					else {
						c->Render();
					}
				}
				else {
					c->Render();
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
	Cell* c;
	Animal* a;

	for (i = 0; i < z->GetWidth(); i++) {
		cout << "|";
		for (j = 0; j < z->GetHeight(); j++) {
			if (x == j && y == i) {
				cout << "X";
			}
			else {
				c = z->GetCell(i, j);
				if (c != NULL) {
					if (c->GetCageID() > -1) {
						a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i, j);
						if (a != NULL) {
							a->Render();
						}
						else {
							c->Render();
						}
					}
					else {
						c->Render();
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
	Cell* c;
	Animal* a;

	for (i = y1; i <= y2; i++) {
		cout << "|";
		for (j = x1; j <= x2; j++) {
			c = z->GetCell(i, j);
			if (c != NULL) {
				if (c->GetCageID() > -1) {
					a = z->GetCage(c->GetCageID())->IsSpaceOccupied(i, j);
					if (a != NULL) {
						a->Render();
					}
					else {
						c->Render();
					}
				}
				else {
					c->Render();
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
	cout << "   Herbivore : " << z->CountFoodHerbivore() << endl;
	cout << "   Carnivore : " << z->CountFoodCarnivore() << endl;
	cout << "   Omnivore  : " << z->CountFoodOmnivore() << endl;
	cout << "========================================" << endl;
}
