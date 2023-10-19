#include "beal.hpp"
#include "mulit.hpp"

template <typename T>
class Beal_ASCII :public Beal<T>
{
public:
	Beal_ASCII() : Beal<T>() {}
	Beal_ASCII(T sum) : Beal<T>(sum) {}
	void paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f);
	template <typename E>
	friend ostream& operator<<(ostream& os, const Beal_ASCII<E>& beal);
	virtual int findEquation();
	int check(T x1, T x2, T x3, T y1, T y2);
};

template <typename E>
ostream& operator<<(ostream& os, const Beal_ASCII<E>& beal)
{
	if (beal.u != 0) {
		cout << beal.bnt;
		for (int i = 0; i < beal.u; i++) {
			cout << " *";
			//cout << beal.bnt << ':' << beal.a[i] << ',' << beal.x[i] << ',' << beal.b[i] << ',' << beal.y[i] << ',' << beal.c[i] << ',' << beal.z[i] << endl;
		}
			//cout << " *";7
		cout << endl;
	}
	return os;
}

template <typename T>
int Beal_ASCII<T>::check(T x1, T x2, T x3, T y1, T y2) {
	int t = 0;
	for (int i = 0; i < this->u; i++) {
		t = 1;
		if (x1 == this->a[i] && x2 == this->b[i] && x3 == this->c[i] && y1 == this->x[i] && y2 == this->y[i])
			break;
		t = 0;
	}
	return t;
}

template <typename T>
void Beal_ASCII<T>::paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f) {
	Beal<T>::paintin(f, a_f, b_f, c_f, x_f, y_f, z_f);
}

template <typename T>
int Beal_ASCII<T>::findEquation() {
	if (this->bnt < 16)
		this->bnt = 16;
	T fac = floor((this->bnt - 9) / 3);
	for (T f = 2; f <= fac; f++) {
		T q = floor((this->bnt - 9) / f);
		for (T i = 0; i < q - 2; i++) {
			T a_f = (i + 1) * f;
			for (T j = 0; j < q - i - 2; j++) {
				T b_f = (j + 1) * f;
				T s = a_f * a_f * a_f + b_f * b_f * b_f;
				T d = pow((q - i - j - 2) * f, this->bnt - a_f - b_f - f - 6);
				if (s > d)
					break;
				for (T k = 0; k < q - i - j - 2; k++) {
					T c_f = (k + 1) * f;
					T sub = this->bnt - (a_f + b_f + c_f);
					if (s <= pow(c_f, sub - 6)) {
						for (T x_f = 3; x_f < sub - 5; x_f++) {
							for (T y_f = 3; y_f < sub - x_f - 2; y_f++) {
								T z_f = sub - x_f - y_f;
								if (a_f == c_f && x_f == z_f)continue;
								if (b_f == c_f && y_f == z_f)continue;
								T m = pow(a_f, x_f) + pow(b_f, y_f);
								T n = pow(c_f, z_f);
								if (m > n)
									break;
								if (m == n) {
									if (check(a_f, b_f, c_f, x_f, y_f))
										break;
									T m1 = pow(a_f, x_f);
									T m2 = pow(b_f, y_f);
									if (m != m1 + m2)break;
									if (n >= 9223372036854775808) {
										string temp_n = getPow(c_f, z_f);
										string temp_m1 = getPow(a_f, x_f);
										if (temp_m1 == temp_n)break;
										string temp_m2 = getPow(b_f, y_f);
										if (temp_m2 == temp_n)break;
										string temp_m = getAdd(temp_m1, temp_m2);
										if (temp_m == temp_n)
											paintin(f, a_f, b_f, c_f, x_f, y_f, z_f);
										break;
									}
									paintin(f, a_f, b_f, c_f, x_f, y_f, z_f);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	return this->u - 1;
}