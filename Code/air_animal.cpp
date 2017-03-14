#include "air_animal.h"
AirAnimal::AirAnimal(){
	habitat[1] = true;
}
Pelican::Pelican() {
	weight = 5;
	food_Weight = 1;
	foodType = 2;
	type = 1;
	cenemy = 0;
}
void Pelican::interact() {
	cout << "Kraoooo";
}
void Pelican::render() {
	cout << "!";
}
Owl::Owl() {
	weight = 1;
	food_Weight = 1;
	foodType = 2;
	type = 2;
	cenemy = 0;
}
void Owl::interact() {
	cout << "HootHoot";
}
void Owl::render() {
	cout << "@";
}
Pigeon::Pigeon() {
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	type = 3;
	cenemy = 0;
}
void Pigeon::interact() {
	cout << "Coo Coo";
}
void Pigeon::render() {
	cout << "#";
}
Canary::Canary() {
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	type = 4;
	cenemy = 0;
}
void Canary::interact() {
	cout << "Kweee";
}
void Canary::render() {
	cout << "$";
}
Bat::Bat() {
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	type = 5;
	cenemy = 2;
	EnemyID = new int [cenemy];
	EnemyID[0] = 2;
	EnemyID[1] = 4;
}
void Bat::interact() {
	cout << "shriekkkkkk";
}
void Bat::render() {
	cout << "%";
}
Eagle::Eagle() {
	weight = 2;
	food_Weight = 1;
	foodType = 2;
	type = 6;
	cenemy = 0;
}
void Eagle::interact() {
	cout << "Squawk!";
}
void Eagle::render() {
	cout << "^";
}
Toucan::Toucan() {
	weight = 1;
	food_Weight = 1;
	foodType = 1;
	type = 7;
	cenemy = 0;
}
void Toucan::interact() {
	cout << "*flies away*";
}
void Toucan::render() {
	cout << "&";
}
