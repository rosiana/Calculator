#include <iostream>
using namespace std;
#include <string>
int main(){
	string tes = "3+5*8-10";
	string delimiter[10] = {"+","-","/","%",":"};
	size_t pos = 0;
	string token;
	for(int i = 0;i<=4;i++){
		cout<<delimiter[i]<<endl;
	}
	int exit = 0;
	int counterdelimiter = 0;
	int countstillhavedelimiter = 5;
	while(countstillhavedelimiter!=0)
	{
		if(countstillhavedelimiter != 0 && counterdelimiter ==5)
		{
			countstillhavedelimiter = 5;
		}
		if(counterdelimiter == 5)
		{
			counterdelimiter = 0;
		}
		
		while((pos = tes.find(delimiter[counterdelimiter])) != std::string::npos) 
		{
			countstillhavedelimiter--;
			token = tes.substr(0, pos);
			std::cout << token << std::endl;
			tes.erase(0, pos + delimiter[counterdelimiter].length());
		}
		counterdelimiter++;
		std::cout << tes << std::endl;
		
	}
}