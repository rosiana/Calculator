#ifndef ekspresi_H
#define ekspresi_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "boolean.h"
#include <vector>
using namespace std;

class ekspresi{
	public:
		ekspresi();
		~ekspresi();
		ekspresi(string s);
		void convertRoman();
		void convert
	private:
		string input;
		vector angka;
		vector operatorinput;
};
#endif