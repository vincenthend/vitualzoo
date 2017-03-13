#include "cage.h"

Cage::Cage()
{
	n_animal = 0;
	a = new Animal*[999];
	c = new Cell*[999];
	cageID = -1;
	cageType = 0;
}

void Cage::addAnimal(Animal* A)
{
	bool habitable=false;
	int i;

	//indeks 
	if (n_animal < (n_cell / 10) * 3) {
		i = (cageType % 10) - 1;
		if ((A->getHabitat())[i]) {
			habitable = true;
		}

		if (habitable) {
			a[n_animal] = A;
			n_animal += 1;
		}
	}
	else {
		cout << "class full";
	}
}


void Cage::setCageID(int n)
{
	cageID = n;
}

int Cage::getCageID()
{
	return cageID;
}

int Cage::getCageType()
{
	return cageType;
}

Animal* Cage::isSpaceOccupied(int x, int y)
{
	Animal* ret = NULL;
	int i = 0;

	while(ret == NULL && i < n_animal)
		if (a[i]->getLocationX() == x && a[i]->getLocationY() == y) {
			ret = a[i];
		}
		else {
			i++;
		}

	return ret;
}

int Cage::CountFoodHerbivore()
{
	int i;
	int sum;
	sum = 0;
	for (i = 0; i < n_animal; i++) {
		if (a[i]->getFoodType() == 1) {
			sum += a[i]->getFoodQuantity();
		}
	}
	return sum;
}

int Cage::CountFoodCarnivore()
{
	int i;
	int sum;
	sum = 0;
	for (i = 0; i < n_animal; i++) {
		if (a[i]->getFoodType() == 2) {
			sum += a[i]->getFoodQuantity();
		}
	}
	return sum;
}

int Cage::CountFoodOmnivore()
{
	int i;
	int sum;
	sum = 0;
	for (i = 0; i < n_animal; i++) {
		if (a[i]->getFoodType() == 3) {
			sum += a[i]->getFoodQuantity();
		}
	}
	return sum;
}

void Cage::addHabitat(Cell* H)
{	
	//Cek apakah sudah ada isi
	if (n_cell == 0) {
		cageType = H->getCellID();
		c[n_cell] = H;
		n_cell += 1;
	}
	else {
		//Cek apakah tipe habitat sama
		if (cageType == H->getCellID()){
			c[n_cell] = H;
			n_cell += 1;
		}
	}
}