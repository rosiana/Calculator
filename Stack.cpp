/**
 * @author 13512088 Annisaur Rosi Lutfiana
 * @file Stack.cpp
 * @class Stack
 * @brief Stack generik yang digunakan pada kelas-kelas lain
 */

#include <iostream>
#include <cstdio>

#include "Stack.h"
#include <string>
using namespace std;

template <class T>
int Stack<T>::defaultStackSize = 100;

template <class T>
Stack<T>::Stack():size(defaultStackSize) {
	topStack = 0;
	data = new T [size];
}

template <class T>
Stack<T>::Stack(int n):size(n) {
	topStack = 0;
	data = new T [size];
}

template <class T>
Stack<T>::Stack(const Stack& S) {
	size = S.size;
	topStack = S.topStack;
	data = new T [size];
	for (int i = 0; i < size; i++) {
		data[i] = S.data[i];
	}
}

template <class T>
Stack<T>::~Stack() {
	delete [] data;
}

template <class T>
void Stack<T>::operator>>(T& x) {
	x = data[topStack];
	topStack--;
}

template <class T>
void Stack<T>::operator<<(T x) {
	topStack++;
	data[topStack] = x;
}




