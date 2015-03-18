/**
 * @author 13512096 Kevin
 * @file superkalkulator.cpp
 * @class superkalkulator
 * @brief Kelas besar untuk menangani masukan untuk input, setting, dan run kalkulator
 */

#include "superkalkulator.h"
#include <string>
#include <iostream>
#include <fstream>
#define LogSize 100
#include <string>
#include "ArabCalc.h"
#include "RomanCalc.h"
#include "LogicCalc.h"
#include <cstdlib>
//#include "LogikaCalc.h"

using namespace std;

/**
 * @fn String2Int(const std::string& str)
 * @brief Mengubah string menjadi integer
 */
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

/**
 * @fn superkalkulator()
 * @brief Konstruktor kelas superkalkulator
 */
superkalkulator::superkalkulator() : Log(LogSize){
	modeekspresi = 2;
	modekalkulator = 1;
}

/**
 * @fn ~superkalkulator()
 * @brief Destruktor kelas superkalkulator
 */
superkalkulator::~superkalkulator(){

}

/**
 * @fn getCountLog()
 * @brief Penghitung data log
 */
int superkalkulator::getCountLog(){
	return Log.getDataCount();
}

/**
 * @fn WriteLog(string str)
 * @brief Penulis data log
 */
void superkalkulator::WriteLog(string str){
	Log<<str;
}

/**
 * @fn Save()
 * @brief Method untuk save pada log file
 */
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

/**
 * @fn Input(string input)
 * @brief Penerima input berupa ekspresi, setting, atau mode
 */
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
	|| input[0] == '4' || input[0] == '5'|| input[0] == '6'|| input[0] == '7'|| input[0] == '8'|| input[0] == '9'
	|| input[0] == 'M' || input[0] == 'D' || input[0] == 'C' || input[0] == 'L' || input[0] == 'X'
		|| input[0] == 'V'|| input[0] == 'I' || input[0] == '~' || input[0] == '&' || input[0] == '|'
		|| input[0] == '+' || input[0] == '-' || input[0] == '*'|| input[0] == ':'  || input[0] == '/' || input[0] == '%' || input[0] == '('|| input[0] == ')')
	{
		cout<<".....Ekspresi....."<<endl;
		ArabCalc *arab;
		RomanCalc *roman;
		LogicCalc *logic;
		if(CheckEkspresiType(input) == modekalkulator || (modekalkulator == 1 && CheckEkspresiType(input) == 0) || (modekalkulator == 2 && CheckEkspresiType(input) == 0))
		{
			switch(modekalkulator)
			{
				case 1 : cout<<"Running Kalk Arab "<<endl;
						arab = new ArabCalc(input,modeekspresi,70);
						cout<<"Hasil "<<arab->Calculate()<<endl;
						break;
				case 2 : cout<<"Running Kalk Logika "<<endl;
						logic = new LogicCalc(input,modeekspresi,70);
						cout<<"Hasil "<<logic->Calculate()<<endl;
						break;
				case 3 : cout<<"Running Kalk Romawi "<<endl;
						roman = new RomanCalc(input,modeekspresi,70);
						cout<<"Hasil "<<roman->Calculate()<<endl;
						break;
				default: break;
			}
			switch(modeekspresi)
			{
				case 1 : cout<<"in prefix mode"<<endl;break;
				case 2 : cout<<"in Infix mode"<<endl;break;
				case 3 : cout<<"in postfix mode"<<endl;break;
				default: break;
			}
		}
		else
		{
			cout<<"Jenis ekspresi tidak sesuai kalkulator"<<endl;
		}
		this->WriteLog(input);
	}
	/*else
	{
		cout<<"Ketik help untuk bantuan"<<endl<<"Ketik exit untuk keluar"<<endl;
	}*/
}

/**
 * @fn Undo(int n)
 * @brief Method untuk undo atau penghapusan data log
 */
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

/**
 * @fn Redo(int n)
 * @brief Method untuk melakukan kembali aksi pada log
 */
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

/**
 * @fn setMode(int n)
 * @brief Mengeset mode ekspresi (prefix, infix, postfix)
 */
void superkalkulator::setMode(int n){
	modeekspresi = n;
}

/**
 * @fn setMode(int n)
 * @brief Mengeset mode kalkulator (arab, romawi, logika)
 */
void superkalkulator::setKalkulator(int n){
	modekalkulator= n;
}

/**
 * @fn runKalkulatorArab()
 * @brief Menjalankan kalkulator arab
 */
void superkalkulator::runKalkulatorArab(){

}

/**
 * @fn runKalkulatorLogika()
 * @brief Menjalankan kalkulator logika
 */
void superkalkulator::runKalkulatorLogika(){

}

/**
 * @fn runKalkulatorRomawi()
 * @brief Menjalankan kalkulator romawi
 */
void superkalkulator::runKalkulatorRomawi(){

}

/**
 * @fn getLog()
 * @brief Mengembalikan log
 */
Stack<string> superkalkulator::getLog(){
	return Log;
}

/**
 * @fn CheckEkspresiType(string ekspresi)
 * @brief Mengecek ekspresi agar dapat ditangani di kalkulator arab, logika, atau romawi
 */
int superkalkulator::CheckEkspresiType(string ekspresi)
{
	int mode;
	string tempekspresi = ekspresi;
	int Exit = 0;
	int ArabnLogika = 0;
	while(tempekspresi.length() != 0 && Exit==0)
	{
		if(tempekspresi[0] == '~' || tempekspresi[0] == '&' || tempekspresi[0] == '|')
		{
			mode = 2;
			Exit = 1;
		}
		else if(tempekspresi[0] == 'M' || tempekspresi[0] == 'D' || tempekspresi[0] == 'C' || tempekspresi[0] == 'L' || tempekspresi[0] == 'X'|| tempekspresi[0] == 'V'|| tempekspresi[0] == 'I')
		{
			mode = 3;
			Exit = 1;
		}
		else if(tempekspresi[0] == '0' || tempekspresi[0] == '1')
		{
			if(tempekspresi.length() > 1)
			{
				if(tempekspresi[1] == '0' || tempekspresi[1] == '1')
				{
					mode = 1;
				}
				else
				{
					mode = 0;
				}
			}
			else
			{
				mode = 0;
			}
		}
		else if( tempekspresi[0] == '2' || tempekspresi[0] == '3' || tempekspresi[0] == '4' || tempekspresi[0] == '5'
			|| tempekspresi[0] == '6'|| tempekspresi[0] == '7' || tempekspresi[0] == '8' || tempekspresi[0] == '9')
		{
			mode = 1;
		}
		tempekspresi.erase(0,1);
	}
	return mode;
}
