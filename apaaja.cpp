#include <iostream>
#include <cmath>
using namespace std;

int main(){
	string input;
	cout<<"Silahkan masukkan ekspresi"<<endl;
	std::getline(std::cin,input);
	int Exit = 0;
	int ArabnLogika = 0;
	while(input != "exit")
	{
		Exit = 0;
		ArabnLogika = 0;
		while(input.length() != 0 && Exit==0)
		{
			if(input[0] == '~' || input[0] == '&' || input[0] == '|')
			{
				cout<<"Logika"<<endl;
				ArabnLogika = 0;
				Exit = 1;
			}
			else if(input[0] == 'M' || input[0] == 'D' || input[0] == 'C' || input[0] == 'L' || input[0] == 'X'|| input[0] == 'V'|| input[0] == 'I')
			{
				cout<<"Romawi"<<endl;
				ArabnLogika = 0;
				Exit = 1;
			}
			else if(input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == ':' || input[0] == '/' || input[0] == '%')
			{
				cout<<"Arab"<<endl;
				ArabnLogika = 0;
				Exit = 1;
			}
			else if(input[0] == '0' || input[0] == '1')
			{
				if(input.length() > 1)
				{
					if(input[1] == '0' || input[1] == '1')
					{
						ArabnLogika = 0;
						cout<<"Romawi"<<endl;
					}
					else
					{
						ArabnLogika = 1;
					}
				}
				else
				{
					ArabnLogika = 1;
				}				
			}
			else if( input[0] == '2' || input[0] == '3' || input[0] == '4' || input[0] == '5'
				|| input[0] == '6'|| input[0] == '7' || input[0] == '8' || input[0] == '9')
			{
				cout<<"Logika"<<endl;
			}
			input.erase(0,1);
		}
		if(ArabnLogika == 1)
		{
			cout<<"Bisa logika dan romawi"<<endl;
		}
		cout<<"Silahkan masukkan ekspresi"<<endl;
		std::getline(std::cin,input);
	}	
	return 0;
}