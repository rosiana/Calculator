#include <iostream>
#include <stdlib.h>

#include "RomanCalc.h"
#include "Stack.h"

using namespace std;

RomanCalc::RomanCalc() {

}

RomanCalc::RomanCalc(String input, int mode) {

}

RomanCalc::RomanCalc(const RomanCalc& R) {

}

RomanCalc::~RomanCalc() {

}

int RomanCalc::RomantoDec(const String& s) {
    int d;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I')
            d++;
        if (s[i] == 'V')
        {
            if (i > 0 && s[i - 1] == 'I')
                d -= 2;
            d += 5;
        }
        if (s[i] == 'X')
        {
            if (i > 0 && s[i - 1] == 'I')
                d -= 2;
            d += 10;
        }
        if (s[i] == 'L')
        {
            if (i > 0 && s[i - 1] == 'X')
                d -= 20;
            d += 50;
        }
    }
    return d;
}

String RomanCalc::DectoRoman (int d) {

}

