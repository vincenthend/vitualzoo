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

LandAnimal::LandAnimal(){
	habitat[0] = true;
}

WaterAnimal::WaterAnimal(){
	habitat[1] = true;
}

AirAnimal::AirAnimal(){
	habitat[2] = true;
}
