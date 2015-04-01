/**
 * @author
 * @file RelationalCalc.cpp
 * @class RelationalCalc
 * @brief Kelas untuk perbandingan (relasional) dengan ekspresi angka arab
 */

#include <iostream>
#include <stdlib.h>

#include "RelationalCalc.h"

/**
 * @fn RelationalCalc(string ekspresi,int mode,int size)
 * @brief Konstruktor parameter kalkulator relational
 */
RelationalCalc::RelationalCalc(string ekspresi,int mode,int size) :bil(size),operatorx(size){
	this->ekspresi = ekspresi;
	this->mode = mode;
}

/**
 * @fn ~RelationalCalc()
 * @brief Destruktor kalkulator relational
 */
RelationalCalc::~RelationalCalc(){
	//no memory to free
}

/**
 * @fn Calculate()
 * @brief Penghitungan sesuai mode ekspresi (prefix, infix, postfix)
 */
float RelationalCalc::Calculate(){
	float hasil;
	if(mode == 1)
    {
		hasil = CalculatePrefix();
	}
	else if(mode == 2)
	{
		hasil = CalculateInfix();
	}
	else if(mode == 3)
	{
		hasil = CalculatePostfix();
	}
	return hasil;
}


