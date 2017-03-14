#include <iostream>
#include "../Renderable/Renderable.h"
#include "../animal/animal.h"

#ifndef CELL_H
#define CELL_H

/** @class 	Cell
 * Kelas Cell, cell_id didefinisikan pada turunan Cell, default ID = 0
 *
 */

class Cell: public Renderable{	
	public:
		Cell();

		void Render();
		void SetCode(char c);
		virtual void SetCageID(int n) {
		}
		virtual int GetCageID() {
			return cage_id;
		}

		/** @brief Mengembalikan nilai cell_id
		*/
		int GetCellID();
		/** @brief Mengembalikan nilai LocX
		* @return Lokasi X hewan
		*/
		int GetLocationX();
		/** @brief Mengembalikan nilai LocY 
		* @return Lokasi Y hewan
		*/
		int GetLocationY();

		


	protected:
		int cell_id;
		int loc_x;
		int loc_y;
		int cage_id;

	private:
		char code;
		
};
#endif
