#include "gui.h"

//CLS METHOD
#ifdef _WIN32
#include <windows.h>
void ClearScreen()
{
	system("cls");
}

void Delay(int x)
{
	int c = 1, d = 1;
	for (c = 1; c <= x * 10; c++)
		for (d = 1; d <= x * 10; d++)
		{
		}
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