#include <iostream>
#include "../animal/animal.h"

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
		/** @brief Melakukan Render (mencetak Code)
		*/
		void Render();
		/** @brief Mencetak code
		*/
		void SetCode(char c);
		/** @brief Mengatur nilai cage_id
		*/
		void SetCageID(int n);
		/** @brief Mengembalikan nilai cage_id
		*/
		int GetCageID();
		/** @brief Mengembalikan nilai cell_id
		*/
		int GetCellID();
		/** @brief Mengembalikan posisi absis hewan.
	     * @return Posisi absis cell.
	     */
		int GetLocationX();
		/** @brief Mengembalikan posisi ordinat hewan.
	     * @return Posisi ordinat cell.
	     */
		int GetLocationY();
	protected:
		const int cell_id = 0;
		int loc_x;
		int loc_y;
		int cage_id = -1;

	private:
		char code;
		
};
#endif
