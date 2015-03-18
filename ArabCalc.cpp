/**
 * @author
 * @file ArabCalc.cpp
 * @class ArabCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand angka arab
 */

#include <iostream>
#include <stdlib.h>

#include "ArabCalc.h"

using namespace std;

/**
 * @fn ArabCalc(string ekspresi,int mode,int size)
 * @brief Konstruktor parameter kalkulator arab
 */
ArabCalc::ArabCalc(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

/**
 * @fn ~ArabCalc()
 * @brief Destruktor kalkulator arab
 */
ArabCalc::~ArabCalc(){
	//no memory to free
}

/**
 * @fn Calculate()
 * @brief Penghitungan sesuai mode ekspresi (prefix, infix, postfix)
 */
float ArabCalc::Calculate(){
	float hasil;
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
	return hasil;
}

/**
 * @fn SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
 * @brief Prosedur penentu operator untuk perhitungan mode infix
 */
void ArabCalc::SmallCalculate(Stack<float> &bil,Stack<string> &operatorx)
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
	else if(popoperator == ":")
	{
		bil<< popbil2/popbil1;
	}
	else if(popoperator == "/")
	{
		int a = (int) floor(popbil2/popbil1 + 0.5);
		bil<< a;
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

/**
 * @fn CalculateInfix()
 * @brief Penghitungan mode infix
 */
float ArabCalc::CalculateInfix(){
	string dumpoperator;
	float dumpbil;
	float hasil;
	string ekspresitemp = ekspresi;
	while(ekspresitemp.length() != 0)
	{
		char *temp =  new char[30];
		int isCompleteRead = 0;
		int ctemp = 0;
		while(ekspresitemp[0] == '0' || ekspresitemp[0] == '1' || ekspresitemp[0] == '2' || ekspresitemp[0] == '3' || ekspresitemp[0] == '4' || ekspresitemp[0] == '5'
		|| ekspresitemp[0] == '6'|| ekspresitemp[0] == '7' || ekspresitemp[0] == '8' || ekspresitemp[0] == '9' || ekspresitemp[0] == '.')
		{
			temp[ctemp] = ekspresitemp[0];
			ekspresitemp.erase(0,1);
			ctemp++;
			isCompleteRead = 1;
		}
		if(isCompleteRead == 1)
		{
			bil<< atof(temp);
		}
		if(ekspresitemp[0] == '+' || ekspresitemp[0] == '-' || ekspresitemp[0] == '*' || ekspresitemp[0] == ':' || ekspresitemp[0] == '/' || ekspresitemp[0] == '%' || ekspresitemp[0] == '('|| ekspresitemp[0] == ')')
		{
			if(operatorx.isEmpty() || ekspresitemp[0] == '(')
			{
				operatorx<<ekspresitemp.substr(0,1);

			}
			else
			{
				if(ekspresitemp[0] == '+' || ekspresitemp[0] == '-')
				{
					if(operatorx.getLastData() == "*" || operatorx.getLastData() == ":"|| operatorx.getLastData() == "/" || operatorx.getLastData() == "%" || operatorx.getLastData() == "+" || operatorx.getLastData() == "-")
					{
						SmallCalculate(bil,operatorx);
						operatorx<<ekspresitemp.substr(0,1);
					}
					else
					{
						operatorx<<ekspresitemp.substr(0,1);

					}
				}
				else if(ekspresitemp[0] == '*' || ekspresitemp[0] == '/' || ekspresitemp[0] == '%' || ekspresitemp[0] == ':')
				{

					if(operatorx.getLastData() == "*" || operatorx.getLastData() == "/" || operatorx.getLastData() == ":"  || operatorx.getLastData() == "%")
					{
						SmallCalculate(bil,operatorx);
						operatorx<<ekspresitemp.substr(0,1);
					}
					else
					{
						operatorx<<ekspresitemp.substr(0,1);
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
	//Cleaning
	while(!bil.isEmpty())
	{
		bil>>dumpbil;
	}
	while(!operatorx.isEmpty())
	{
		operatorx>>dumpoperator;
	}
	return hasil;
}

/**
 * @fn CalculatePrefix()
 * @brief Penghitungan mode prefix
 */
float ArabCalc::CalculatePrefix() {
    char buffer[15];
    int i, len, j;
    float op1, op2, x;
    Stack<float> s;
	float dumpfloat;
    len = ekspresi.length();
    j = 0;
    for(i=len-1; i>=0; i--){

        if((ekspresi[i]>='0' && ekspresi[i]<='9') || ekspresi[i]<='.'){
            buffer[j++] = ekspresi[i];
        }
        else if(ekspresi[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atof(buffer);
                s<<x;
                j = 0;
            }
        }
        else if(ekspresi[i]=='+' || ekspresi[i]=='-' || ekspresi[i]=='*' || ekspresi[i]==':' || ekspresi[i]=='%' || ekspresi[i]=='/'){
            op1 = s.getLastData();
            s>>dumpfloat;
            op2 = s.getLastData();
            s>>dumpfloat;
            switch(ekspresi[i]){
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
                case '%': // di c++ nggak bisa float mod float
                    while (op2 >= op1) {
                        op2 = op2 - op1;
                    }
                    s<<(op2);
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
float ArabCalc::CalculatePostfix() {
    char buffer[15];
    int i, len, j;
    float op1, op2, x;
    Stack<float> s;
    len = ekspresi.length();
    j = 0;
	float dumpfloat;
    for(i=0; i<len;i++){

        if((ekspresi[i]>='0' && ekspresi[i]<='9') || ekspresi[i]<='.'){
            buffer[j++] = ekspresi[i];
        }
        else if(ekspresi[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atof(buffer);
                s<<x;
                j = 0;
            }
        }
        else if(ekspresi[i]=='+' || ekspresi[i]=='-' || ekspresi[i]=='*' || ekspresi[i]==':' || ekspresi[i]=='%' || ekspresi[i]=='/'){
            op1 = s.getLastData();
            s>>dumpfloat;
            op2 = s.getLastData();
            s>>dumpfloat;
            switch(ekspresi[i]){
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
                case '%': // di c++ nggak bisa float mod float
                    while (op2 >= op1) {
                        op2 = op2 - op1;
                    }
                    s<<(op2);
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
