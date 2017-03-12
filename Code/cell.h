#include <iostream>
#include "renderable.h"
#include "animal.h"

#ifndef CELL_H
#define CELL_H

/** @class 	Cell
 * Kelas Cell, cellID didefinisikan pada turunan Cell, default ID = 0
 *
 */

class Cell: public Renderable{	
public:
	protected:
		int cellID;
		int locX;
		int locY;
		char renderObj;
};
#endif
