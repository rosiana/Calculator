/**
 * @author
 * @file RelationalCalc.h
 * @class RelationalCalc
 * @brief Kelas untuk perbandingan (relasional) dengan ekspresi angka arab
 */

#ifndef RelationalCalc_H
#define RelationalCalc_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Stack.h"
#include "kalkulator.h"
#include "ArabCalc.h"

using namespace std;

class RelationalCalc : public kalkulator<float> {
    public:
		RelationalCalc(string ekspresi, int mode, int size);
		~RelationalCalc();
        float Calculate();
		void SmallCalculate(Stack<float> &bil,Stack<string> &operatorx);
		float CalculateInfix();
		float CalculatePrefix();
		float CalculatePostfix();

    private:
        ArabCalc eks1;
        ArabCalc eks2;
};

#endif
