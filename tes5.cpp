#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include "Stack.h"
#include <cmath>
#include <math.h>
void Print(Stack<float> bil,Stack<string>operatorx){
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
	string tes = "3-4%5";
	cout<<tes<<endl;
	Stack<string> operatorx;
	string popbil1,popbil2,popoperator;
	Stack<float> bil;
	string dumpoperator;
	float dumpbil;
	int cbil = 0;
	int m = 0;
	int coperator = 0;
	cout<<"Silahkan masukkan formula.exit untuk keluar"<<endl;
	std::getline(std::cin,tes);
	while(tes!= "exit")
	{
		while(tes.length()!=0)
		{
			char *temp =  new char[30];
			string apaaja;
			temp[0] = '@';
			int ctemp = 0;
			while(tes[0] == '0' || tes[0] == '1' || tes[0] == '2' || tes[0] == '3' || tes[0] == '4' || tes[0] == '5'
			|| tes[0] == '6'|| tes[0] == '7' || tes[0] == '8' || tes[0] == '9' || tes[0] == '.')
			{	
				temp[ctemp] = tes[0];
				tes.erase(0,1);
				ctemp++;
			}
			if(temp[0] !='@')
			{	
				bil<< atof(temp);
				cbil++;
			}
			if(tes[0] == '+' || tes[0] == '-' || tes[0] == '*' || tes[0] == '/' || tes[0] == '%' || tes[0] == '('|| tes[0] == ')')
			{
				cout<<"Operan "<<tes[0]<<endl;
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
		cout<<"HASIL : "<<bil.getLastData()<<endl;
		cout<<"Silahkan masukkan formula.exit untuk keluar"<<endl;
		std::getline(std::cin,tes);
		while(!bil.isEmpty())
		{
			bil>>dumpbil;
		}
	}
	
	return 0;
}