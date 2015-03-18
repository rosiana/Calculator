#ifndef RomanCalc_H
#define RomanCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Stack.h"
using namespace std;

class RomanCalc {
    public:
		RomanCalc(string ekspresi,int mode,int size);
		~RomanCalc();
        string DectoRoman(int d);
		int RomantoDec(string s);
        string Calculate();
		void SmallCalculate(Stack<int> &bil,Stack<string> &operatorx);
		int CalculateInfix();
		
    private:
        Stack<int> bil;
        Stack<string> operatorx;
		int mode;
		string ekspresi;
};

#endif

