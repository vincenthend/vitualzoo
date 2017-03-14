#include <iostream>
#include "animal.h"

#ifndef CELL_H
#define CELL_H

/** @class 	Cell
 * Kelas Cell, cellID didefinisikan pada turunan Cell
 */
class Cell{	
	public:
		/** @brief Membuat cell dengan x dan y 0 dan cellID 0
		*/
		Cell();
		/** @brief Mengembalikan nilai cellID 
		* 11 = LandHabitat; 12 = WaterHabitat; 13 = AirHabitat;
		* 21 = Road; 210 = Entrance; 211 = Exit; 22 = Resto; 23 = Park;
		* @param x
		* lokasi x
		* @param y
		* lokasi y
		* @param ID
		* nilai cellID (tetap)
		*/
		Cell(int x, int y, int ID);
		/** @brief Melakukan render (mencetak Code)
		*/
		void render();
		/** @brief Mencetak code
		*/
		void setCode(char c);
		/** @brief Mengatur nilai cageID
		*/
		void setCageID(int n);
		/** @brief Mengembalikan nilai cageID
		*/
		int getCageID();
		/** @brief Mengembalikan nilai cellID
		*/
		int getCellID();
		/** @brief Mengembalikan posisi absis hewan.
	     * @return Posisi absis cell.
	     */
		int getLocationX();
		/** @brief Mengembalikan posisi ordinat hewan.
	     * @return Posisi ordinat cell.
	     */
		int getLocationY();
	protected:
		const int cellID = 0;
		int locX;
		int locY;
		int cageID = -1;

	private:
		char code;
		
};
#endif
