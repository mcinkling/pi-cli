#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	// Set the initial values
	long double a = 1;
	long double u = 6;
	long double h = sqrt(0.75);
	long double x = 1-h;

	string input;

	// Boolean that stops unnecessary variables from being printed later
	bool fulloutp = 0;
	cout << "Full Output? (0 - 1) [default: 0]: ";
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> fulloutp;
	}

	// Set the amount of digits after the decimal point
	int coutp = 25;
	cout << "Output Length (1 - 75) [default: 25]: ";
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> coutp;
	}
	cout.precision(coutp);

	// Set how often the following for loop will be repeated	longer = more accurate
	long long sides = 100000;
	cout << "Amount of sides on the circle (6 - inf) [default: 100000]: ";
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> sides;
	}

	// Output the values for hexagon
	if (fulloutp == true) {
		cout << endl << \
		"a" << 6 << "  =  " << a << endl << \
		"u" << 6 << "  =  " << u << endl << \
		"h" << 6 << "  =  " << h << endl << \
		"x" << 6 << "  =  " << x << endl;
	}
	cout << "pi6 =  " << 3 << endl;


	// Increase the amount of sides in order to get closer to a circle
	for (long long n = 12; n <= sides; n*=2) {
		a = sqrt((0.5*a)*(0.5*a)+x*x);
		u = n*a;
		h = sqrt(1-(0.5*a)*(0.5*a));
		x = 1-h;

		if (fulloutp == true) {
			// Output the values used for the calculation, if Full Output was enabled
			cout << endl << \
			"a" << n << "  =  " << a << endl << \
			"u" << n << "  =  " << u << endl << \
			"h" << n << "  =  " << h << endl << \
			"x" << n << "  =  " << x << endl;
		}
		cout << "pi" << n << " =  " << u/2 << endl;
	}
}
