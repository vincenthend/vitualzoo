#include "animal.h"

#ifndef LANDANIMAL_H
#define LANDANIMAL_H
/** @class landAnimal
  * Kelas landAnimal 
  */
class LandAnimal : virtual public Animal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    LandAnimal();
	
private:
};

class Kucing: public LandAnimal {
	public :
	void interact();
}; 
class Sapi: public LandAnimal {
	public :
	void interact();
}; 
class Kelinci: public LandAnimal {
	public :
	void interact();
}; 
class Kambing: public LandAnimal {
	public :
	void interact();
}; 
class Kuda: public LandAnimal {
	public :
	void interact();
}; 
class Ular: public LandAnimal {
	public :
	void interact();
}; 
class Semut: public LandAnimal {
	public :
	void interact();
}; 
class Bunglon: public LandAnimal {
	public :
	void interact();
}; 

#endif
