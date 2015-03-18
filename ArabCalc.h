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
		ArabCalc(string ekspresi,int mode,int size);
		~ArabCalc();
        float Calculate();
		float CalculateInfix();
		void SmallCalculate(Stack<float> &bil,Stack<string> &operatorx);
		int CalculatePrefix();
		int CalculatePostfix();
    private:
        Stack<float> bil;
        Stack<string> operatorx;
		string ekspresi;
		int mode;
};

#endif

