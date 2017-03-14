#include "air_animal.h"
#include "land_animal.h"
#include "water_animal.h"

#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H
/** @class airAnimal
  * Kelas airAnimal 
  */

class Penguin : public WaterAnimal, public LandAnimal {
public:
	Penguin();
	void interact();
	void render();
};

#endif
