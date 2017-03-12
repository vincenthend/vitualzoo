#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;
/** @class Animal
  * Kelas Animal 
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
	
   /** @brief Memindahkan hewan sejauh x, y
     */
	void move(int x, int y);
	
protected:
	bool habitat[3] = {false, false, false};
	
private:
	int locX;
	int locY;
	int weight;
	int food_Weight;
	int foodType;
	bool tame;
};

/** @class LandAnimal
  * Kelas LandAnimal 
  */
class LandAnimal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    LandAnimal();
	
private:
};

/** @class WaterAnimal
  * Kelas WaterAnimal 
  */
class WaterAnimal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    WaterAnimal();
	
private:
};

/** @class AirAnimal
  * Kelas AirAnimal 
  */
class AirAnimal {
public:	
   /** @brief Konstruktor, menginisiasi.
     */
    AirAnimal();
	
private:
};
#endif
