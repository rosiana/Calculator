#include <iostream>
using namespace std;

int main()
{
    string roman_Numeral;
	int i =0;
    int arabic_Numeral=0;
    cout<<"Enter the Roman Numeral in Capital letters (e.g. CCXIX) : ";
	std::getline(std::cin,roman_Numeral);
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
cout<<arabic_Numeral<<endl;
return 0;
}