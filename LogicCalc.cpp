/**
 * @author
 * @file LogicCalc.cpp
 * @class LogicCalc
 * @brief Kelas untuk pengolahan ekspresi dengan operand angka arab
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
 * @brief Konstruktor parameter kalkulator arab
 */
LogicCalc::LogicCalc(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

/**
 * @fn ~LogicCalc()
 * @brief Destruktor kalkulator arab
 */
LogicCalc::~LogicCalc(){
	//no memory to free
}

/**
 * @fn Calculate()
 * @brief Penghitungan sesuai mode ekspresi (prefix, infix, postfix)
 */
int LogicCalc::Calculate(){
	int hasil;
	cout<<"Masuk"<<endl;
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
	cout<<"Out"<<endl;
	return hasil;
}

/**
 * @fn SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
 * @brief Prosedur penentu operator untuk perhitungan mode infix
 */
void LogicCalc::SmallCalculate(Stack<int> &bil,Stack<string> &operatorx)
{
	cout<<"Start Calculate"<<endl;
	Print(bil,operatorx);
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
		bool x = popbil1 | popbil2;
		cout <<"XXXXXXXXXXXXXXXXXXX"<< x<< endl;
		if(x==1)
		{
			bil<< 1;
		}
		else
		{
			bil<< 0;
		}
		operatorx>>dumpoperator;
	}
	cout<<"Finish Calculate"<<endl;
	Print(bil,operatorx);
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
	cout<<"Infix"<<endl;
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
				else
				{
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
		cout<<"Printtttttt"<<endl;
		Print(bil,operatorx);
		if(ekspresitemp[0] == '~' || ekspresitemp[0] == '&' || ekspresitemp[0] == '|' || ekspresitemp[0] == '(' || ekspresitemp[0] == ')')
		{
			cout<<"ASDFASDFASDFASDFADSF"<<endl;
			if(ekspresitemp[0] == '~')
			{
				cout<<"Ther is operand"<<ekspresitemp.substr(0,1)<<endl;
				operatorx<<ekspresitemp.substr(0,1);
				cout<<"PPPPPPPPPPPPPPPPPPPP"<<endl;
				SmallCalculate(bil,operatorx);
			}
			else if(operatorx.isEmpty() || ekspresitemp[0] == '(')
			{
				operatorx<<ekspresitemp.substr(0,1);
			}
			else if(ekspresitemp[0] == '&' || ekspresitemp[0] == '|' || ekspresitemp[0] == ')')
			{
				cout<<"BBBBBBBBBBBBBBBBBBB"<<ekspresitemp[0]<<endl;
				if(ekspresitemp[0] == '&' || ekspresitemp[0] == '|')
				{
					operatorx<<ekspresitemp.substr(0,1);
					SmallCalculate(bil,operatorx);
				}
				/*else if(ekspresitemp[0] == '~')
				{
					if(operatorx.getLastData() == "&" || operatorx.getLastData() == "|")
					{
						SmallCalculate(bil,operatorx);
						operatorx<<ekspresitemp.substr(0,1);
					}
					else //operatorx.getLastData() == "~"
					{
						operatorx<<ekspresitemp.substr(0,1);
					}
				}*/
				else if(ekspresitemp[0] == ')')
				{
					while(operatorx.getLastData() != "(")
					{
						SmallCalculate(bil,operatorx);
					}
					operatorx>>dumpoperator;
				}

			}
		}
		cout<<"Erase"<<endl;
		ekspresitemp.erase(0,1);
		cout<<"Ekspresi Left"<<ekspresitemp<<endl;
		Print(bil,operatorx);
		cout<<"Length : "<<ekspresitemp.length()<<endl;
	}
	cout<<"Parse Complete"<<endl;
	Print(bil,operatorx);
	cout<<"IsEmpty()"<<operatorx.isEmpty()<<endl;
	if(operatorx.isEmpty())
	{
		while(!operatorx.isEmpty())
		{
			SmallCalculate(bil,operatorx);

		}
	}
	cout<<"Masuk hasil"<<endl;
	hasil = bil.getLastData();
	return hasil;
	//End
}

/**
 * @fn CalculatePrefix()
 * @brief Penghitungan mode prefix
 */
int LogicCalc::CalculatePrefix() {
    char buffer[15];
    int i, len, j;
    int op1, op2, x;
    Stack<int> s;
	int dumpint;
    len = ekspresi.length();
    j = 0;
    for(i=len-1; i>=0; i--){
        if(ekspresi[i]>='0' && ekspresi[i]<='9'){
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
            s>>dumpint;
            op2 = s.getLastData();
            s>>dumpint;
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
                case '%': // di c++ nggak bisa int mod int
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
int LogicCalc::CalculatePostfix() {
    char buffer[15];
    int i, len, j;
    int op1, op2, x;
    Stack<int> s;
    len = ekspresi.length();
    j = 0;
	int dumpint;
    for(i=0; i<len;i++){

        if(ekspresi[i]>='0' && ekspresi[i]<='9'){
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
            s>>dumpint;
            op2 = s.getLastData();
            s>>dumpint;
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
                case '%': // di c++ nggak bisa int mod int
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

