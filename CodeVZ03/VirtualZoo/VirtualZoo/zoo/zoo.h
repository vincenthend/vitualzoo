#include <iostream>
#include "../cell/cell.h"
#include "../cage/cage.h"

#ifndef ZOO_H
#define ZOO_H


/** @class 	Zoo
 * Kelas Zoo
 */

class Zoo{
	public:

		// ctor, ctor dan dtor

		/** @brief Membuat Zoo dengan width 21 dan height 21
    	 */
		Zoo();
		
		/** @brief Membuat Zoo dengan width w dan height h dengan nama name
    	 */
		Zoo(int w, int h);
		
		/** @brief dtor Zoo
    	 */
		~Zoo();
		
		/** @brief Melakukan copy pada kebun binatang
    	 */
		Zoo(const Zoo& Z);

		//Getter dan Setter

		/** @brief Melakukan penambahan cage,
		*/
		void AddCage();

		/** @brief Melakukan penambahan cell dengan cell C yang sudah dictor di tempat lain
		*/
		void AddCell(int x, int y, Cell* C);

		/** @brief Mengembalikan nilai width pada zoo
		* @return Nilai Width Zoo
		*/
		int GetWidth();

		/** @brief Mengembalikan nilai height pada zoo
		* @return Nilai Height Zoo
		*/
		int GetHeight();

		/** @brief getter untuk cell dengan posisi x dan y
		* @return Alamat cell pada (x,y) dalam memory
		*/
		Cell* GetCell(int x, int y);

		/** @brief getter untuk cage ke-n
		* @return Alamat cage ke-n dalam memory
		*/
		Cage* GetCage(int n);

		/** @brief getter untuk cage ke-n
		* @return jumlah cage pada saat ini
		*/
		int GetNCage();

		//Fungsi lain

		/** @brief menghitung total makanan herbivore dalam zoo
		* @return total makanan herbivore
		*/
		int CountFoodHerbivore();

		/** @brief menghitung total makanan carnivore dalam zoo
		* @return total makanan carnivore
		*/
		int CountFoodCarnivore();

		/** @brief menghitung total makanan omnivore dalam zoo
		* @return total makanan omnivore
		*/
		int CountFoodOmnivore();


	private:
		int width;
		int height;
		int n_cage;
		Cell *** c;
		Cage ** cg;
};

#endif
