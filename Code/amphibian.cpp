#include "amphibian.h"

Penguin::Penguin()
{
	weight = 5;
	food_Weight = 1;
	foodType = 2;
	tame = true;
	type = 24;
}

void Penguin::interact()
{
	cout << "Waaaaah";
}

void Penguin::render()
{
	cout << "¥";
}
