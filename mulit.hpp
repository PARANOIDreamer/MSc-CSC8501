#pragma once
#include<iostream>
#include <string>

using namespace std;


string getAdd(string a, string b)
{
	int bit = 0;
	int len_a = a.length();
	int len_b = b.length();
	string c = "";
	if (len_a <= len_b) {
		for (int i = 1; i <= len_a; i++) {
			int t1 = a[len_a - i] - 48;
			int t2 = b[len_b - i] - 48;
			int sum = t1 + t2 + bit;
			bit = floor(sum / 10);
			int num = sum % 10;
			c = c + to_string(num);
		}
		for (int j = 1; j <= len_b - len_a; j++) {
			int t2 = b[len_b - len_a - j] - 48;
			int sum = t2 + bit;
			bit = floor(sum / 10);
			int num = sum % 10;
			c = c + to_string(num);
		}
		if (bit != 0)
			c = c + to_string(bit);
	}
	else {
		for (int i = 1; i <= len_b; i++) {
			int t1 = a[len_a - i] - 48;
			int t2 = b[len_b - i] - 48;
			int sum = t1 + t2 + bit;
			bit = floor(sum / 10);
			int num = sum % 10;
			c = c + to_string(num);
		}
		for (int j = 1; j <= len_a - len_b; j++) {
			int t1 = a[len_a - len_b - j] - 48;
			int sum = t1 + bit;
			bit = floor(sum / 10);
			int num = sum % 10;
			c = c + to_string(num);
		}
		if (bit != 0)
			c = c + to_string(bit);
	}
	string cReverse(c.rbegin(), c.rend());
	return cReverse;
}

template <typename T>
string getPow(T a, T b)
{
	string a1 = to_string(a);
	string a2 = a1;
	T len_m = a1.length();
	T len_n = a2.length();
	int bit = 0;
	for (int i = 1; i < b; i++) {
		string c = "0";
		for (T j = 1; j <= len_m; j++) {
			int m = a1[len_m - j] - 48;
			string temp = "";
			for (T k = 1; k <= len_n; k++) {
				int n = a2[len_n - k] - 48;
				int mul = m * n + bit;
				bit = floor(mul / 10);
				int num = mul % 10;
				temp = temp + to_string(num);
			}
			if (bit != 0)
				temp = temp + to_string(bit);
			bit = 0;
			string tempR(temp.rbegin(), temp.rend());
			for (T x = 1; x < j; x++)
				tempR = tempR + '0';
			c = getAdd(tempR, c);
		}
		a2 = c;
		len_n = a2.length();
	}
	return a2;
}