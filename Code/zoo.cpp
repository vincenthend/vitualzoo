#include "zoo.h"

Zoo::Zoo(){
	int i,j;
	
	n_cage = 0;
	width = 21;
	height = 21;

	//Init cell
	c = new Cell** [width];	
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
		for (j = 0; j < height; j++) {
			//Inisialisasi dengan null
			c[i][j] = NULL;
		}
	}

	//Init cage
	cg = new Cage*[width];
}

Zoo::Zoo(int w, int h){
	int i,j;
	
	n_cage = 0;
	width = w;
	height = h;
	
	//Init cell
	c = new Cell** [width];	
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
		for (j = 0; j < height; j++) {
			//Inisialisasi dengan null
			c[i][j] = NULL;
		}
	}

	//Init cage
	cg = new Cage*[width];
}

Zoo::~Zoo(){
	int i,j;
	
	//Delete cell & cell data
	for (i = 0; i < width; i++) {
		for (j = 0;j < width;j++) {
			if (c[i][j] != NULL) {
				delete c[i][j];
			}
		}
		delete[] c[i];
	}
	delete[] c;

	//Delete cage & cage data
	for (i = 0; i < n_cage; i++) {
		delete cg[i];
	}
	delete[] cg;
}

Zoo::Zoo(const Zoo& Z){
	int i,j;
	
	width = Z.width;
	height = Z.height;
	c = new Cell** [width];
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
		for(j = 0; i<height; i++){
			c[i][j] = Z.c[i][j];
		}
	}	
}

void Zoo::addCage()
{
	cg[n_cage] = new Cage;
	cg[n_cage]->setCageID(n_cage);
	n_cage += 1;	
}

void Zoo::addCell(int x, int y, Cell* C)
{
	c[x][y] = C;
}

int Zoo::getWidth()
{
	return width;
}

int Zoo::getHeight()
{
	return height;
}

Cell* Zoo::getCell(int x, int y)
{
	return c[x][y];
}

Cage * Zoo::getCage(int n)
{
	return cg[n];
}

int Zoo::getNCage()
{
	return n_cage;
}

int Zoo::CountFoodHerbivore()
{
	int i, sum;
	i = 0;
	sum = 0;
	for (i = 0; i < n_cage;i++) {
		sum += cg[i]->CountFoodHerbivore();
	}
	return sum;
}

int Zoo::CountFoodCarnivore()
{
	int i,sum;
	i = 0;
	sum = 0;
	for (i = 0; i < n_cage;i++) {
		sum += cg[i]->CountFoodCarnivore();
	}
	return sum;
}

int Zoo::CountFoodOmnivore()
{
	int i, sum;
	i = 0;
	sum = 0;
	for (i = 0; i < n_cage;i++) {
		sum += cg[i]->CountFoodOmnivore();
	}
	return sum;
}
