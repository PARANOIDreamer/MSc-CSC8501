#include "bealLowbnt.hpp"
#include "bealLimit.hpp"
#include "bealASCII.hpp"
#include "question.hpp"

int main() {
	int x;
	cout << "Hello! Welcome to explore the Beal Conjecture!" << endl;
	while (true){
		cout << "Questions: Q1.First 5 BNTs. Q2.First 5 BNTs(prime numbers). Q3.All equations(a,b,c:3-20, x,y,z:3-15)." << endl;
		cout << " Q4.(Not choise)Outputs to file. Q5.First 10 BNTs(composite numbers). Q6.BNTs(square numbers:1000-100,000)." << endl;
		cout << " Q7.Histogram of BNTs. Q8.Highest BNT." << endl;
		cout << "Choose Questions by keyboard button: Q1-1 Q2-2 Q3-3 Q5-5 Q6-6 Q7-7 Q8-8 Exit-9." << endl;
		cin >> x;
		switch (x)
		{
		case 1: {
			string q = "Q1:";
			File(q);
			Question_1();
			break;
		}
		case 2: {
			string q = "Q2:";
			File(q);
			Question_2();
			break;
		}
		case 3: {
			string q = "Q3:";
			File(q);
			Question_3();
			break;
		}
		case 5: {
			string q = "Q5:";
			File(q);
			Question_5();
			break;
		}
		case 6: {
			Qusetion_6();
			break;
		}
		case 7: {
			Question_7();
			break;
		}
		case 8: {
			Proof();
			Example();
			break;
		}
		case 9: {
			cout << "END" << endl;
			return 0;
		}
		default:
			cout << "Please enter a correct number!" << endl;
			cin.clear();
			while (cin.get() != '\n');
			break;
		}
	}
	cout << "END" << endl;
	return 0;
}