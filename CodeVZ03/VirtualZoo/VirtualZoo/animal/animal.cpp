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

void Animal::setLocationX(int x) {
	locX = x;
}

void Animal::setLocationY(int y) {
	locY = y;
}

int Animal::getType()
{
	return type;
}

void Animal::move(int x, int y){
	locX += x;
	locY += y;
}

bool * Animal::getHabitat()
{
	return habitat;
}

int* Animal::getEnemyList()
{
	return EnemyID;
}

int Animal::getCEnemy()
{
	return cenemy;
}
