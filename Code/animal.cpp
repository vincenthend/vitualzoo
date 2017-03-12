#include "Animal.h"
int Animal::getFoodQuantity (){
	return (food_Weight * weight);
}

int Animal::getFoodType(){
	return (foodType);
}

int Animal::getLocationX(){
	return (locX);
}

int Animal::getLocationY(){
	return (locY);
}

int Animal::getTame(){
	return (tame);
}

void Animal::move(int x, int y);
	locX += x;
	locY += y;
}

landAnimal::landAnimal(){
	habitat[0] = true;
}

waterAnimal::waterAnimal(){
	habitat[1] = true;
}

airAnimal::airAnimal(){
	habitat[2] = true;
}
