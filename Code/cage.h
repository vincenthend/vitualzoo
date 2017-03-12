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
		* membuat array a dan c sebanyak 99 buah
		*/
		Cage();

		/** @brief Menambahkan habitat ke dalam cage
		*/
		void addHabitat(Habitat* H);

		/** @brief Menambahkan animal ke dalam cage
		*/
		void addAnimal(Animal* A);
		
	private:
		int n_animal;
		int n_cell;
		Animal ** a;
		Habitat ** c;	
};

#endif
