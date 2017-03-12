#include "cage.h"

Cage::Cage()
{
	n_animal = 0;
	a = new Animal*[99];
}

void Cage::addAnimal(Animal* A)
{
	a[n_animal] = A;
	n_animal += 1;
}

void Cage::addHabitat(Habitat* H)
{
	c[n_cell] = H;
	n_cell += 1;
}
