/**
 * @author 13512096 Kevin
 * @file superkalkulator.h
 * @class superkalkulator
 * @brief Kelas besar untuk menangani masukan untuk input, setting, dan run kalkulator
 */

#ifndef superkalkulator_H
#define superkalkulator_H

#include <string>
#include "Stack.h"
#include <sstream>
using namespace std;
class superkalkulator{
	public:
		superkalkulator();
		~superkalkulator();
		int getCountLog();
		void WriteLog(string str);
		void Save();
		void Input(string input);
		void Undo(int n);
		void Redo(int n);
		void setMode(int n);
		void setKalkulator(int n);
		void runKalkulatorArab(string input);
		void runKalkulatorLogic(string input);
		void runKalkulatorRomawi(string input);
		Stack<string> getLog();
		int CheckEkspresiType(string input);
		void Set();
		void ShowMem(int n);
		void ShowAll();
	private:
		Stack<string> Log;
		int modeekspresi;
		int modekalkulator;
};
#endif
