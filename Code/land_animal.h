#include "animal.h"

#ifndef LAND_ANIMAL_H
#define LAND_ANIMAL_H
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

class Chicken : public LandAnimal {
public:
	Chicken();
	void interact();
	void render();
};
class Cat : public LandAnimal {
public:
	Cat();
	void interact();
	void render();
};
class Cow : public LandAnimal {
public:
	Cow();
	void interact();
	void render();
};
class Mouse : public LandAnimal {
public:
	Mouse();
	void interact();
	void render();
};
class Goat : public LandAnimal {
public:
	Goat();
	void interact();
	void render();
};
class Llama : public LandAnimal {
public:
	Llama();
	void interact();
	void render();
};
class Snake : public LandAnimal {
public:
	Snake();
	void interact();
	void render();
};
class Sheep : public LandAnimal {
public:
	Sheep();
	void interact();
	void render();
};
class Chameleon : public LandAnimal {
public:
	Chameleon();
	void interact();
	void render();
};
#endif
