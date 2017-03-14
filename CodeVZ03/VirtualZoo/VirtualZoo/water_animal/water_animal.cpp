#include "water_animal.h"
WaterAnimal::WaterAnimal(){
	habitat[2] = true;
}
Salmon::Salmon() {
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	type = 17;
	cenemy = 0;
	EnemyID = new int [cenemy];
	EnemyID [0] = 19;
	EnemyID [1] = 21;
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
	type = 18;
	cenemy = 0;
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
	type = 19;
	cenemy = 0;
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
	type = 20;
	cenemy = 0;
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
	type = 21;
	cenemy = 0;
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
	type = 22;
	cenemy = 0;
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
	type = 23;
	cenemy = 0;
}
void Dolphin::interact() {
	cout << "*swims slowly*";
}
void Dolphin::render() {
	cout << "0";
}
