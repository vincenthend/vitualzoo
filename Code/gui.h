#ifndef GUI_H
#define GUI_H

#include <stdlib.h>

//CLS METHOD
#ifdef _WIN32
	#include <windows.h>
	void ClearScreen()
	{
		system("cls");
	}

	void delay(int x)
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
void delay(int x)
{
	usleep(x * 1000);
	fflush(stdout);
}

#endif

#endif