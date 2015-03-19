#include <iostream>
#include <stdlib.h>
#include "LogicCalc2.h"

using namespace std;

LogicCalc::LogicCalc(string ekspresi, int mode){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

LogicCalc::~LogicCalc(){
	// not needed
}

bool LogicCalc::Calculate(){
	bool hasil;
	if(mode == 1){
		hasil = CalculatePrefix();
	}
	else if (mode == 2){
		hasil = CalculateInfix();
	}
	else if(mode == 3){
		hasil = CalculatePostfix();
	}
	return hasil;
}

bool LogicCalc::CalculatePrefix(){
    char buffer[15];
    string jawab;
    int i,j; //iterator
    bool op1, op2, x; //operand dan hasil
    int len; //panjang
    len = this->ekspresi.length();
    j = 0;
    for(i=len-1; i>=0; i--){
        if(ekspresi[i] == '0' || ekspresi[i]=='1'){
            buffer[0] = ekspresi[i];
   	    x = atoi(buffer);
            operand << x;
        }
        else if(ekspresi[i] == '&' || ekspresi[i] == '|' || ekspresi[i]=='~'){
			operatorx << ekspresi.substr(i,1);
            operand << Evaluate();
        }
    }
    x = operand.getLastData();
    if(operand.getLastData() == 0){
	jawab = "false";
    }
    else{
	jawab = "true";
    }
    cout << "Answer is " << jawab << endl;
    return x;
}

bool LogicCalc::CalculateInfix(){

}

bool LogicCalc::CalculatePostfix(){
	char buffer[15];
    string jawab;
    int i,j; //iterator
	bool op1, op2, x; //operand dan hasil
	int len; //panjang
    len = this->ekspresi.length();
    j = 0;
    for(i=0; i<len;i++){
        if(ekspresi[i] == '0' || ekspresi[i]=='1'){
            buffer[0] = ekspresi[i];
			x = atoi(buffer);
            operand << x;
        }
        else if(ekspresi[i] == '&' || ekspresi[i] == '|' || ekspresi[i]=='~'){
            operatorx << ekspresi.substr(i,1);
            operand << Evaluate();
        }
    }
    x = operand.getLastData();
	if(operand.getLastData() == 0){
		jawab = "false";
	}
	else{
		jawab = "true";
	}
    cout << "Answer is " << jawab << endl;
    return x;
}

bool LogicCalc::Evaluate(){
	bool ans, op1, op2;
	string operat;
	this->operatorx >> operat;
    if (operat == "&"){
			operand >> op1;
	        operand >> op2;
	        ans = op1 & op2;
	        cout << op1 <<" & " << op2 << "=" << ans << endl;
    }
	 else if(operat == "|"){
			operand >> op1;
	        operand >> op2;
	        ans = op1 | op2;
	        cout << op1 <<" | " << op2 << "=" << ans << endl;
	 }
	 else if(operat=="~"){
			operand >> op1;
	        if (op1 == 1){
				ans = false;
	        }
	        else{
				ans = true;
	        }
	        cout << "~"<<op1 << "=" << ans << endl;
    }
    return ans;
}
