#include "animal.h"
Animal::Animal()
{
	locX = -99;
	locY = -99;
	type = 0;
}
Animal::Animal(int id)
{
	locX = -99;
	locY = -99;

	if (id == 1) {
		type = 1;
		sound = "Kraoooo";
		weight = 5;
		food_Weight = 1;
		foodType = 2;
		code = '!';
		habitat[1] = true;
		tame = true;
	}
	else if (id == 2) {
		type = 2;
		sound = "HootHoot";
		weight = 1;
		food_Weight = 1;
		foodType = 2;
		code = '@';
		habitat[1] = true;
		tame = true;
	}
	else if (id == 3) {
		type = 3;
		sound = "Coo Coo";
		weight = 1;
		food_Weight = 1;
		foodType = 1;
		code = '#';
		habitat[1] = true;
		tame = true;
	}
	else if (id == 4) {
		type = 4;
		sound = "Kweee";
		weight = 1;
		food_Weight = 1;
		foodType = 1;
		code = '$';
		habitat[1] = true;
		tame = true;
	}
	else if (id == 5) {
		type = 5;
		sound = "shriekkkkkk";
		weight = 1;
		food_Weight = 1;
		foodType = 1;
		code = '%';
		habitat[1] = true;
		tame = false;
	}
	else if (id == 6) {
		type = 6;
		sound = "Squawk!";
		weight = 2;
		food_Weight = 1;
		foodType = 2;
		code = '^';
		habitat[1] = true;
		tame = true;
	}
	else if (id == 7) {
		type = 7;
		sound = "*flies away*";
		weight = 1;
		food_Weight = 1;
		foodType = 1;
		code = '&';
		habitat[1] = true;
		tame = true;
	}
	else if (id == 8) {
		type = 8;
		sound = "Cock-a-doodle-doo!";
		weight = 2;
		food_Weight = 1;
		foodType = 3;
		code = '*';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 9) {
		type = 9;
		sound = "Meow";
		weight = 4;
		food_Weight = 1;
		foodType = 2;
		code = '-';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 10) {
		type = 10;
		sound = "Mooo...";
		weight = 1000;
		food_Weight = 2;
		foodType = 1;
		code = '+';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 11) {
		type = 11;
		sound = "Squeak-squeak";
		weight = 2;
		food_Weight = 1;
		foodType = 1;
		code = '~';
		habitat[0] = true;
		tame = false;
	}
	else if (id == 12) {
		type = 12;
		sound = "Beeeeeek";
		weight = 100;
		food_Weight = 2;
		foodType = 1;
		code = '"';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 13) {
		type = 13;
		sound = "Neiigh!";
		weight = 500;
		food_Weight = 2;
		foodType = 1;
		code = '[';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 14) {
		type = 14;
		sound = "Hsssss...";
		weight = 10;
		food_Weight = 1;
		foodType = 2;
		code = ']';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 15) {
		type = 15;
		sound = "Baaaaaaaaaa";
		weight = 1;
		food_Weight = 1;
		foodType = 1;
		code = '{';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 16) {
		type = 16;
		sound = "Scrook...";
		weight = 1;
		food_Weight = 1;
		foodType = 2;
		code = '}';
		habitat[0] = true;
		tame = true;
	}
	else if (id == 17) {
		type = 17;
		sound = "blub blub";
		weight = 1;
		food_Weight = 1;
		foodType = 2;
		code = ':';
		habitat[2] = true;
		tame = false;
	}
	else if (id == 18) {
		type = 18;
		sound = "wooooooooooooo";
		weight = 1;
		food_Weight = 1;
		foodType = 2;
		code = '<';
		habitat[2] = true;
		tame = true;
	}
	else if (id == 19) {
		type = 19;
		sound = "sluhb..sluhb..";
		weight = 300;
		food_Weight = 2;
		foodType = 2;
		code = '>';
		habitat[2] = true;
		tame = true;
	}
	else if (id == 20) {
		type = 20;
		sound = "*glub glub*";
		weight = 1;
		food_Weight = 1;
		foodType = 2;
		code = '/';
		habitat[2] = true;
		tame = true;
	}
	else if (id == 21) {
		type = 21;
		sound = "swoosh";
		weight = 100;
		food_Weight = 1;
		foodType = 2;
		code = '=';
		habitat[2] = true;
		tame = true;
	}
	else if (id == 22) {
		type = 22;
		sound = "Bawrk Bawrk!";
		code = ';';
		habitat[2] = true;
		weight = 25;
		food_Weight = 1;
		foodType = 2;
		code = '/';
		habitat[2] = true;
		tame = true;
	}
	else if (id == 23) {
		type = 23;
		sound = "*swims slowly*";
		weight = 1;
		food_Weight = 1;
		foodType = 1;
		code = '0';
		habitat[2] = true;
		tame = true;
	}
	else if (id == 24) {
		type = 24;
		sound = "Waaaah";
		weight = 5;
		food_Weight = 1;
		foodType = 2;
		code = '¥';
		habitat[0] = true;
		habitat[2] = true;
		tame = true;
	}

}
void Animal::interact()
{
	cout << sound << endl;
}
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

void Animal::setLocationX(int x){
	locX = x;
}

void Animal::setLocationY(int y){
	locY = y;
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
