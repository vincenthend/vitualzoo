#include <iostream>
#include "cell.h"

using namespace std;

#ifndef HABITAT_H
#define HABITAT_H

/**
 * @class 	Habitat
 * Kelas Habitat
 *
 */
class Habitat: public Cell{
	
	public:
	/** @brief Mengubah nilai cageID menjadi n
	*/
	void setCageID(int n);

	/** @brief Mengembalikan nilai cageID
	*/
	int getCageID();
};

/**
 * @class 	landHabitat
 * Kelas landHabitat, cellID bernilai 11
 *
 */
class landHabitat: public Habitat{
	public:
		//ctor, dtor, cctor
		/** @brief Membuat landHabitat dengan X dan Y 0 dan cellID 11
    	 */
		landHabitat();
		
		/** @brief Membuat landHabitat dengan X dan Y terdefinisi dan cellID 11
    	 */
		landHabitat(int x, int y);
		
		/** @brief Melakukan render terhadap jenis cell
    	 */
		void Render();
	
};

/**
 * @class 	waterHabitat
 * Kelas waterHabitat, cellID bernilai 13
 *
 */
class waterHabitat: public Habitat{
	public:
	//ctor, dtor, cctor
	/** @brief Membuat waterHabitat dengan X dan Y 0 dan cellID 11
	*/
	waterHabitat();

	/** @brief Membuat waterHabitat dengan X dan Y terdefinisi dan cellID 11
	*/
	waterHabitat(int x, int y);

	/** @brief Melakukan render terhadap jenis cell
	*/
	void Render();

};


/**
* @class 	airHabitat
* Kelas airHabitat, cellID bernilai 12
*
*/
class airHabitat : public Habitat {
public:
	//ctor, dtor, cctor
	/** @brief Membuat airHabitat dengan X dan Y 0 dan cellID 12
	*/
	airHabitat();

	/** @brief Membuat airHabitat dengan X dan Y terdefinisi dan cellID 12
	*/
	airHabitat(int x, int y);

	/** @brief Melakukan render terhadap jenis cell
	*/
	void Render();

};

#endif
