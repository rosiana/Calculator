#ifndef RomanCalc_H
#define RomanCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Stack.h"
using namespace std;

class RomanCalc {
    public:
		RomanCalc(string ekspresi,int mode,int size);
		~RomanCalc();
        int RomantoDec(string s);
        string DectoRoman(int d);
        string Calculate();
		void SmallCalculate(Stack<int> &bil, Stack<string> &operatorx);
		int CalculateInfix();
		int CalculatePrefix();
		int CalculatePostfix();
		

    private:
        Stack<int> bil;
        Stack<string> operatorx;
		int mode;
		string ekspresi;
};

#endif

