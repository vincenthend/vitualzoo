#include "animal.h"

#ifndef AIRANIMAL_H
#define AIRANIMAL_H
/** @class airAnimal
  * Kelas airAnimal 
  */
class AirAnimal : virtual public Animal	 {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    AirAnimal();
	
private:
};

class Pelikan: public AirAnimal {
	public :
	void interact();
}; 
class Capung: public AirAnimal {
	public :
	void interact();
}; 
class Kunang-kunang": public AirAnimal {
	public :
	void interact();
}; 
class Nyamuk: public AirAnimal {
	public :
	void interact();
}; 
class Puyuh: public AirAnimal {
	public :
	void interact();
}; 
class Gagak: public AirAnimal {
	public :
	void interact();
}; 
class Kepik: public AirAnimal {
	public :
	void interact();
}; 



#endif
