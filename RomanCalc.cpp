/**
 * @author 13512088 Annisaur Rosi Lutfiana
 * @file RomanCalc.cpp
 * @class RomanCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand angka romawi
 */

#include <iostream>
#include <stdlib.h>

#include "RomanCalc.h"

using namespace std;
//tools debug
/*void RomanCalc::Print(Stack<int> bil,Stack<string>operatorx){
	cout<<"Stack bilangan"<<endl;
	for(int i = 0;i<=bil.getDataCount()-1;i++)
	{
		cout<<i<<"). "<<bil.getData(i)<<endl;
	}
	cout<<"Stack operator"<<endl;
	for(int j = 0;j<=operatorx.getDataCount()-1;j++)
	{
		cout<<j<<"). "<<operatorx.getData(j)<<endl;
	}
}*/

/**
 * @fn RomanCalc(string ekspresi,int mode,int size)
 * @brief Konstruktor parameter kalkulator romawi
 */
RomanCalc::RomanCalc(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

/**
 * @fn ~RomanCalc()
 * @brief Destruktor kalkulator romawi
 */
RomanCalc::~RomanCalc(){
	//no memory to free
}

/**
 * @fn RomantoDec(string s)
 * @brief Converter angka romawi ke desimal (arab) untuk perhitungan
 */
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

/**
 * @fn DectoRoman(int d)
 * @brief Converter angka desimal (arab) ke romawi untuk hasil
 */
string RomanCalc::DectoRoman(int d) {
    int dec[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string num[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string rom;
    for(int i = 0; i < 13; i++) {
        while (d >= dec[i]) {
            d -= dec[i];
            rom.append(num[i]);
        }
    }
    return rom;
}

/**
 * @fn Calculate()
 * @brief Penghitungan sesuai mode ekspresi (prefix, infix, postfix)
 */
string RomanCalc::Calculate(){
	int hasil;
	if(mode == 1)
    {
		hasil = CalculatePrefix();
	}
	else if(mode == 2)
	{
		hasil = CalculateInfix();
	}
	else if(mode == 3)
	{
		hasil = CalculatePostfix();
	}
	return DectoRoman(hasil);
}

/**
 * @fn SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
 * @brief Prosedur penentu operator untuk perhitungan mode infix
 */
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
		bil<< popbil2%popbil1;
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

/**
 * @fn CalculateInfix()
 * @brief Penghitungan mode infix
 */
int RomanCalc::CalculateInfix()
{
	string popbil1,popbil2,popoperator;
	string dumpoperator;
	int dumpbil;
	int m = 0;
	int coperator = 0;
	int hasil;
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
			bil<< RomantoDec(temp);
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
	hasil = bil.getLastData();
	return hasil;
}

/**
 * @fn CalculatePrefix()
 * @brief Penghitungan mode prefix
 */
int RomanCalc::CalculatePrefix() {
    char buffer[15];
    int i,op1, op2, len, j, x;
    Stack<int> s;
	int dumpint;
	string tempekspresi = ekspresi;
    len = tempekspresi.length();
    j = 0;
    for(i=len-1; i>=0; i--){

        if(tempekspresi[i] == 'M' || tempekspresi[i] == 'D' || tempekspresi[i] == 'C' || tempekspresi[i] == 'L' || tempekspresi[i] == 'X'
		|| tempekspresi[i] == 'V'|| tempekspresi[i] == 'I'){
            buffer[j++] = tempekspresi[i];
        }
		
        else if(tempekspresi[i]==' '){
			if(j>0){
				char tempbuffer[15];
				int counter = 0;
				buffer[j] = '\0';
				for(int i =j-1;i>=0;i--)
				{
					tempbuffer[counter] = buffer[i];
					counter++;
				}
				tempbuffer[counter] = '\0';
				x = RomantoDec(tempbuffer);
				s<<x;
				j = 0;
            }
        }
        else if(tempekspresi[i]=='+' || tempekspresi[i]=='-' || tempekspresi[i]=='*' || tempekspresi[i]==':' || tempekspresi[i]=='%' || tempekspresi[i]=='/'){
            op1 = s.getLastData();
            s>>dumpint;
            op2 = s.getLastData();
            s>>dumpint;
            switch(tempekspresi[i]){
                case '+':
                    s<<op2 + op1;
                    break;
                case '-':
                    s<<(op2 - op1);
                    break;
                case '*':
                    s<<(op2 * op1);
                    break;
                case ':':
                    s<<(op2 / op1);
                    break;
                case '%':
                    s<<(op2 % op1);
                    break;
                case '/':
                    int div;
                    div = (int)floor(op2 / op1);
                    s<<(div);
                    break;
            }
        }
    }
    return s.getLastData();
}

/**
 * @fn CalculatePostfix()
 * @brief Penghitungan mode postfix
 */
int RomanCalc::CalculatePostfix() {

    int i,op1, op2, len, j, x;
    Stack<int> s;
	string ekspresitemp = ekspresi;
    len = ekspresitemp.length();
    j = 0;
	string buffer;
	int dumpint;
    for(i=0; i<len;i++){

        if(ekspresitemp[i] == 'M' || ekspresitemp[i] == 'D' || ekspresitemp[i] == 'C' || ekspresitemp[i] == 'L' || ekspresitemp[i] == 'X'
		|| ekspresitemp[i] == 'V'|| ekspresitemp[i] == 'I'){
            buffer += ekspresitemp.substr(i,1);
			j++;
        }
        else if(ekspresitemp[i]==' '){
            if(j>0){
                x = RomantoDec(buffer);
                s<<x;
				buffer.erase(0,j);
				j=0;
            }
        }
        else if(ekspresitemp[i]=='+' || ekspresitemp[i]=='-' || ekspresitemp[i]=='*' || ekspresitemp[i]==':' || ekspresitemp[i]=='%' || ekspresitemp[i]=='/'){
            op1 = s.getLastData();
            s>>dumpint;
            op2 = s.getLastData();
            s>>dumpint;
            switch(ekspresitemp[i]){
                case '+':
                    s<<(op2 + op1);
                    break;
                case '-':
                    s<<(op2 - op1);
                    break;
                case '*':
                    s<<(op2 * op1);
                    break;
                case ':':
                    s<<(op2 / op1);
                    break;
                case '%':
                    s<<(op2 % op1);
                    break;
                case '/':
                    s<<(op2 / op1);
                    break;
            }
        }
    }
    return s.getLastData();
}
