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
