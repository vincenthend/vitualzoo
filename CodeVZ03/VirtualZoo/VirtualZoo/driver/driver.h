//Header to include all files
//Standard Headers
#include <iostream>
#include <fstream>

//Class Headers
#include "../animal/animal.h"
#include "../air_animal/air_animal.h"
#include "../land_animal/land_animal.h"
#include "../water_animal/water_animal.h"
#include "../amphibian/amphibian.h"
#include "../cage/cage.h"
#include "../cell/cell.h"
#include "../facility/facility.h"
#include "../habitat/habitat.h"
#include "../Renderable/Renderable.h"
#include "../zoo/zoo.h"
#include "../gui/gui.h"

#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
public:	
	/** @brief Membuat driver yang membuat Zoo sesuai file Input
	*/
	Driver(string Input);

	/** @brief dtor driver
	*/
	~Driver();
	
	/** @brief Mencetak menu dan memfasilitasi input menu
	*/
	void printMenu();

	/** @brief Menjalankan Tour
	*/
	void StartTour();

	/** @brief Mencetak keseluruhan zoo
	*/
	void printZoo();
	
	/** @brief Mencetak zoo dengan x,y adalah posisi player
	* @param x posisi absis player
	* @param y posisi ordinat player
	*/
	void printZoo(int x, int y);

	/** @brief Mencetak zoo dari titik (x1,y1) hingga (x2,y2)
	*/
	void printZoo(int x1, int y1, int x2, int y2);

	//void printLegend();

	/** @brief Mencetak zoo dari titik (x1,y1) hingga (x2,y2)
	*/
	void printStatus();

private:
	Zoo* Z;
};

#endif
