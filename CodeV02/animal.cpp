#include "animal.h"
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

int Animal::getType()
{
	return 0;
}

void Animal::move(int x, int y){
	locX += x;
	locY += y;
}

void Animal::render()
{
	cout << code;
}

bool * Animal::getHabitat()
{
	return habitat;
}
