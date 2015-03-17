#include "superkalkulator.h"
#include <string>
#include <iostream>

#define LogSize 100
#include <string>
using namespace std;

superkalkulator::superkalkulator() : Log(LogSize){
	int countLog = 0;
	int modeekspresi = 2;
	int modekalkulator = 1;
}

superkalkulator::~superkalkulator(){
	
}

void superkalkulator::Print(){
	if(Log.isEmpty())
	{
		cout<<"No log recorded"<<endl;
	}
	else
	{
		cout<<"Log recorded is :"<<endl;
		for(int i = 0;i<=Log.getTopStack()-1;i++)
		{
			cout<<i+1<<") "<<Log.getData(i)<<endl;
		}
	}
}

int superkalkulator::getCountLog(){
	return Log.getDataCount();
}

void superkalkulator::WriteLog(string str){
	Log<<str;
}

void superkalkulator::Save(){

}

void superkalkulator::Input(string input){

}

void superkalkulator::Undo(int n){

}

void superkalkulator::setMode(int n){

}

void superkalkulator::setKalkulator(int n){

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