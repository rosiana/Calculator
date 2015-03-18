#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include "Stack.h"
#include <cmath>
#include <math.h>
void Print(Stack<int> bil,Stack<string>operatorx){
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

int convert(string roman_Numeral)
{
	int i =0;
    int arabic_Numeral=0;
    while(i<roman_Numeral.length())
    {
		if (roman_Numeral[i] == 'M')
		{	
			arabic_Numeral=arabic_Numeral+1000;
		}

		else if (roman_Numeral[i] == 'D')
		{
			if(i<roman_Numeral.length()+1)
			{
				if(roman_Numeral[i+1] == 'M'){ arabic_Numeral=arabic_Numeral-500;}
				else{ arabic_Numeral=arabic_Numeral+500;}
			}
		}

		else if (roman_Numeral[i] == 'C')
		{
			if(i<roman_Numeral.length()+1)
			{
				if(roman_Numeral[i+1] == 'M' || roman_Numeral[i+1] == 'D'){ arabic_Numeral=arabic_Numeral-100;}
				else{ arabic_Numeral=arabic_Numeral+100;}
			}
		}

		else if (roman_Numeral[i] == 'L')
		{
			if(i<roman_Numeral.length()+1)
			{
				if(roman_Numeral[i+1] == 'M' || roman_Numeral[i+1] == 'D' || roman_Numeral[i+1] == 'C'){ arabic_Numeral=arabic_Numeral-50;}
				else{ arabic_Numeral=arabic_Numeral+50;}
			}
		}                       

		else if (roman_Numeral[i] == 'X')
		{
			if(i<roman_Numeral.length()+1)
			{
				if(roman_Numeral[i+1] == 'M' || roman_Numeral[i+1] == 'D' || roman_Numeral[i+1] == 'C' || roman_Numeral[i+1] == 'L'){ arabic_Numeral=arabic_Numeral-10;}
				else{ arabic_Numeral=arabic_Numeral+10;}
			}
		}

		else if (roman_Numeral[i] == 'V')
		{
			if(i<roman_Numeral.length()+1)
			{
				if(roman_Numeral[i+1] == 'M' || roman_Numeral[i+1] == 'D' || roman_Numeral[i+1] == 'C' || roman_Numeral[i+1] == 'L' || roman_Numeral[i+1] == 'X'){ arabic_Numeral=arabic_Numeral-5;}
				else{ arabic_Numeral=arabic_Numeral+5;}
			}
		}   

		else if (roman_Numeral[i] == 'I')
		{
			if(i<roman_Numeral.length()+1)
			{
				if(roman_Numeral[i+1] == 'M' || roman_Numeral[i+1] == 'D' || roman_Numeral[i+1] == 'C' || roman_Numeral[i+1] == 'L' || roman_Numeral[i+1] == 'X' || roman_Numeral[i+1] == 'V'){ arabic_Numeral=arabic_Numeral-1;}
				else{ arabic_Numeral=arabic_Numeral+1;}
			}
		}
		else
		{
			cout<<"Your input is wrong"<<endl;
		}
		i++;
    }
	return arabic_Numeral;
}

void SmallCalculate(Stack<float> &bil,Stack<string> &operatorx)
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

int main(){
	Stack<string> operatorx;
	Stack<float> bil;
	string popbil1,popbil2,popoperator;
	string dumpoperator;
	float dumpbil;
	int cbil = 0;
	int m = 0;
	int coperator = 0;
	string tes;
	cout<<"Silahkan masukkan formula.exit untuk keluar"<<endl;
	std::getline(std::cin,tes);
	while(tes!= "exit")
	{
		while(tes.length()!=0)
		{
			string temp;
			int isCompleteRead = 0;
			int ctemp = 0;
			while(tes[0] == 'M' || tes[0] == 'D' || tes[0] == 'C' || tes[0] == 'L' || tes[0] == 'X'
			|| tes[0] == 'V'|| tes[0] == 'I')
			{	
				temp += tes.substr(0,1);
				tes.erase(0,1);
				ctemp++;
				isCompleteRead = 1;
			}
			if(isCompleteRead == 1)
			{	
				bil<< convert(temp);
				cbil++;
			}
			if(tes[0] == '+' || tes[0] == '-' || tes[0] == '*' || tes[0] == '/' || tes[0] == '%' || tes[0] == '('|| tes[0] == ')')
			{
				if(operatorx.isEmpty() || tes[0] == '(')
				{
					operatorx<<tes.substr(0,1);
					coperator++;
				}
				else
				{
					if(tes[0] == '+' || tes[0] == '-')
					{
						if(operatorx.getLastData() == "*" || operatorx.getLastData() == "/" || operatorx.getLastData() == "%" || operatorx.getLastData() == "+" || operatorx.getLastData() == "-")
						{
							SmallCalculate(bil,operatorx);
							operatorx<<tes.substr(0,1);
						}
						else
						{
							operatorx<<tes.substr(0,1);
							coperator++;
						}
					}
					else if(tes[0] == '*' || tes[0] == '/' || tes[0] == '%')
					{
						
						if(operatorx.getLastData() == "*" || operatorx.getLastData() == "/" || operatorx.getLastData() == "%")
						{
							SmallCalculate(bil,operatorx);
							operatorx<<tes.substr(0,1);
						}
						else
						{
							operatorx<<tes.substr(0,1);
							coperator++;
						}
					}
					else if(tes[0] == ')')
					{
						while(operatorx.getLastData() != "(")
						{
							SmallCalculate(bil,operatorx);
						}
						operatorx>>dumpoperator;
					}
					
				}
				tes.erase(0,1);
			}
		}
		while(!operatorx.isEmpty())
		{
			SmallCalculate(bil,operatorx);

		}
		cout<<"HaSIL : "<<bil.getLastData()<<endl;
		cout<<"Silahkan masukkan formula.exit untuk keluar"<<endl;
		std::getline(std::cin,tes);
		while(!bil.isEmpty())
		{
			bil>>dumpbil;
		}
		while(!operatorx.isEmpty())
		{
			operatorx>>dumpoperator;
		}
	}
	
	return 0;
}