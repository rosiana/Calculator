#include <iostream>
#include <stdlib.h>

#include "ArabCalc.h"

using namespace std;

ArabCalc::ArabCalc(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

ArabCalc::~ArabCalc(){
	//no memory to free
}

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
	if(mode == 3)
	{
		hasil = CalculatePostfix();
	}
	return hasil;
}

float ArabCalc::CalculatePrefix(){
	char buffer[15], buffer2[15];
	int i, j, len;
	float op1, op2, x;
	j = 0;
	len = this->ekspresi.length();
	for(i=len-1;i>=0;i--){
		if((ekspresi[i] >= '0' && ekspresi[i]<='9') || ekspresi[i]=='.'){
			buffer[j++] = ekspresi[i];
		}
		else if(ekspresi[i]==' '){
			if(j>0){
				int n =j-1;
				int k;
                for(k = 0; k < j; k++){
					buffer2[k]=buffer[n];
					cout << buffer2[k]<<endl;
					n--;
                }
                buffer2[k+1] = '\0';
                x = atof(buffer2);
				this->bil << x;
				j = 0;
			}
		}
		else if(ekspresi[i]=='+' || ekspresi[i]=='-' || ekspresi[i]=='*' || ekspresi[i]==':' || ekspresi[i]=='%' || ekspresi[i]=='/'){
			this->operatorx << ekspresi.substr(i,1);
			SmallCalculate(bil, operatorx);
		}
	}
	x = bil.getLastData();
	return x;
}

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

float ArabCalc::CalculatePostfix(){
	char buffer[15];
	int i, j; //iterator
	float op1, op2, x; //operand dan hasil
	char opr; //operator
	j = 0;
	int len; // panjang ekspresi
	len = this->ekspresi.length();
	for(i=0; i<len;i++){
		if((ekspresi[i] >= '0' && ekspresi[i]<='9') || ekspresi[i] == '.'){
			buffer[j++] = ekspresi[i];
		}
		else if(ekspresi[i]==' '){
			if(j>0){
				buffer[j]='\0';
				x = atoi(buffer);
				this->bil << x;
				j = 0;
			}
		}
		else if(ekspresi[i]=='+' || ekspresi[i]=='-' || ekspresi[i]=='*' || ekspresi[i]==':' || ekspresi[i]=='%' || ekspresi[i]=='/'){
			this->operatorx << ekspresi.substr(i,1);
			SmallCalculate(bil, operatorx);
			}
		}
    x = bil.getLastData();
	return x;
}

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
