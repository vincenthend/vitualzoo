#include "cage.h"

Cage::Cage()
{
	n_animal = 0;
	a = new Animal*[999];
	c = new Cell*[999];
	cageID = -1;
	cageType = 0;
}

bool Cage::IsFull() {
	return (n_animal >= ((n_cell / 10) * 3));
}

void Cage::addAnimal(Animal* A)
{
	bool habitable=false;
	int i;

	//indeks 
	//Harus diubah, gak ngecek habitable lagi, jadiin I.S. udah pasti habitable
	//Harus ngeset X Y animal berdasarkan habitat yang available, kayaknya perlu gethabitat
	A->setLocationX(c[n_animal]->getLocationX());
	A->setLocationY(c[n_animal]->getLocationY());
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
		H->setCageID(cageID);
	}
	else {
		//Cek apakah tipe habitat sama
		if (cageType == H->getCellID()){
			c[n_cell] = H;
			n_cell += 1;
			H->setCageID(cageID);
		}
	}
}
