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
#include "kalkulator.h"

using namespace std;

class ArabCalc : public kalkulator<float> {
    public:
		void Print(Stack<float> bil,Stack<string>operatorx); //tools debug
		ArabCalc(string ekspresi,int mode,int size);
		~ArabCalc();
        float Calculate();
		void SmallCalculate(Stack<float> &bil,Stack<string> &operatorx);
		float CalculateInfix();
		float CalculatePrefix();
		float CalculatePostfix();

    private:
        Stack<float> bil;
        Stack<string> operatorx;
		string ekspresi;
		int mode;
};

#endif

