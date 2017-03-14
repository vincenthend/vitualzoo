#include "animal.h"

#ifndef WATER_ANIMAL_H
#define WATER_ANIMAL_H
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

class Salmon : public WaterAnimal {
public:
	Salmon();
	void interact();
	void render();
};
class Whale : public WaterAnimal {
public:
	Whale();
	void interact();
	void render();
};
class Squid : public WaterAnimal {
public:
	Squid();
	void interact();
	void render();
};
class Goldfish : public WaterAnimal {
public:
	Goldfish();
	void interact();
	void render();
};
class Turtle : public WaterAnimal {
public:
	Turtle();
	void interact();
	void render();
};
class Seal : public WaterAnimal {
public:
	Seal();
	void interact();
	void render();
};
class Dolphin : public WaterAnimal {
public:
	Dolphin();
	void interact();
	void render();
};

#endif
