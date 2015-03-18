#ifndef RomanCalc_H
#define RomanCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class RomanCalc {
    public:
		RomanCalc(string ekspresi,int mode,int size);
		~RomanCalc();
        int RomantoDec(const string& s);
        string DectoRoman(int d);
        string Calculate();
		void SmallCalculate(Stack<float> &bil,Stack<string> &operatorx);
		
    private:
        Stack<int> bil;
        Stack<string> operatorx;
		int mode;
		string ekspresi;
};

#endif

