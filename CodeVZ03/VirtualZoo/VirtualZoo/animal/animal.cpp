#include "animal.h"
int Animal::GetFoodQuantity (){
	return (food_Weight * weight);
}

int Animal::GetFoodType(){
	return (foodType);
}

int Animal::GetLocationX(){
	return (locX);
}

int Animal::GetLocationY(){
	return (locY);
}

void Animal::SetLocationX(int x) {
	locX = x;
}

void Animal::SetLocationY(int y) {
	locY = y;
}

int Animal::GetType()
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
