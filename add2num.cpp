#include <iostream>
using namespace std;
int main()
{
	int a;
	int b;
	cout << "Input both the numbers" << endl;
	cin >> a >> b;
	int sum = a + b;
	cout << "The sum is = " << sum << endl;	
	int size= sizeof(sum);
	cout << "size of sum = " << size << endl;
	return 0;
}
