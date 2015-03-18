#include <iostream>
#include <stdlib.h>

#include "RomanCalc.h"
#include "Stack.h"

using namespace std;

RomanCalc::RomanClac(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = eksrepsi;
	this->mode = mode;
}
int RomanCalc::RomantoDec(string s) {
	int i = 0;
    int dec = 0;
    while(i < s.length())
    {
		if (s[i] == 'M') {
			dec += 1000;
		}

		else if (s[i] == 'D')
		{
			if(i < s.length() + 1)
			{
				if(s[i+1] == 'M') {
                    dec -= 500;
				}
				else {
                    dec += 500;
                }
			}
		}
        else if (s[i] == 'C')
		{
			if(i < s.length() + 1)
			{
				if(s[i+1] == 'M' || s[i+1] == 'D') {
                    dec -= 100;
                }
				else {
                    dec += 100;
                }
			}
		}
        else if (s[i] == 'L')
		{
			if(i < s.length() + 1)
			{
				if(s[i+1] == 'M' || s[i+1] == 'D' || s[i+1] == 'C') {
                    dec -= 50;
                }
				else {
                    dec += 50;
                }
			}
		}
        else if (s[i] == 'X')
		{
			if(i < s.length() + 1)
			{
				if(s[i+1] == 'M' || s[i+1] == 'D' || s[i+1] == 'C' || s[i+1] == 'L') {
                    dec -= 10;
                }
				else {
                    dec += 10;
                }
			}
		}

		else if (s[i] == 'V')
		{
			if(i < s.length() + 1)
			{
				if(s[i+1] == 'M' || s[i+1] == 'D' || s[i+1] == 'C' || s[i+1] == 'L' || s[i+1] == 'X') {
                    dec -= 5;
                }
				else {
                    dec += 5;
                }
			}
		}

		else if (s[i] == 'I')
		{
			if(i < s.length()+1)
			{
				if(s[i+1] == 'M' || s[i+1] == 'D' || s[i+1] == 'C' || s[i+1] == 'L' || s[i+1] == 'X' || s[i+1] == 'V') {
                    dec -= 1;
                }
				else {
                    dec += 1;
                }
			}
		}
		else
		{
			// error
		}
		i++;
    }
	return dec;
}

string RomanCalc::DectoRoman (int d) {
    int dec[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string num[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string rom;

    for(int i = 0; i < 13; i++) {
        while (d >= dec[i]) {
            d -= dec[i];
            numeral.append(num[i]);
        }
    }
    return rom;
}

RomanCalc::~RomanCalc(){
	//no memory to free
}

string RomanCalc::Calculate(){

}

void RomanCalc::SmallCalculate(Stack<float> &bil,Stack<string> &operatorx)
{
	float popbil1;
	float popbil2;
	string dumpoperator;
	float dumpbil;
	popbil1 = bil.getLastData();
	bil>>dumpbil;
	popbil2 = bil.getLastData();
	bil>>dumpbil;
	string popoperator = operatorx.getLastData();
	operatorx>>dumpoperator;
	if(popoperator == "*")
	{
		bil<< popbil2*popbil1;
	}
	else if(popoperator == "/")
	{
		bil<< popbil2/popbil1;
	}
	else if(popoperator == "%")
	{	
		int tempint1 = (int) floor(popbil1 + 0.5);
		int tempint2 = (int) floor(popbil2 + 0.5);
		float hasil = (float)(tempint2%tempint1);
		bil<< hasil;
	}
	
	else if(popoperator == "+")
	{
		bil<< popbil2+popbil1;
	}
	else if(popoperator == "-")
	{
		bil<< popbil2-popbil1;
	}
}
