#include "beal.hpp"

template <typename T>
class Beal_lowestBnt :public Beal<T>
{
public:
	Beal_lowestBnt() : Beal<T>() {}
	Beal_lowestBnt(T sum) : Beal<T>(sum) {}
	template <typename E>
	friend ostream& operator<<(ostream& os, const Beal_lowestBnt<E>& beal);
	virtual int findEquation();
	void paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f);
};

template <typename E>
ostream& operator<<(ostream& os, const Beal_lowestBnt<E>& beal)
{

	ofstream outfile("result.txt", ios::app);
	if (outfile.fail())
		cout << "fail" << endl;
	for (int i = 0; i < beal.u; i++) {
		outfile << beal.bnt << ':' << beal.a[i] << ',' << beal.x[i] << ',' << beal.b[i] << ',' << beal.y[i] << ',' << beal.c[i] << ',' << beal.z[i] << endl;
		cout << beal.bnt << ':' << beal.a[i] << ',' << beal.x[i] << ',' << beal.b[i] << ',' << beal.y[i] << ',' << beal.c[i] << ',' << beal.z[i] << endl;
	}
	outfile.close();
	return os;
}

template <typename T>
void Beal_lowestBnt<T>::paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f) {
	Beal<T>::paintin(f, a_f, b_f, c_f, x_f, y_f, z_f);
}

template <typename T>
int Beal_lowestBnt<T>::findEquation()
{
	if (this->bnt < 16)
		this->bnt = 16;
	T fac = floor((this->bnt - 9) / 3);
	while (this->u == 0) {
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
										paintin(f, a_f, b_f, c_f, x_f, y_f, z_f);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
		if (this->u == 0) {
			this->bnt++;
		}
	}
	return this->u - 1;
}