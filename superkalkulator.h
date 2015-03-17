#ifndef superkalkulator_H
#define superkalkulator_H

#include <string>
#include "Stack.h"
using namespace std;
class superkalkulator{
	public:
		superkalkulator();
		~superkalkulator();
		void Print();
		void getCountLog();
		void WriteLog(string str);
		void Save();
		void Input(string input);
		void Undo(int n);
		void setMode(int n);
		void setKalkulator(int n);
		void runKalkulatorArab();
		void runKalkulatorLogika();
		void runKalkulatorRomawi();
	private:
		Stack<string> Log(100);
		int countLog;
		int modeekspresi;
		int modekalkulator;
};
#endif