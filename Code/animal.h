#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "renderable.h"

using namespace std;
/** @class Animal
  * Kelas Animal 
  * @param habitat
  * 0 = land, 1 = water, 2 = air
  */
class Animal : public Renderable {
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

	/** @brief Mengembalikan nilai type hewan.
	* @return habitat yang dapat ditinggali hewan
	*/
	bool* getHabitat();

	/** @brief Mengatur nilai X hewan
	* @param x lokasi X hewan
	*/
	void setLocationX(int x);

	/** @brief Mengatur nilai y hewan
	* @param x lokasi y hewan
	*/
	void setLocationY(int y);
	
protected:
	int type;
	bool habitat[3] = {false, false, false};
	int weight;
	int food_Weight;
	int foodType;
	bool tame;
	
private:
	int locX;
	int locY;
};
#endif
