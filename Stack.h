/**
 * @author 13512088 Annisaur Rosi Lutfiana
 * @file Stack.h
 * @class Stack
 * @brief Stack generik yang digunakan pada kelas-kelas lain
 */

#ifndef STACK_H
#define STACK_H
#include "boolean.h"
#include <iostream>
#include <string>
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
	T getData(int n);
	bool isFull();
	bool isEmpty();
	int getMaxSize() const;
	int getTopStack();
	int getDataCount(); // Mengembalikan jumlah data di stack
	T getLastData();
  private:
    static int defaultStackSize;
    const int size;
    int topStack;
    T *data;
};


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
Stack<T>::Stack(const Stack& S) :size(S.size){
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
	data[topStack] = x;
	topStack++;
}

template<class T>
T Stack<T>::getData(int n){
	T temp;
	if(n<=topStack-1)
		return data[n];
	else
		return temp;
}

template<class T>
int Stack<T>::getMaxSize() const{
	return size;
}

template<class T>
int Stack<T>::getTopStack(){
	return topStack;
}

template<class T>
bool Stack<T>::isFull(){
	return (topStack-1)==size;
}

template<class T>
bool Stack<T>::isEmpty(){
	return topStack==0;
}

template<class T>
int Stack<T>::getDataCount(){
	return topStack;
}

template<class T>
T Stack<T>::getLastData(){
	return this->getData(topStack-1);
}
#endif
