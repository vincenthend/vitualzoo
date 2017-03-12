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
		/** @brief Membuat Cell dengan X dan Y 0 dan cellID 0
    	 */
		Cell();
		
	    /** @brief Membuat Cell pada X dan Y tertentu dengan cellID terdefinisi
    	 */
		Cell(int x, int y, int ID);
	
	protected:
		int cellID;
		int locX;
		int locY;
};
#endif
