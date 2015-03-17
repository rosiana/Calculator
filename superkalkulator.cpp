#include "superkalkulator.h"
#include <string>
#include <iostream>
#include <fstream>
#define LogSize 100
#include <string>
using namespace std;

int String2Int(const std::string& str)
{
	int result = 0;
    std::string::const_iterator i = str.begin();
 
    if (i == str.end())
        return -999;
 
    bool negative = false;
 
    if (*i == '-')
    {
        negative = true;
        ++i;
 
        if (i == str.end())
            return -999;;
    }
 
    result = 0;
 
    for (; i != str.end(); ++i)
    {
        if (*i < '0' || *i > '9')
            return -999;;
 
        result *= 10;
        result += *i - '0';
    }
 
    if (negative)
    {
        result = -result;
    }
 
    return result;
}

superkalkulator::superkalkulator() : Log(LogSize){
	modeekspresi = 2;
	modekalkulator = 1;
}

superkalkulator::~superkalkulator(){
	
}

int superkalkulator::getCountLog(){
	return Log.getDataCount();
}

void superkalkulator::WriteLog(string str){
	Log<<str;
}

void superkalkulator::Save(){
   ofstream outfile;
   outfile.open("Log.txt",ios::app);
   for(int i = 0;i<=Log.getTopStack()-1;i++)
   {
		outfile << Log.getData(i) << endl;
   }
   outfile.close();
   cout<<"Save success"<<endl;
}

void superkalkulator::Input(string input){

	if(input == "Set")
	{
		string pilihan;
		string smode;
		int mode;
		cout<<".....Set....."<<endl;
		cout<<"Silahkan masukkan pilihan ekspresi(e) atau mode kalkulator(k)"<<endl;
		std::getline(std::cin,pilihan);
		if(pilihan == "e")
		{
			cout<<"Masukkan mode ekspresi"<<endl;
			cout<<"1. Prefix"<<endl;
			cout<<"2. Sufix"<<endl;
			cout<<"3. PostFix"<<endl;
			std::getline(std::cin,smode);
			mode = String2Int(smode);
			setMode(mode);
			cout<<"Berhasil"<<endl;
		}
		else if(pilihan == "k")
		{
			cout<<"Masukkan mode kalkulator"<<endl;
			cout<<"1. Arab"<<endl;
			cout<<"2. Logika"<<endl;
			cout<<"3. Romawi"<<endl;
			std::getline(std::cin,smode);
			mode = String2Int(smode);
			setKalkulator(mode);
			cout<<"Berhasil"<<endl;
		}
		else
		{
			cout<<"Masukkan tidak sesuai"<<endl<<"Tidak berhasil"<<endl;
		}
		this->WriteLog(input);
		
	}
	else if(input.substr(0,7) == "ShowMem")
	{
		cout<<".....ShowMem....."<<endl;
		int n = String2Int(input.substr(8,input.length()));
		if(n <= Log.getDataCount())
		{
			for(int i = Log.getDataCount() - n;i<=Log.getDataCount()-1;i++)
			{
				cout<<"Data-"<<i+1<<" : "<<Log.getData(i)<<endl;
			}
		}
		else
		{
			cout<<"Jumlah log lebih kecil dari yang diminta"<<endl;
		}
		this->WriteLog(input);
	}
	else if(input == "Show All")
	{
		cout<<".....Show All....."<<endl;
		this->WriteLog(input);
		if(Log.getDataCount() == 0)
		{
			cout<<"Log Kosong"<<endl;
		}
		else
		{
			for(int i = 0;i<Log.getDataCount();i++)
			{
				cout<<"Data-"<<i+1<<" : "<<Log.getData(i)<<endl;
			}
		}
		
	}
	else if(input.substr(0,4) == "Redo")
	{
		cout<<".....Redo....."<<endl;
		int n = String2Int(input.substr(5,input.length()));
		this->Redo(n);
		//this->WriteLog(input);
		//Tidak dimasukkan ke dalam log karena jika redo dijalankan setelah redo maka akan terjadi looping
	}
	else if(input.substr(0,4) == "Undo")
	{	
		//this->WriteLog(input);
		//Tidak dimasukkan ke dalam log karena jika redo dijalankan setelah undo maka akan terjadi keanehan semantik
		
		cout<<".....Undo....."<<endl;
		int n = String2Int(input.substr(5,input.length()-1));
		this->Undo(n);
	}
	else if(input == "Save")
	{
		cout<<".....Save....."<<endl;
		this->Save();
		this->WriteLog(input);
		
	}
	else if(input == "help")
	{
		cout<<".....Help....."<<endl;
		cout<<"Command List"<<endl;
		cout<<"1). Set"<<endl;
		cout<<"2). ShowMem x"<<endl;
		cout<<"3). Show All"<<endl;
		cout<<"4). Redo x"<<endl;
		cout<<"5). Save"<<endl;
		
	}
	else if(input[0] == '(' || input[0] == '0' || input[0] == '1' || input[0] == '2' || input[0] == '3'
	|| input[0] == '4' || input[0] == '5'|| input[0] == '6'|| input[0] == '7'|| input[0] == '8'|| input[0] == '9')
	{
		cout<<".....Ekspresi....."<<endl;
		switch(modekalkulator)
		{
			case 1 : cout<<"Running Kalk Arab ";break;
			case 2 : cout<<"Running Kalk Logika ";break;
			case 3 : cout<<"Running Kalk Romawi ";break;
			default: break;
		}
		switch(modeekspresi)
		{
			case 1 : cout<<"in prefix mode"<<endl;break;
			case 2 : cout<<"in sufix mode"<<endl;break;
			case 3 : cout<<"in postfix mode"<<endl;break;
			default: break;
		}
		this->WriteLog(input);
	}
	/*else
	{
		cout<<"Ketik help untuk bantuan"<<endl<<"Ketik exit untuk keluar"<<endl;
	}*/
}

void superkalkulator::Undo(int n){
	string out;
	if(n <= Log.getDataCount())
	{
		int temp = Log.getDataCount();
		for(int i = temp - n;i<=temp-1;i++)
		{
			cout<<"Pushed : "<<Log.getData(i)<<endl;
			this->Log>>out;
		}
	}
	else
	{
		cout<<"Penghapusan gagal"<<endl;
	}
	
}

void superkalkulator::Redo(int n){
	if(n <= Log.getDataCount())
	{
		int temp = Log.getDataCount();
		for(int i = temp - n;i<=temp-1;i++)
		{
			this->Input(Log.getData(i));
		}
	}
	else
	{
		cout<<"Jumlah log lebih kecil dari yang diminta"<<endl;
	}

}

void superkalkulator::setMode(int n){
	modeekspresi = n;
}

void superkalkulator::setKalkulator(int n){
	modekalkulator= n;
}

void superkalkulator::runKalkulatorArab(){

}

void superkalkulator::runKalkulatorLogika(){

}

void superkalkulator::runKalkulatorRomawi(){

}

Stack<string> superkalkulator::getLog(){
	return Log;
}