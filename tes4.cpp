#include <iostream>
using namespace std;

int convert(string s)
{
	string roman_Numeral = s;
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
int main()
{
	string operatorx[30];
	int bil[30];
	int cbil = 0;
	int coperator = 0;
	string tes;
	cout<<"Enter the Roman Numeral in Capital letters (e.g. CCXIX) : ";
	std::getline(std::cin,tes);
	cout<<"Mulai"<<endl;
	while(tes!= "exit")
	{
		int cbil = 0;
		int coperator = 0;		
		while(tes.length()!=0)
		{
			//temp = "";
			string temp;
		
			temp  = "@";
			int ctemp = 0;
			while(tes[0] == 'M' || tes[0] == 'D' || tes[0] == 'C' || tes[0] == 'L' || tes[0] == 'X'
			|| tes[0] == 'V'|| tes[0] == 'I')
			{	
				//temp.append(tes.substr(0,1));
				temp.append(tes.substr(0,1));
				tes.erase(0,1);
				ctemp++;
			}
			if(temp !="@")
			{	
				cout<<"temp"<<temp.substr(1,temp.length())<<endl;
				bil[cbil] = convert(temp.substr(1,temp.length()));
				cbil++;
			}
			if(tes[0] == '+' || tes[0] == '-' || tes[0] == '*' || tes[0] == '/' || tes[0] == '%' || tes[0] == '('|| tes[0] == ')')
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
		cout<<"Enter the Roman Numeral in Capital letters (e.g. CCXIX) : ";
		std::getline(std::cin,tes);
	
	}
	return 0;
}

