#include "water_animal.h"
WaterAnimal::WaterAnimal(){
	habitat[2] = true;
}
Salmon::Salmon(){
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = false;
}
void Salmon::interact(){
	cout<<"blub blub";
}
Whale::Whale(){
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Whale::interact(){
	cout<<"wooooooooooooo";
}
Squid::Squid(){
	weight = 300;
	food_Weight = 2;
	foodType = 2;
	tame = true;
}
void Squid::interact(){
	cout<<"sluhb..sluhb..";
}
Goldfish::Goldfish(){
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Goldfish::interact(){
	cout<<"*glub glub*";
}
Turtle::Turtle(){
	weight = 100;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Turtle::interact(){
	cout<<"swoosh";
}
Seal::Seal(){
	weight = 25;
	food_Weight = 1;
	foodType = 2;
	tame = true;
}
void Seal::interact(){
	cout<<"Bawrk Bawrk!";
}
Dolphin::Dolphin(){
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = true;
}
void Dolphin::interact(){
	cout<<"*swims slowly*";
}
