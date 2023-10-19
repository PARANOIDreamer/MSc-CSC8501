#include "beal.hpp"

template <typename T>
class Beal_limit :public Beal<T>
{
public:
	Beal_limit() : Beal<T>() {}
	Beal_limit(T sum) : Beal<T>(sum) {}
	void paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f);
	template <typename E>
	friend ostream& operator<<(ostream& os, const Beal_limit<E>& beal);
	virtual int findEquation();
	int check(T x1, T x2, T x3, T y1, T y2);
};

template <typename E>
ostream& operator<<(ostream& os, const Beal_limit<E>& beal)
{
	ofstream outfile("result.txt", ios::app);
	if (outfile.fail())
		cout << "fail" << endl;
	for (int i = 0; i < beal.u; i++) {
		outfile << beal.bnt << ':' << beal.a[i] << ',' << beal.x[i] << ',' << beal.b[i] << ',' << beal.y[i] << ',' << beal.c[i] << ',' << beal.z[i] << endl;
		printf("%d:%d,%d,%d,%d,%d,%d\n", beal.bnt, beal.a[i], beal.x[i], beal.b[i], beal.y[i], beal.c[i], beal.z[i]);
	}
	outfile.close();
	return os;
}

template <typename T>
int Beal_limit<T>::check(T x1, T x2, T x3, T y1, T y2) {
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
void Beal_limit<T>::paintin(T f, T a_f, T b_f, T c_f, T x_f, T y_f, T z_f) {
	Beal<T>::paintin(f, a_f, b_f, c_f, x_f, y_f, z_f);
}

template <typename T>
int Beal_limit<T>::findEquation(){
	if (this->bnt < 23)
		this->bnt = 23;
	T fac = floor((this->bnt - 9) / 3);
	fac = (fac < 20) ? fac : 20;
	while (this->u == 0) {
		for (T f = 3; f <= fac; f++) {
			T q = floor((this->bnt - 9) / f);
			for (T i = 0; i < q - 2; i++) {
				T a_f = (i + 1) * f;
				if (a_f > 20)
					break;
				for (T j = 0; j < q - i - 2; j++) {
					T b_f = (j + 1) * f;
					if (b_f > 20)
						break;
					T s = a_f * a_f * a_f + b_f * b_f * b_f;
					T d = pow((q - i - j - 2) * f, this->bnt - a_f - b_f - f - 6);
					if (s > d)
						break;
					for (T k = 0; k < q - i - j - 2; k++) {
						T c_f = (k + 1) * f;
						if (c_f > 20)
							break;
						T sub = this->bnt - (a_f + b_f + c_f);
						T max = (pow(c_f, sub - 6));
						if (s <= max) {
							for (T x_f = 3;x_f < sub - 5; x_f++) {
								if (x_f > 15)
									break;
								int p = (sub - x_f - 15);
								p = (p > 3) ? p : 3;
								for (T y_f = p; y_f < sub - x_f - 2; y_f++) {
									if ( y_f > 15)
										break;
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
		if (this->u == 0) {
			this->bnt++;
			if (this->bnt > 105) {
				return 0;
			}
		}
	}
	return this->u - 1;
}