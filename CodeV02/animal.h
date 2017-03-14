#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;
/** @class Animal
  * Kelas Animal 
  * @param habitat
  * 0 = land, 1 = water, 2 = air
  */
class Animal{
public:	
	//ctor dan cctor
	Animal(int id);

   /** @brief Menuliskan interaksi dengan hewan ke layar.
     */
	virtual void interact();

	//Setter dan Getter
	
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

	/** @brief Mengatur nilai X hewan
	* @param x lokasi X hewan
	*/
	void setLocationX(int x);

	/** @brief Mengatur nilai y hewan
	* @param x lokasi y hewan
	*/
	void setLocationY(int y);

	/** @brief Mengembalikan nilai type hewan.
	* @return Nilai type hewan.
	*/
	int getType();

	/** @brief Mengembalikan nilai habitat hewan.
	* @return habitat yang dapat ditinggali hewan
	*/
	bool* getHabitat();

	//Fungsi Lain

	/** @brief Memindahkan hewan sejauh x, y
	*/
	void move(int x, int y);	
	
	/** @brief Melakukan pencetakan terhadap code
	*/
	void render();
	int getCEnemy();
	int* getEnemyList();
	
private:
	bool habitat[3] = {false, false, false};
	int type;
	int locX;
	int locY;
	int weight;
	int food_Weight;
	int foodType;
	char code;
	string sound;
	int* EnemyID;
	int cenemy;
};
#endif
