#ifndef ZOO_H
#define ZOO_H


#include <iostream>
#include "cell.h"


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
		Zoo(int w, int h, string name);
		
		/** @brief Menghancurkan kebun binatang, dan menghapus cell
    	 */
		~Zoo();
		
		/** @brief Melakukan copy pada kebun binatang
    	 */
		Zoo(Zoo& Z);
	
	private:
		int width;
		int height;
		string name;
		Cell ** c;
};

#endif
