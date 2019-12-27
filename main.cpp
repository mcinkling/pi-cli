#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	// Set the initial values, to start the calculation from
	long double lps = 1;  // The lenght per side is set to 1
	long double cir = 6;  // The circumference of hexagon (with a length per side of 1) is 6
	long double lrd = sqrt(0.75);  // The lowest "radius" / 
	long double dif = 1-lrd;  // The difference between the 'lrd' and the radius of a perfect circle (1)

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

	// Set how often the following for loop will be repeated; longer = more accurate
	long long sides = 100663296;
	cout << "Amount of sides on the circle (6 - inf) [default: 100,663,296]: ";
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> sides;
	}
    
	// Output the values for a hexagon
	cout << "PI6* 2^0\t=   " << 3 << endl;
	if (fulloutp == true) {
		cout << "lps6* 2^0\t=   " << lps << endl << \
                "cir6* 2^0\t=   " << cir << endl << \
                "lrd6* 2^0\t=   " << lrd << endl << \
                "dif6* 2^0\t=   " << dif << endl << endl;
	}


	// Increase the amount of sides in order to get closer to a circle
	for (long long n = 12; n <= sides; n*=2) {
		lps = sqrt((0.5*lps)*(0.5*lps)+dif*dif);
		cir = n*lps;
		lrd = sqrt(1-(0.5*lps)*(0.5*lps));
		dif = 1-lrd;

		cout << "PI6* 2^" << log2(n/6) << "\t=   " << cir/2 << endl;
        if (fulloutp == true) {  // Output the values used for the calculation, if Full Output was enabled
			cout << "lps6* 2^" << log2(n/6) << "\t=   " << lps << endl << \
                    "cir6* 2^" << log2(n/6) << "\t=   " << cir << endl << \
                    "lrd6* 2^" << log2(n/6) << "\t=   " << lrd << endl << \
                    "dif6* 2^" << log2(n/6) << "\t=   " << dif << endl << endl;
		}
	}

    cout << "Done! Press 'Enter' to close...";
    cin.ignore();
}
