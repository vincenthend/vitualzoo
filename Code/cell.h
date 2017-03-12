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
		virtual void setCageID(int n) {

		}
		virtual int getCageID() {
			return cageID;
		}

	/** @brief Mengembalikan nilai cellID
	*/
	int getCellID();
	protected:
		int cellID;
		int locX;
		int locY;
		int cageID;
		char renderObj;

};
#endif
