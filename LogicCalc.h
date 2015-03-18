/**
 * @author
 * @file LogicCalc.h
 * @class LogicCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand angka arab
 */

#ifndef LogicCalc_H
#define LogicCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Stack.h"
using namespace std;

class LogicCalc {
    public:
		void Print(Stack<int> bil,Stack<string>operatorx);
		LogicCalc(string ekspresi,int mode,int size);
		~LogicCalc();
        int Calculate();
		void SmallCalculate(Stack<int> &bil,Stack<string> &operatorx);
		int CalculateInfix();
		int CalculatePrefix();
		int CalculatePostfix();

    private:
        Stack<int> bil;
        Stack<string> operatorx;
		string ekspresi;
		int mode;
};

#endif

