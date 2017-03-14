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
		code = '!';
		habitat[2] = true;
	}
	else if (id == 2) {
		type = 2;
		sound = "*flies around*";
		code = '@';
		habitat[2] = true;
	}
	else if (id == 3) {
		type = 3;
		sound = "*flickers*";
			code = '#';
		habitat[2] = true;
	}
	else if (id == 4) {
		type = 4;
		sound = "Bzzzz";
		code = '$';
		habitat[2] = true;
	}
	else if (id == 5) {
		type = 5;
		sound = "Chip Whirp Whirp!";
		code = '%';
		habitat[2] = true;
	}
	else if (id == 6) {
		type = 6;
		sound = "Squawk!";
		code = '^';
		habitat[2] = true;
	}
	else if (id == 7) {
		type = 7;
		sound = "*fly away*";
		code = '&';
		habitat[2] = true;
	}
	else if (id == 8) {
		type = 8;
		sound = "Cock-a-doodle-doo!";
		code = '*';
		habitat[0] = true;
	}
	else if (id == 9) {
		type = 9;
		sound = "Meow";
		code = '-';
		habitat[0] = true;
	}
	else if (id == 10) {
		type = 10;
		sound = "Mooo...";
		code = '+';
		habitat[0] = true;
	}
	else if (id == 11) {
		type = 11;
		sound = "Squeak-squeak";
		code = '~';
		habitat[0] = true;
	}
	else if (id == 12) {
		type = 12;
		sound = "Baa..";
		code = '"';
		habitat[0] = true;
	}
	else if (id == 13) {
		type = 13;
		sound = "Neiigh!";
		code = '[';
		habitat[0] = true;
	}
	else if (id == 14) {
		type = 14;
		sound = "Hsssss...";
		code = ']';
		habitat[0] = true;
	}
	else if (id == 15) {
		type = 15;
		sound = ".....";
		code = '{';
		habitat[0] = true;
	}
	else if (id == 16) {
		type = 16;
		sound = "Scrook...";
		code = '}';
		habitat[0] = true;
	}
	else if (id == 17) {
		type = 17;
		sound = "blub blub";
		code = ':';
		habitat[1] = true;
	}
	else if (id == 18) {
		type = 18;
		sound = "splash";
		code = '<';
		habitat[1] = true;
	}
	else if (id == 19) {
		type = 19;
		sound = "sluhb.;sluhb..";
		code = '>';
		habitat[1] = true;
	}
	else if (id == 20) {
		type = 20;
		sound = "*glub glub*";
		code = '/';
		habitat[1] = true;
	}
	else if (id == 21) {
		type = 21;
		sound = "swoosh";
		code = '=';
		habitat[1] = true;
	}
	else if (id == 22) {
		type = 22;
		sound = "Bawrk Bawrk!";
		code = ';';
		habitat[1] = true;
	}
	else if (id == 23) {
		type = 23;
		sound = "*swims slowly*";
		code = '0';
		habitat[1] = true;
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
