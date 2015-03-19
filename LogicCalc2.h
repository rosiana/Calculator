#ifndef LogicCalc2_H
#define LogicCalc2_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <math.h>
#include "Stack.h"
using namespace std;

class LogicCalc2{
	public:
		LogicCalc(string ekspresi, int mode);
		~LogicCalc();
		bool Calculate();
		bool CalculatePrefix();
		bool CalculateInfix();
		bool CalculatePostfix();
		void Evaluate();
		
	private:
		string ekspresi;
		int mode;
		Stack<bool> operand;
		Stack<string> operatorx;
};

#endif
