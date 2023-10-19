#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>

using namespace std;

template <typename T>
class Beal
{
public:
	Beal();
	Beal(T sum);
	void paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f);
	T get_bnt();
	virtual int findEquation() = 0;

protected:
	vector<T> factor;
	vector<T> a, b, c;
	vector<T> x, y, z;
	T bnt;
	int u;
};

template <typename T>
Beal<T>::Beal() {
	bnt = 13;
	u = 0;
}

template <typename T>
Beal<T>::Beal(T sum) {
	bnt = sum;
	u = 0;
}

template <typename T>
T Beal<T>::get_bnt() {
	return bnt;
}

template <typename T>
void Beal<T>::paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f) {
	u++;
	factor.push_back(f);
	a.push_back(a_f);
	b.push_back(b_f);
	c.push_back(c_f);
	x.push_back(x_f);
	y.push_back(y_f);
	z.push_back(z_f);
}