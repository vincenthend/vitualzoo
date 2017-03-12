#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;
/** @class Animal
  * Kelas Animal 
  * @param habitat
  * 0 = land, 1 = air, 2 = water
  */
class Animal {
public:	
   /** @brief Menuliskan interaksi dengan hewan ke layar.
     */
	virtual void interact() = 0;
	
   /** @brief Menghitung jumlah makanan yang dibutuhkan hewan setiap harinya.
     * @return Jumlah makanan yang dibutuhkan hewan setiap harinya.
     */
	int getFoodQuantity ();

   /** @brief Mengembalikan jenis makanan yang dibutuhkan hewan.
     * @return Kode makanan yang dibutuhkan hewan, 1 untuk herbivora, 2 untuk karnivora dan 3 untuk omnivora.
     */
	int getFoodType();
	
   /** @brief Mengembalikan posisi absis hewan.
     * @return Posisi absis hewan.
     */
	int getLocationX();
	
   /** @brief Mengembalikan posisi ordinat hewan.
     * @return Posisi ordinat hewan.
     */
	int getLocationY();
	
   /** @brief Mengembalikan status jinak hewan.
     * @return True jika jinak dan false jika tidak jinak.
     */
	int getTame();

	/** @brief Mengembalikan nilai type hewan.
	* @return Nilai type hewan.
	*/
	int getType();
	
   /** @brief Memindahkan hewan sejauh x, y
     */
	void move(int x, int y);
	
protected:
	bool habitat[3] = {false, false, false};
	
private:
	int type;
	int locX;
	int locY;
	int weight;
	int food_Weight;
	int foodType;
	bool tame;
};

/** @class landAnimal
  * Kelas landAnimal 
  */
class landAnimal : virtual public Animal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    landAnimal();
	
private:
};

/** @class waterAnimal
  * Kelas waterAnimal 
  */
class waterAnimal : virtual public Animal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    waterAnimal();
	
private:
};

/** @class airAnimal
  * Kelas airAnimal 
  */
class airAnimal : virtual public Animal	 {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    airAnimal();
	
private:
};
#endif
