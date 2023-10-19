#pragma once
//#define_CRT_SECURE_NO_WAR
#include<iostream>
#include <thread>

using namespace std;

void File(string q) {
	ofstream outfile("result.txt", ios::app);
	if (outfile.fail())
		cout << "fail" << endl;
	outfile << q << endl;
	outfile.close();
}

void LimitBNT(int min, int max) {
	unsigned long long int m = min;
	while (m <= max) {
		Beal_limit<unsigned long long int> a(m);
		a.findEquation();
		m = a.get_bnt();
		if (m > max)
			break;
		cout << a;
		m++;
	}
}

void Question_1() {
	unsigned int m = 16;
	for (int i = 0; i < 5; i++) {
		Beal_lowestBnt<unsigned int> a(m);
		a.findEquation();
		cout << a;
		m = a.get_bnt() + 1;
	}
}

void Question_2() {
	unsigned int m = 16;
	for (int i = 0; i < 5; i++) {
		int v = 0;
		while (v == 0) {
			int u = 0;
			while (u < m - 2) {
				for (int j = 2; j < m; j++) {
					if (m % j == 0) {
						m++;
						break;
					}
					u++;
				}
			}
			Beal_lowestBnt<unsigned long long int> a(m);
			a.findEquation();
			if (m == a.get_bnt()) {
				cout << a;
				m++;
				v++;
			}
			else
			{
				m = a.get_bnt();
			}
		}
	}
}

void Question_3() {
	int s = 0;
	cout << "Sequential output? Yes-0/No-1." << endl;
	cin >> s;
	cin.clear();
	while (cin.get() != '\n');
	if (s == 0) {
		cout << "Sequential output." << endl;
		LimitBNT(23, 105);
	}
	else
	{
		cout << "Nonsequential output." << endl;
		thread a(LimitBNT, 23, 65);
		thread b(LimitBNT, 65, 105);
		a.join();
		b.join();
	}
}

void Question_5() {
	unsigned int m = 16;
	for (int i = 0; i < 10; i++) {
		int v = 0;
		while (v == 0) {
			int u = 0;
			while (u < 1) {
				for (int j = 2; j < m; j++) {
					if (m % j == 0) {
						u++;
						break;
					}
				}
				m++;
			}
			m--;
			Beal_lowestBnt<unsigned long long int> a(m);
			a.findEquation();
			if (m == a.get_bnt()) {
				cout << a;
				m++;
				v++;
			}
			else
			{
				m = a.get_bnt();
			}
		}
	}
}

void Qusetion_6() {
	for (int r = 32; r < 317; r++) {
		unsigned long long int m = r * r;
		int u = 0;
		for (int y = 1; y < 17; y++) {
			int c = pow(2, y);
			int p = m - 2 - c;
			if (p % (2 * y + 1) == 0) {
				int q = p / (2 * y + 1);
				int x = y * q - 1;
				//cout << m << endl;
				cout << m << ':' << 2 << ',' << x << ',' << 2 << ',' << x << ',' << c << ',' << q << endl;
				u++;
				break;
			}
		}
		if (u == 0)
			cout << m << "is fail" << endl;
	}
}

void Question_7() {
	int min = 0;
	int max = -1;
	int t = 0;
	while (t == 0) {
		cout << "Please enter the minimun BNT(>15):(if BNT>100, it need a long time to find.)" << endl;
		//scanf("%d", &min);
		cin >> min;
		cin.clear();
		while (cin.get() != '\n');
		if (min < 16) {
			cout << "Please enter the appropriate numbers." << endl;
			continue;
		}
		cout << "Please enter the maximum BNT:" << endl;
		cin >> max;
		cin.clear();
		while (cin.get() != '\n');
		if (max < min) {
			cout << "Please enter the appropriate numbers." << endl;
			continue;
		}
		if (max > 150) {
			cout << "Max is too large, and it need a long time to find. Change number please." << endl;
			cout << "Please enter the maximum BNT" << endl;
			cin >> max;
			cin.clear();
			while (cin.get() != '\n');
			if (max < min) {
				cout << "Please enter the appropriate numbers." << endl;
				continue;
			}
		}
		t = 1;
	}
	for (int i = min; i <= max; i++) {
		Beal_ASCII<unsigned long long int> a(i);
		a.findEquation();
		cout << a;
	}
}

void Proof() {
	cout << "BNT is infinity" << endl;
	cout << "Proof:" << endl;
	cout << "a^x + b^y = c^z," << endl;
	cout << "if a=b=2^m,c=2^n,x=y,(m>1,n>1), so (2^m)^x + (2^m)^x = (2^n)^z" << endl;
	cout << "so 2^(m*x) + 2^(m*x) = 2^(n*z)" << endl;
	cout << "because 2^(m*x) + 2^(m*x) = 2^(n*z), so n*z = m*x + 1" << endl;
	cout << "and BNT1 = 2^m + x + 2^m + x + 2^n + z = 2^(m+1) + 2^n + 2x + z" << endl;
	cout << "if BNT1 is largest," << endl;
	cout << "if x_new = x + z, we can find a new Beal equation." << endl;
	cout << "a¡¢b still is 2^m, m*x_new + 1 = m*(x+z) +1 = m*x + m*z +1 = n*z + m*z = (n+m)*z" << endl;
	cout << "so n_new = n+m, c_new = 2^n_new = 2^(n+m)" << endl;
	cout << "so (2^m)^x_new + (2^m)^x_new = (2^n_new)^z" << endl;
	cout << "so (2^m)^(x+z) + (2^m)^(x+z) = (2^(n+m))^z" << endl;
	cout << "and BNT2 = 2^m + x_new + 2^m + x_new + 2^n_new + z = 2^(m+1) + 2^n_new + 2x_new + z" << endl;
	cout << "BNT2 = 2^(m+1) + 2^(n+m) + 2*(x+z) + z = 2^(m+1) + 2^(n+m) + 2x + 3z" << endl;
	cout << "BNT2 - BNT1 = 2^(n+m) - 2^n + 2z > 0 , so BNT2 > BNT1" << endl;
	cout << "so BNT is infinity" << endl;
}
int Example() {
	cout << "For example: 23:4^4 + 4^4 = 8^3, 57:4^7 + 4^7 = 32^3" << endl;
	char t;
	t = 'y';
	int a = 4;
	int n = 3;
	int x = 4;
	int z = 3;
	while (t == 'y') {
		cout << "Show largest? Yes-'y'or'Y'/No-'other'n'or'N'" << endl;
		cin >> t;
		cin.clear();
		while (cin.get() != '\n');
		if (t == 'Y' || t == 'y') {
			t = 'y';
			n = 2 + n;
			x = x + z;
			if (x >= 46) {
				cout << "Sorry. It is too larget, computer cannot show it£¡" << endl;
				break;
			}
			int c = pow(2, n);
			int bnt = a + a + x + x + c + z;
			cout << bnt << ':' << a << '^' << x << " + " << a << '^' << x << " = " << c << '^' << z << endl;
		}
		else {
			if (t != 'n' && t != 'N') {
				cout << "Please press 'y'/'Y' or 'n'/'N'!" << endl;
				t = 'y';
			}
		}
	}
	return 0;
}