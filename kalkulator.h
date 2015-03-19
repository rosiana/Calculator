/**
 * @author 13512096 Kevin
 * @file kalkulator.h
 * @class kalkulator
 * @brief Kelas interface penghitungan, implementasi masing-masing di setiap mode kalkulator
 */

#ifndef kalkulator_H
#define kalkulator_H
#include <iostream>

using namespace std;

template <class Z>
class kalkulator{
	public:
		virtual Z Calculate() = 0;

};
#endif
