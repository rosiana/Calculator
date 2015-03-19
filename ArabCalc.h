/**
 * @author
 * @file ArabCalc.h
 * @class ArabCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand angka arab
 */

#ifndef ArabCalc_H
#define ArabCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Stack.h"
using namespace std;

class ArabCalc {
    public:
		void Print(Stack<float> bil,Stack<string>operatorx); //tools debug
		ArabCalc(string ekspresi,int mode,int size);
		~ArabCalc();
        float Calculate();
		void SmallCalculate(Stack<float> &bil,Stack<string> &operatorx);
		float CalculateInfix();
		int CalculatePrefix();
		int CalculatePostfix();

    private:
        Stack<float> bil;
        Stack<string> operatorx;
		string ekspresi;
		int mode;
};

#endif

