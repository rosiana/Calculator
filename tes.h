#ifndef tes_H
#define tes_H

template<class T>
class X{
	public:
		X();
		~X();
	private:
		T *data;
};
#endif

template<class T>
X<T>::X(){
	data = new T[100];
}

template<class T>
X<T>::~X(){
	delete[] data;
}