#ifndef RomanCalc_H
#define RomanCalc_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class RomanCalc {
    public:
        int RomantoDec(const string& s);
        string DectoRoman(int d);
        string Calculate(RomanCalc R);
    private:
        Stack<char> op;
        Stack<int> num;
};

#endif

