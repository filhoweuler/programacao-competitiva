#include <bits/stdc++.h>

using namespace std;

typedef long double C;
typedef complex<C> P;

#define pi 3.141516
#define X real()
#define Y imag()

double deg(double rad) { return (rad*180.0)/M_PI; }

int main () {
	P x(5, 5);
	cout << abs(x) << endl;
	cout << deg(arg(x)) << endl;
	x *= polar(1.0, -M_PI);
	cout << deg(arg(x)) << endl;
}
