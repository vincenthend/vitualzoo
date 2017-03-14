#include "land_animal.h"
LandAnimal::LandAnimal(){
	habitat[0] = true;
}
Chicken::Chicken() {
	weight = 2;
	food_Weight = 1;
	foodType = 3;
	tame = true;
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
	tame = true;
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
	tame = true;
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
	tame = false;
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
	tame = true;
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
	tame = true;
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
	tame = true;
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
	tame = true;
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
	tame = true;
}
void Chameleon::interact() {
	cout << "Scrook...";
}
void Chameleon::render() {
	cout << "}";
}