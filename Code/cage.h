#ifndef CAGE_H
#define CAGE_H


/**
 * @class 	Cage
 * Kelas Cage
 */

 
class Cage{
	public :
		Cage();
		
	private:
		int n_animal = 0;
		int n_cell = 0;
		Animal ** a;
		Cell ** c;
	
};

#endif
