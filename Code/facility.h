#include <iostream>
#include "Cell.h"

#ifndef FACILITY_H
#define FACILITY_H


/**
* @class Facility
* Kelas Road, cellID bernilai 21
* @param type
* type entrance bernilai 1, exit bernilai 2, default 0
*/
class Facility: public Cell{

};


/**
 * @class Road
 * Kelas Road, cellID bernilai 21
 * @param type
 * type entrance bernilai 1, exit bernilai 2, default 0
 */
class Road: public Facility{
	public:
		//ctor, dtor, cctor

		/** @brief Membuat road dengan X dan Y 0 dan cellID 21 dan tipe 0
		*/
		Road();

		/** @brief Membuat road dengan X dan Y terdefinisi dan cellID 21 dan tipe 0
		*/
		Road(int x, int y);

		/** @brief Membuat road dengan X dan Y terdefinisi dan cellID 21 dan tipe terdefinisi
		*/
		Road(int x, int y, int type);
		
	private:
		int type;
		const char defaultCode = 'X';
};

/**
 * @class Resto
 * Kelas Resto, cellID bernilai 22
 */

class Resto: public Facility{
	public:
		//ctor, dtor, cctor

		/** @brief Membuat Resto dengan X dan Y 0 dan cellID 22
		*/
		Resto();

		/** @brief Membuat Resto dengan X dan Y terdefinisi dan cellID 22
		*/
		Resto(int x, int y);
	private:
		const char defaultCode = 'R';
};

/**
 * @class Park
 * Kelas Park, cellID bernilai 23
 *
 */

class Park: public Facility{
	public:
		//ctor, dtor, cctor

		/** @brief Membuat Park dengan X dan Y terdefinisi dan cellID 23
		*/
		Park();

		/** @brief Membuat Park dengan X dan Y terdefinisi dan cellID 23
		*/
		Park(int x, int y);
	private:
		const char defaultCode = 'P';
};

#endif
