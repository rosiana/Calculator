#ifndef RomanCalc_H
#define RomanCalc_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class RomanCalc {
    public:
        RomanCalc();
        RomanCalc(string input, int mode);
        RomanCalc(const RomanCalc& R);
        RomanCalc& operator=(const string& s);
        ~RomanCalc();
        int RomantoDec(const string& s);
        string DectoRoman(int d);
        string Calculate(RomanCalc R);
    private:
        Stack<char> op;
        Stack<int> num;
};

#endif

