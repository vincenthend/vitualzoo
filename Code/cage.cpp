#include "cage.h"

Cage::Cage()
{
	n_animal = 0;
	a = new Animal*[999];
	c = new Habitat*[999];
	cageID = -1;
	cageType = 0;
}

void Cage::addAnimal(Animal* A)
{
	a[n_animal] = A;
	n_animal += 1;
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

void Cage::addHabitat(Habitat* H)
{	
	//Cek apakah sudah ada isi
	if (n_cell = 0) {
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
