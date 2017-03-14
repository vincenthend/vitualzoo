#include "land_animal.h"
LandAnimal::LandAnimal(){
	habitat[0] = true;
}
Chicken::Chicken(){
	weight = 2;
	food_Weight = 1;
	foodType = 3;
	tame = true;
}
void Chicken::interact(){
	cout<<"Cock-a-doodle-doo!";
}
Cat::Cat(){
	weight = 4;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Cat::interact(){
	cout<<"Meow";
}
Cow::Cow(){
	weight = 1000;
	food_Weight = 2;
	foodType = 1;
	tame = true;
}
void Cow::interact(){
	cout<<"Mooo...";
}
Mouse::Mouse(){
	weight = 2;
	food_Weight = 1;
	foodType = 1;
	tame = false;
}
void Mouse::interact(){
	cout<<"Squeak-squeak";
}
Goat::Goat(){
	weight = 100;
	food_Weight = 2;
	foodType = 1;
	tame = true;
}
void Goat::interact(){
	cout<<"Beeeeeek";
}
Llama::Llama(){
	weight = 500;
	food_Weight = 2;
	foodType = 1;
	tame = true;
}
void Llama::interact(){
	cout<<"Neiigh!";
}
Snake::Snake(){
	weight = 10;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Snake::interact(){
	cout<<"Hsssss...";
}
Sheep::Sheep(){
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = true;
}
void Sheep::interact(){
	cout<<"Baaaaaaaaaa";
}
Chameleon::Chameleon(){
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Chameleon::interact(){
	cout<<"Scrook...";
}
