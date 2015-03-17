#include <iostream>
#include "superkalkulator.h"
#include <string>

using namespace std;
int main(){
	superkalkulator tes;
	cout<<tes.getLog().getMaxSize()<<endl;
	tes.Print();
	tes.WriteLog("Record 1");
	tes.Print();
	cout<<"Log recorded : "<<tes.getCountLog()<<" data"<<endl;
	return 0;
}