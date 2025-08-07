#include <iostream>
using namespace std;
int main()
{
	int f;
	cout << "Enter the fahrenheit value" << endl;
	cin >> f;
	int c = (f-32)*(5.0/9);
	cout << "The celsius value = " << c << endl;
	return 0;
}
