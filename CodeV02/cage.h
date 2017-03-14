#include "animal.h"
#include "cell.h"

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

		bool IsFull();

		/** @brief Menambahkan habitat ke dalam cage
		*/
		void AddHabitat(Cell* H);

		/** @brief Menambahkan animal ke dalam cage, jika cage_type 
		* sesuai dengan kebutuhan animal, maka ditambahkan; cage_type pasti != 0
		*/
		void AddAnimal(Animal* A);

		//Setter and Getter

		/** @brief cage_id diubah menjadi n
		*/
		void SetCageID(int n);

		/** @brief mengembalikan nilai cage_id
		* @return nilai cage_id
		*/
		int GetCageID();

		/** @brief mengembalikan nilai cage_type
		* @return nilai cage_type
		*/
		int GetCageType();

		/** @brief mengembalikan nilai alamat animal apakah x dan y dipakai, jika tidak maka null
		* @return pointer menuju animal
		*/
		Animal* IsSpaceOccupied(int x, int y);

		//Fungsi lain

		/** @brief menghitung total jumlah makanan herbivore
		* @return nilai total makanan herbivore
		*/
		int CountFoodHerbivore();
		/** @brief menghitung total jumlah makanan carnivore
		* @return nilai total makanan carnivore
		*/
		int CountFoodCarnivore();
		/** @brief menghitung total jumlah makanan omnivore
		* @return nilai total makanan omnivore
		*/
		int CountFoodOmnivore();
		bool IsExist(int ID);


	private:
		int cage_id;
		int n_animal;
		int n_cell;
		int cage_type;
		Animal ** a;
		Cell ** c;
};

#endif
