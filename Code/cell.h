#ifndef CELL_H
#define CELL_H


#include <iostream>
#include "renderable.h"
#include "animal.h"

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
		
		/** @brief Membuat Cell pada X dan Y tertentu dengan ID tertentu.
    	 */
		~Cell();
		Cell(Cell& C);
	
	private:
		int cellID;
		int locX;
		int locY;
};
#endif
