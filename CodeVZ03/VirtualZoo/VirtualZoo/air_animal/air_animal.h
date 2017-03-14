#include "../animal/animal.h"

#ifndef AIR_ANIMAL_H
#define AIR_ANIMAL_H
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

class Pelican : public AirAnimal {
public:
	Pelican();
	void interact();
	void render();
};
class Owl : public AirAnimal {
public:
	Owl();
	void interact();
	void render();
};
class Pigeon : public AirAnimal {
public:
	Pigeon();
	void interact();
	void render();
};
class Canary : public AirAnimal {
public:
	Canary();
	void interact();
	void render();
};
class Bat : public AirAnimal {
public:
	Bat();
	void interact();
	void render();
};
class Eagle : public AirAnimal {
public:
	Eagle();
	void interact();
	void render();
};
class Toucan : public AirAnimal {
public:
	Toucan();
	void interact();
	void render();
};

#endif
