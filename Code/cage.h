#include "animal.h"
#include "habitat.h"

#ifndef CAGE_H
#define CAGE_H


/**
 * @class 	Cage
 * Kelas Cage
 */

 
class Cage{
	public :
		/** @brief Inisialisasi cage dengan n_animal 0 dan n_cell 0
		* membuat array a dan c sebanyak 999 buah
		*/
		Cage();

		/** @brief Menambahkan habitat ke dalam cage
		*/
		void AddHabitat(Habitat* H);

		/** @brief Menambahkan animal ke dalam cage
		*/
		void AddAnimal(Animal* A);

		//Setter and Getter

		/** @brief cageID diubah menjadi n
		*/
		void setCageID(int n);

		/** @brief mengembalikan nilai cageID
		* @return nilai cageID
		*/
		int getCageID();

		/** @brief mengembalikan nilai cageType
		* @return nilai cageType
		*/
		int getCageType();

		/** @brief mengembalikan nilai alamat animal apakah x dan y dipakai, jika tidak maka null
		* @return pointer menuju animal
		*/
		Animal* isSpaceOccupied(int x, int y);

	private:
		int cageID;
		int n_animal;
		int n_cell;
		int cageType;
		Animal ** a;
		Habitat ** c;	
};

#endif
