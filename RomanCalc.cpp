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
			cout<<"something wrong"<<endl;
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
	int hasil;
	if(mode == 2)//infix
	{
		hasil = CalculateSufix();
	}
	return hasil;
}

void RomanCalc::SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
{
	int popbil1;
	int popbil2;
	string dumpoperator;
	int dumpbil;
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
	else if(popoperator == ":")
	{
		bil<< popbil2/popbil1;
	}
	else if(popoperator == "/")
	{
		bil<< popbil2/popbil1;
	}
	else if(popoperator == "%")
	{	
		bil<< tempint2%tempint1;
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
int RomanCalc::CalculateSufix()
{
	string popbil1,popbil2,popoperator;
	string dumpoperator;
	int dumpbil;
	int m = 0;
	int coperator = 0;
	string ekspresitemp = ekspresi;
	while(ekspresitemp.length()!=0)
	{
		string temp;
		int isCompleteRead = 0;
		int ctemp = 0;
		while(ekspresitemp[0] == 'M' || ekspresitemp[0] == 'D' || ekspresitemp[0] == 'C' || ekspresitemp[0] == 'L' || ekspresitemp[0] == 'X'
		|| ekspresitemp[0] == 'V'|| ekspresitemp[0] == 'I')
		{	
			temp += ekspresitemp.substr(0,1);
			ekspresitemp.erase(0,1);
			ctemp++;
			isCompleteRead = 1;
		}
		if(isCompleteRead == 1)
		{	
			bil<< convert(temp);
		}
		if(ekspresitemp[0] == '+' || ekspresitemp[0] == '-' || ekspresitemp[0] == '*'|| ekspresitemp[0] == ':'  || ekspresitemp[0] == '/' || ekspresitemp[0] == '%' || ekspresitemp[0] == '('|| ekspresitemp[0] == ')')
		{
			if(operatorx.isEmpty() || ekspresitemp[0] == '(')
			{
				operatorx<<ekspresitemp.substr(0,1);
				coperator++;
			}
			else
			{
				if(ekspresitemp[0] == '+' || ekspresitemp[0] == '-')
				{
					if(operatorx.getLastData() == "*" || operatorx.getLastData() == ":"  || operatorx.getLastData() == "/" || operatorx.getLastData() == "%" || operatorx.getLastData() == "+" || operatorx.getLastData() == "-")
					{
						SmallCalculate(bil,operatorx);
						operatorx<<ekspresitemp.substr(0,1);
					}
					else
					{
						operatorx<<ekspresitemp.substr(0,1);
						coperator++;
					}
				}
				else if(ekspresitemp[0] == '*' || ekspresitemp[0] == '/' || ekspresitemp[0] == '%' || ekspresitemp[0] == ':')
				{
					
					if(operatorx.getLastData() == "*" || operatorx.getLastData() == "/" || operatorx.getLastData() == ":" || operatorx.getLastData() == "%")
					{
						SmallCalculate(bil,operatorx);
						operatorx<<ekspresitemp.substr(0,1);
					}
					else
					{
						operatorx<<ekspresitemp.substr(0,1);
						coperator++;
					}
				}
				else if(ekspresitemp[0] == ')')
				{
					while(operatorx.getLastData() != "(")
					{
						SmallCalculate(bil,operatorx);
					}
					operatorx>>dumpoperator;
				}
				
			}
			ekspresitemp.erase(0,1);
		}
	}
	while(!operatorx.isEmpty())
	{
		SmallCalculate(bil,operatorx);
	}
	return bil.getLastData();
}