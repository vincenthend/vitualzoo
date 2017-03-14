#include "water_animal.h"
WaterAnimal::WaterAnimal(){
	habitat[2] = true;
}
Salmon::Salmon() {
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = false;
	type = 17;
}
void Salmon::interact() {
	cout << "blub blub";
}
void Salmon::render() {
	cout << ":";
}
Whale::Whale() {
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = true;
	type = 18;
}
void Whale::interact() {
	cout << "wooooooooooooo";
}
void Whale::render() {
	cout << "<";
}
Squid::Squid() {
	weight = 300;
	food_Weight = 2;
	foodType = 2;
	tame = true;
	type = 19;
}
void Squid::interact() {
	cout << "sluhb..sluhb..";
}
void Squid::render() {
	cout << ">";
}
Goldfish::Goldfish() {
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	tame = true;
	type = 20;
}
void Goldfish::interact() {
	cout << "*glub glub*";
}
void Goldfish::render() {
	cout << "/";
}
Turtle::Turtle() {
	weight = 100;
	food_Weight = 1;
	foodType = 2;
	tame = true;
	type = 21;
}
void Turtle::interact() {
	cout << "swoosh";
}
void Turtle::render() {
	cout << "=";
}
Seal::Seal() {
	weight = 25;
	food_Weight = 1;
	foodType = 2;
	tame = true;
	type = 22;
}
void Seal::interact() {
	cout << "Bawrk Bawrk!";
}
void Seal::render() {
	cout << "/";
}
Dolphin::Dolphin() {
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	tame = true;
	type = 23;
}
void Dolphin::interact() {
	cout << "*swims slowly*";
}
void Dolphin::render() {
	cout << "0";
}