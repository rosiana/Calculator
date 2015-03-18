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

/**
 * @fn Stack()
 * @brief Konstruktor stack (tanpa parameter)
 */
template <class T>
Stack<T>::Stack():size(defaultStackSize) {
	topStack = 0;
	data = new T [size];
}

/**
 * @fn Stack(int n)
 * @brief Konstruktor stack (dengan parameter)
 */
template <class T>
Stack<T>::Stack(int n):size(n) {
	topStack = 0;
	data = new T [size];
}

/**
 * @fn Stack(const Stack& S)
 * @brief Copy constructor stack
 */
template <class T>
Stack<T>::Stack(const Stack& S) :size(S.size){
	topStack = S.topStack;
	data = new T [size];
	for (int i = 0; i < size; i++) {
		data[i] = S.data[i];
	}
}

/**
 * @fn ~Stack()
 * @brief Destruktor stack
 */
template <class T>
Stack<T>::~Stack() {
	delete [] data;
}

/**
 * @fn operator>>(T& x)
 * @brief Pop (simpan dan hapus elemen teratas stack)
 */
template <class T>
void Stack<T>::operator>>(T& x) {
	x = data[topStack];
	topStack--;
}

/**
 * @fn operator<<(T x)
 * @brief Push (tambah elemen teratas stack)
 */
template <class T>
void Stack<T>::operator<<(T x) {
	data[topStack] = x;
	topStack++;
}

/**
 * @fn getData(int n)
 * @brief Ambil isi stack dengan elemen indeks kesekian
 */
template<class T>
T Stack<T>::getData(int n){
	T temp;
	if(n<=topStack-1)
		return data[n];
	else
		return temp;
}

/**
 * @fn getMaxSize()
 * @brief Mengembalikan ukuran maksimum stack
 */
template<class T>
int Stack<T>::getMaxSize() const{
	return size;
}

/**
 * @fn getTopStack()
 * @brief Mengembalikan indeks teratas stack
 */
template<class T>
int Stack<T>::getTopStack(){
	return topStack;
}

/**
 * @fn isFull()
 * @brief Cek apakah stack penuh
 */
template<class T>
bool Stack<T>::isFull(){
	return (topStack-1)==size;
}

/**
 * @fn isEmpty()
 * @brief Cek apakah stack kosong
 */
template<class T>
bool Stack<T>::isEmpty(){
	return topStack==0;
}

/**
 * @fn getDataCount()
 * @brief Mengembalikan jumlah elemen pada stack
 */
template<class T>
int Stack<T>::getDataCount(){
	return topStack;
}

/**
 * @fn getLastData()
 * @brief Mengembalikan data dengan indeks terbesar
 */
template<class T>
T Stack<T>::getLastData(){
	return this->getData(topStack-1);
}
#endif
