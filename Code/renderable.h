#ifndef RENDERABLE_H
#define RENDERABLE_H


/** @class 	Renderable
 * Mengatur render
 */

class Renderable(){
	public:
		/** @brief Membuat Cell pada X dan Y tertentu dengan ID tertentu.
    	 */
		Renderable();
		
		/** @brief Membuat Cell pada X dan Y tertentu dengan ID tertentu.
    	 */
		~Renderable();
		
		/** @brief Membuat Cell pada X dan Y tertentu dengan ID tertentu.
    	 */
		Renderable(Renderable& R);
		
		/** @brief Melakukan print berdasarkan tipe
    	 */
		virtual	Render() = 0;
	
};

#endif
