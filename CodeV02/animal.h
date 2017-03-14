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
	virtual void Interact();

	//Setter dan Getter
	
   /** @brief Menghitung jumlah makanan yang dibutuhkan hewan setiap harinya.
     * @return Jumlah makanan yang dibutuhkan hewan setiap harinya.
     */
	int GetFoodQuantity();

   /** @brief Mengembalikan jenis makanan yang dibutuhkan hewan.
     * @return Kode makanan yang dibutuhkan hewan, 1 untuk herbivora, 2 untuk karnivora dan 3 untuk omnivora.
     */
	int GetFoodType();
	
   /** @brief Mengembalikan posisi absis hewan.
     * @return Posisi absis hewan.
     */
	int GetLocationX();
	
   /** @brief Mengembalikan posisi ordinat hewan.
     * @return Posisi ordinat hewan.
     */
	int GetLocationY();

	/** @brief Mengatur nilai X hewan
	* @param x lokasi X hewan
	*/
	void SetLocationX(int x);

	/** @brief Mengatur nilai y hewan
	* @param x lokasi y hewan
	*/
	void SetLocationY(int y);

	/** @brief Mengembalikan nilai type hewan.
	* @return Nilai type hewan.
	*/
	int GetType();

	/** @brief Mengembalikan nilai habitat hewan.
	* @return habitat yang dapat ditinggali hewan
	*/
	bool* GetHabitat();

	//Fungsi Lain

	/** @brief Memindahkan hewan sejauh x, y
	*/
	void Move(int x, int y);	
	
	/** @brief Melakukan pencetakan terhadap code
	*/
	void Render();
	int GetCEnemy();
	int* GetEnemyList();
	
private:
	bool habitat[3] = {false, false, false};
	int type;
	int loc_x;
	int loc_y;
	int weight;
	int food_weight;
	int food_type;
	char code;
	string sound;
	int* enemy_id;
	int c_enemy;
};
#endif
