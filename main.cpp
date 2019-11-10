#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long double a = 1;
	long double u = 6;
	long double pi = 3;
	long double h = sqrt(0.75);
	long double x = 1-h;

	/*bool simple;
	cout << "Simplified Output? (0 - 1): ";
	cin >> simple;*/

	int coutp;
	cout << "Output Length (1 - 75): ";
	cin >> coutp;
	cout.precision(coutp);

	/*int cycles;
	cout << "Precision (): ";
	cin >> cycles;*/

	cout << endl << \
	"n =  " << 6 << endl << \
	"a" << 6 << " =  " << a << endl << \
	"u" << 6 << " =  " << u << endl << \
	"h" << 6 << " =  " << h << endl << \
	"x" << 6 << " =  " << x << endl << \
	"PI = " << pi << endl;


	for (long long n = 12; n < 1000000; n*=2) {
		a = sqrt((0.5*a)*(0.5*a)+x*x);
		u = n*a;
		pi = u/2;
		h = sqrt(1-(0.5*a)*(0.5*a));
		x = 1-h;

		cout << endl << \
		"n =  " << n << endl << \
		"a" << n << " =  " << a << endl << \
		"u" << n << " =  " << u << endl << \
		"h" << n << " =  " << h << endl << \
		"x" << n << " =  " << x << endl << \
		"PI = " << pi << endl;
	}
}
