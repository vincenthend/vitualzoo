#include "animal.h"

#ifndef WATERANIMAL_H
#define WATERANIMAL_H
/** @class waterAnimal
  * Kelas waterAnimal 
  */
class WaterAnimal : virtual public Animal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    WaterAnimal();
	
private:
};

class Salmon: public WaterAnimal {
	public :
	void interact();
}; 
class Bushido: public WaterAnimal {
	public :
	void interact();
}; 
class Cumi-cumi: public WaterAnimal {
	public :
	void interact();
}; 
class Mas: public WaterAnimal {
	public :
	void interact();
}; 
class Penyu: public WaterAnimal {
	public :
	void interact();
}; 
class AnjingLaut: public WaterAnimal {
	public :
	void interact();
}; 
class KudaLaut: public WaterAnimal {
	public :
	void interact();
}; 


#endif
