/**
 * @author 13512088 Annisaur Rosi Lutfiana
 * @file RomanCalc.h
 * @class RomanCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand angka romawi
 */

#ifndef RomanCalc_H
#define RomanCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Stack.h"
#include "kalkulator.h"

using namespace std;

class RomanCalc : public kalkulator<string> {
    public:
		//void Print(Stack<int> bil,Stack<string>operatorx); //tools debug
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

