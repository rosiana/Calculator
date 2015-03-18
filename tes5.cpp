#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include "Stack.h"
#include <cmath>
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
	float popbill;
	float popbill2;
	string dump;
	popbil1 = bil.getLastData();
	bil>>dump;
	popbil2 = bil.getLastData();
	bil>>dump;
	popoperator = operatorx.getLastData();
	operatorx>>dump;
	cout<<"Popbil1 : "<<popbil1<<endl<<"Popbil2 : "<<popbil2<<endl<<"Operator"<<popoperator<<endl;
	if(popoperator == "x")
	{
		bil<< popbil1*popbil2;
	}
	else if(popoperator == "/")
	{
		bil<< popbil1/popbil2;
	}
	else if(operatorx == "%")
	{
		bil<< popbil1%popbil2;
	}
	else if(operatorx == "+")
	{
		bil<< popbil1+popbil2;
	}
	else if(operatorx == "-")
	{
		bil<< popbil1-popbil2;
	}
}

int main(){
	string tes = "3.44+6*6-(6/3)";
	Stack<string> operatorx;
	string popbil1,popbil2,popoperator;
	Stack<float> bil;
	string dump;
	int cbil = 0;
	int m = 0;
	int coperator = 0;
	cout<<"Mulai"<<endl;
	while(tes.length()!=0)
	{
		char *temp =  new char[30];
	
		temp[0] = '@';
		int ctemp = 0;
		while(tes[0] == '1' || tes[0] == '2' || tes[0] == '3' || tes[0] == '4' || tes[0] == '5'
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
			if(operatorx.isEmpty() || tes[0] == '(' || tes[0] == 'x' || tes[0] == '/' || tes[0] == '%')
			{
				operatorx<<tes.substr(0,1);
				tes.erase(0,1);
				coperator++;
			}
			else
			{
				if(tes[0] == '+' || tes[0] == '-' || tes[0] == ')')
				{
					operatorx<<tes.substr(0,1);
					tes.erase(0,1);
					coperator++;
				}
				if(tes[0] == '+' || tes[0] == '-')
				{
					if(operatorx.getLastData() == "x" || operatorx.getLastData() == "/" || operatorx.getLastData() == "%")
					{
						
					}
					else
					{
						operatorx<<tes.substr(0,1);
						tes.erase(0,1);
						coperator++;
					}
				}
			}
		}
	}
	return 0;
}