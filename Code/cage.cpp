#include "cage.h"

Cage::Cage()
{
	n_animal = 0;
	n_cell = 0;
	a = new Animal*[99];
	c = new Cell*[99];
}

void Cage::AddAnimal(Animal* A)
{
	a[n_animal] = A;
	n_animal += 1;
}

void Cage::AddHabitat(Habitat* H)
{
	c[n_cell] = H;
	n_cell += 1;
}
