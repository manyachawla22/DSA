#include <iostream>
using namespace std;
int main()
{
	int p = 1000;
	int r = 5;
	int t = 3;
	float si = (p*r*t)/100;
	float a = p + si;
	cout << "The simple interest is = " << si << endl << "The total amount to be paid is = " << a << endl;
	return 0;
}
