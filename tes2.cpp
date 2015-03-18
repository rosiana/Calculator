#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>


int main(){
	string tes = "3.44+6*6-(6/3)";
	string delimiter[10] = {"+","-","/","%",":"};
	size_t pos = 0;
	string token;

	int sizetemp[10];
	string operatorx[10];
	float bil[10];
	int cbil = 0;
	int m = 0;
	int coperator = 0;
	cout<<"Mulai"<<endl;
	while(tes.length()!=0)
	{
		//temp = "";
		char *temp =  new char[30];
	
		temp[0] = '@';
		int ctemp = 0;
		while(tes[0] == '1' || tes[0] == '2' || tes[0] == '3' || tes[0] == '4' || tes[0] == '5'
		|| tes[0] == '6'|| tes[0] == '7' || tes[0] == '8' || tes[0] == '9' || tes[0] == '.')
		{	
			//temp.append(tes.substr(0,1));
			temp[ctemp] = tes[0];
			tes.erase(0,1);
			ctemp++;
		}
		if(temp[0] !='@')
		{	
			bil[cbil] = atof(temp);
			cbil++;
		}
		if(tes[0] == '+' || tes[0] == '-' || tes[0] == '*' || tes[0] == '/' || tes[0] == '('|| tes[0] == ')')
		{
			operatorx[coperator] = tes.substr(0,1);
			tes.erase(0,1);
			coperator++;
		}
	}
	cout<<"Stack bilangan"<<endl;
	for(int i = 0;i<=cbil-1;i++)
	{
		cout<<i<<"). "<<bil[i]<<endl;
	}
	cout<<"Stack operator"<<endl;
	for(int j = 0;j<=coperator-1;j++)
	{
		cout<<j<<"). "<<operatorx[j]<<endl;
	}
}