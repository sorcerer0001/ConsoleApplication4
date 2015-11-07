#include <iostream>
using namespace std;

int main() {
	double dIn;
	cin >> dIn;

	cout.setf(ios::fixed);
	cout.precision(5);
	cout << dIn << endl;

	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout.precision(7);
	cout << dIn << endl;

	//system("pause");
}
