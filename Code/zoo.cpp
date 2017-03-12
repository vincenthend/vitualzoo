#include "zoo.h"

//copas ke zoo.cpp

Zoo::Zoo(){
	int i;
	
	width = 21;
	height = 21;
	c = new Cell** [width];
	
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
	}
}

Zoo::Zoo(int w, int h){
	int i;
	
	width = w;
	height = h;
	c = new Cell** [width];
	
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
	}
}

Zoo::~Zoo(){
	int i;
	
	for(i = 0; i<width; i++){
		delete [] c[i];
	}
	delete [] c;
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