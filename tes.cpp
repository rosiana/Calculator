/* 13512088 Annisaur Rosi Lutfiana */

/* Implementasi Kelas Stack */

#include <iostream>
#include <cstdio>

#include "Stack.h"

using namespace std;
/* 13512088 Annisaur Rosi Lutfiana */

/* Implementasi Kelas Stack */

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack {
  public:
    Stack();
    Stack(int n);
    Stack(const Stack&);
    ~Stack();
    void operator>>(T& x);
    void operator<<(T x);

  private:
    static int defaultStackSize;
    const int size;
    int topStack;
    T *data;
};

#endif

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




