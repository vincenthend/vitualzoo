//Header to include all files
//Standard Headers
#include <iostream>
#include "driver.h"

int main()
{
	int choice;

	//Inisialisasi Zoo disini
	Driver D(4,4);
	choice = 0;
	do{
		cout << "Menu :" << endl << "1. Tampilkan Zoo" << endl << "2. Mulai Tour" << endl << "9. Keluar" << endl << "Pilihan : ";
		cin >> choice;

		ClearScreen();
		if (choice == 1) {
			do {
				cout << "1. Tampilkan seluruhnya" << endl << "2. Tampilkan sebagian"; //belum selesai
			} while (choice != 9);
		}
	} while (choice != 9);

    return 0;
}
