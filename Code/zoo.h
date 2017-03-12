#include <iostream>
#include "cell.h"

#ifndef ZOO_H
#define ZOO_H


/** @class 	Zoo
 * Kelas Zoo
 *
 */

class Zoo{
	public:
		/** @brief Membuat Zoo dengan width 21 dan height 21
    	 */
		Zoo();
		
		/** @brief Membuat Zoo dengan width w dan height h dengan nama name
    	 */
		Zoo(int w, int h);
		
		/** @brief Menghancurkan kebun binatang, dan menghapus cell
    	 */
		~Zoo();
		
		/** @brief Melakukan copy pada kebun binatang
    	 */
		Zoo(const Zoo& Z);

		/** @brief Mengembalikan nilai width pada zoo
		*/
		int GetWidth();

		/** @brief Mengembalikan nilai height pada zoo
		*/
		int GetHeight();
	
	private:
		int width;
		int height;
		Cell *** c;
};

#endif

//copas ke zoo.cpp

Zoo::Zoo(){
	int i;
	
	width = 21;
	height = 21;
	c = new Cell** [width];
	
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
	}
}

Zoo::Zoo(int w, int h){
	int i;
	
	width = w;
	height = h;
	c = new Cell** [width];
	
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
	}
}

Zoo::~Zoo(){
	int i;
	
	for(i = 0; i<width; i++){
		delete [] c[i];
	}
	delete [] c;
}

Zoo::Zoo(const Zoo& Z){
	int i,j;
	
	width = Z.width;
	height = Z.height;
	c = new Cell** [width];
	for(i = 0; i<width; i++){
		c[i] = new Cell* [height];
		for(j = 0; i<height; i++){
			c[i][j] = Z.c[i][j];
		}
	}	
}