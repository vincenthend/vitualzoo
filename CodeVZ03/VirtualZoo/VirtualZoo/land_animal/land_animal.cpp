#include "land_animal.h"
LandAnimal::LandAnimal(){
	habitat[0] = true;
}
Chicken::Chicken() {
	weight = 2;
	food_Weight = 1;
	foodType = 3;
	type = 8;
	cenemy = 0;
}
void Chicken::interact() {
	cout << "Cock-a-doodle-doo!";
}
void Chicken::render() {
	cout << "*";
}
Cat::Cat() {
	weight = 4;
	food_Weight = 1;
	foodType = 2;
	type = 9;
	cenemy = 0;
}
void Cat::interact() {
	cout << "Meow";
}
void Cat::render() {
	cout << "-";
}
Cow::Cow() {
	weight = 1000;
	food_Weight = 2;
	foodType = 1;
	type = 10;
	cenemy = 0;
}
void Cow::interact() {
	cout << "Mooo...";
}
void Cow::render() {
	cout << "+";
}
Mouse::Mouse() {
	weight = 2;
	food_Weight = 1;
	foodType = 1;
	type = 11;
	cenemy = 1;
	EnemyID = new int [cenemy];
	EnemyID[0] = 9;
}
void Mouse::interact() {
	cout << "Squeak-squeak";
}
void Mouse::render() {
	cout << "~";
}
Goat::Goat() {
	weight = 100;
	food_Weight = 2;
	foodType = 1;
	type = 12;
	cenemy = 0;
}
void Goat::interact() {
	cout << "Beeeeeek";
}
void Goat::render() {
	cout << ";";
}
Llama::Llama() {
	weight = 500;
	food_Weight = 2;
	foodType = 1;
	type = 13;
	cenemy = 0;
}
void Llama::interact() {
	cout << "Neiigh!";
}
void Llama::render() {
	cout << "[";
}
Snake::Snake() {
	weight = 10;
	food_Weight = 1;
	foodType = 2;
	type = 14;
	cenemy = 0;
}
void Snake::interact() {
	cout << "Hsssss...";
}
void Snake::render() {
	cout << "]";
}
Sheep::Sheep() {
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	type = 15;
	cenemy = 0;
}
void Sheep::interact() {
	cout << "Baaaaaaaaaa";
}
void Sheep::render() {
	cout << "{";
}
Chameleon::Chameleon() {
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	type = 16;
	cenemy = 0;
}
void Chameleon::interact() {
	cout << "Scrook...";
}
void Chameleon::render() {
	cout << "}";
}
