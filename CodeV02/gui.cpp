#include "gui.h"

//CLS METHOD
#ifdef _WIN32
#include <windows.h>
void ClearScreen()
{
	system("cls");
}

void Delay(unsigned int x)
{
	clock_t goal = x + clock();
	while (goal > clock());
}
#elif __linux__
#include <unistd.h>
void ClearScreen()
{
	system("clear");
}
void Delay(int x)
{
	usleep(x * 1000);
	fflush(stdout);
}

#endif