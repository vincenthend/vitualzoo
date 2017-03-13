#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream myfile("map.txt");
	string S;
	getline(myfile,S);
	int i = 0;
	int temp = 0;
	cout << S[i] << endl;
	while ((S[i] >= '0') && (S[i] <= '9')){
		cout << i << endl;
		temp = (temp * 10) + (S[i] - '0');
		i++;
	}
	cout << temp << endl;
	return 0;
}
