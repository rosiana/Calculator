/**
 * @author
 * @file LogicCalc.cpp
 * @class LogicCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand boolean
 */

#include <iostream>
#include <stdlib.h>

#include "LogicCalc.h"

using namespace std;

//tools debug
void LogicCalc::Print(Stack<int> bil,Stack<string>operatorx){
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
}

/**
 * @fn LogicCalc(string ekspresi,int mode,int size)
 * @brief Konstruktor parameter kalkulator logika
 */
LogicCalc::LogicCalc(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

/**
 * @fn ~LogicCalc()
 * @brief Destruktor kalkulator logika
 */
LogicCalc::~LogicCalc(){
	//no memory to free
}

/**
 * @fn Calculate()
 * @brief Penghitungan sesuai mode ekspresi (prefix, infix, postfix)
 */
string LogicCalc::Calculate(){
	int hasil;
	string hasilstr;
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
	if(hasil == 1)
	{
		hasilstr = "true";
	}
	else if(hasil == 0)
	{
		hasilstr = "false";
	}
	else
	{
		hasilstr = "Undefined";
	}
	return hasilstr;
}

/**
 * @fn SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
 * @brief Prosedur penentu operator untuk perhitungan mode infix
 */
void LogicCalc::SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
{
	int popbil1;
	int popbil2;
	string dumpoperator;
	int dumpbil;
	string popoperator = operatorx.getLastData();
	operatorx>>dumpoperator;
	if(popoperator == "~")
	{
		if(!bil.isEmpty() && bil.getLastData() == -999)
		{
			bil>>dumpbil; //Pop -999
		}
		else if(!operatorx.isEmpty() && operatorx.getLastData() == "~")
		{
			operatorx>>dumpoperator;
		}
		else
		{
			bil<< -999; //counter untuk merubah bil masukan berikut nya menjadi negasi dari input
		}
	}
	else if(popoperator == "&")
	{
		popbil1 = bil.getLastData();
		bil>>dumpbil;
		popbil2 = bil.getLastData();
		bil>>dumpbil;
		if(popbil1 && popbil2)
		{
			bil<< 1;
		}
		else
		{
			bil<< 0;
		}
	}
	else if(popoperator == "|")
	{
		popbil1 = bil.getLastData();
		bil>>dumpbil;
		popbil2 = bil.getLastData();
		bil>>dumpbil;
		if(popbil1 || popbil2)
		{
			bil<< 1;
		}
		else
		{
			bil<< 0;
		}
	}
	
}

/**
 * @fn CalculateInfix()
 * @brief Penghitungan mode infix
 */
int LogicCalc::CalculateInfix(){
	string dumpoperator;
	int dumpbil;
	int hasil;
	string ekspresitemp = ekspresi;
	string temp;
	while(ekspresitemp.length() != 0)
	{	
		int isCompleteRead = 0;
		int ctemp = 0; //Menghitung panjang buffer angka
		if(ekspresitemp[0] == '0' || ekspresitemp[0] == '1')
		{
			if(bil.isEmpty())
			{
				if(ekspresitemp[0] == '1')
				{
					bil<<1;
				}
				else if(ekspresitemp[0] == '0')
				{
					bil<<0;
				}
			}
			else // stack bil mempunyai 1 elemen
			{
				if(bil.getLastData() == -999) //cek counter untuk merubah bil masukan menjadi negasi dari input
				{
					if(!operatorx.isEmpty())
					{
						if(operatorx.getLastData() != "{")
						{
							bil>>dumpbil;
							if(ekspresitemp[0] == '1')
							{
								bil<<0;
							}
							else if(ekspresitemp[0] == '0')
							{
								bil<<1;
							}
						}
					}
					else
					{
						bil>>dumpbil;
						if(ekspresitemp[0] == '1')
						{
							bil<<0;
						}
						else if(ekspresitemp[0] == '0')
						{
							bil<<1;
						}
					}
				}
				else
				{
					if(ekspresitemp[0] == '1')
					{
						bil<<1;
					}
					else if(ekspresitemp[0] == '0')
					{
						bil<<0;
					}
				}
			}

		}
		if(ekspresitemp[0] == '~' || ekspresitemp[0] == '&' || ekspresitemp[0] == '|' || ekspresitemp[0] == '(' || ekspresitemp[0] == ')')
		{
			if(ekspresitemp[0] == '~')
			{
				operatorx<<ekspresitemp.substr(0,1);
				SmallCalculate(bil,operatorx);
			}
			if((operatorx.isEmpty() || ekspresitemp[0] == '(') && ekspresitemp[0] != '~')
			{
				operatorx<<ekspresitemp.substr(0,1);

			}
			else
			{
				if(ekspresitemp[0] == '&' || ekspresitemp[0] == '|')
				{
					if(operatorx.getLastData() == "~")
					{
						SmallCalculate(bil,operatorx);
						operatorx<<ekspresitemp.substr(0,1);
					}
					else //operatorx.getLastData() == "~"
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
					if(!bil.isEmpty())
					{
						if(bil.getLastData() == -999)
						{
							bil>>dumpbil;
							if(ekspresitemp[0] == '1')
							{
								bil<<0;
							}
							else if(ekspresitemp[0] == '0')
							{
								bil<<1;
							}
						}
					}
					
				}

			}
		}
		ekspresitemp.erase(0,1);
	}
	

	while(!operatorx.isEmpty())
	{
		SmallCalculate(bil,operatorx);

	}
	hasil = bil.getLastData();
	cout<<"Hasil : "<<hasil<<endl;
	return hasil;
	//End
}

/**
 * @fn CalculatePrefix()
 * @brief Penghitungan mode prefix
 */
int LogicCalc::CalculatePrefix() {
    char buffer[15];
    string jawab;
    int i,j; //iterator
    bool op1, op2, x; //operand dan hasil
    int len; //panjang
    len = this->ekspresi.length();
    j = 0;
    for(i=len-1; i>=0; i--){
        if(ekspresi[i] == '0' || ekspresi[i]=='1'){
            buffer[0] = ekspresi[i];
			x = atoi(buffer);
            bil << x;
        }
        else if(ekspresi[i] == '&' || ekspresi[i] == '|' || ekspresi[i]=='~'){
			operatorx << ekspresi.substr(i,1);
            SmallCalculate(bil,operatorx);
        }
    }
    return bil.getLastData();
}

/**
 * @fn CalculatePostfix()
 * @brief Penghitungan mode postfix
 */
int LogicCalc::CalculatePostfix() {
    char buffer[15];
    string jawab;
    int i,j; //iterator
	bool op1, op2, x; //operand dan hasil
	int len; //panjang
    len = this->ekspresi.length();
    j = 0;
    for(i=0; i<len;i++){
        if(ekspresi[i] == '0' || ekspresi[i]=='1'){
            buffer[0] = ekspresi[i];
			x = atoi(buffer);
            bil << x;
        }
        else if(ekspresi[i] == '&' || ekspresi[i] == '|' || ekspresi[i]=='~'){
            operatorx << ekspresi.substr(i,1);
            SmallCalculate(bil,operatorx);
        }
    }
    return bil.getLastData();
}

