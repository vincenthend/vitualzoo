#ifndef RENDERABLE_H
#define RENDERABLE_H


/** @class Renderable
 * Mengatur render
 */

class Renderable{
	public:
		/** @brief Melakukan print berdasarkan tipe
    	 */
		virtual void render() = 0;	
};

#endif