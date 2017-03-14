#include "air_animal.h"
AirAnimal::AirAnimal(){
	habitat[1] = true;
}
Pelican::Pelican(){
	weight = 5;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Pelican::interact(){
	cout<<"Kraoooo";
}
Owl::Owl(){
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Owl::interact(){
	cout<<"HootHoot";
}
Pigeon::Pigeon(){
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = true;
}
void Pigeon::interact(){
	cout<<"Coo Coo";
}
Canary::Canary(){
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = true;
}
void Canary::interact(){
	cout<<"Kweee";
}
Bat::Bat(){
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = false;
}
void Bat::interact(){
	cout<<"shriekkkkkk";
}
Eagle::Eagle(){
	weight = 2;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Eagle::interact(){
	cout<<"Squawk!";
}
Toucan::Toucan(){
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = true;
}
void Toucan::interact(){
	cout<<"*flies away*";
}
