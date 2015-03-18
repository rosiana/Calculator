#include <iostream>
#include "superkalkulator.h"
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(){
	superkalkulator tes;
	string masukan = "";
	cout<<"Selamat datang"<<endl;
	cout<<"Silahkan masukkan perintah atau exit untuk keluar"<<endl;
	cout<<"Masukan : ";
	std::getline(std::cin,masukan);
	while(masukan!="exit")
	{
		tes.Input(masukan);
		cout<<"Masukan : ";
		std::getline(std::cin,masukan);
	}
	return 0;
}