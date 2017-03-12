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
<<<<<<< HEAD
	public:
		void render();
		void setCode(char c);
=======

	public:
		virtual void setCageID(int n) {

		}
		virtual int getCageID() {
			return cageID;
		}

	/** @brief Mengembalikan nilai cellID
	*/
	int getCellID();
>>>>>>> 786693fe39eaccf034845372b6b4ce5b35a21a2a
	protected:
		int cellID;
		int locX;
		int locY;
<<<<<<< HEAD
	private:
		char code;
=======
		int cageID;
		char renderObj;

>>>>>>> 786693fe39eaccf034845372b6b4ce5b35a21a2a
};
#endif
