#include <iostream>
using namespace std;
int main()
{
	int a, b;
    cout << "Enter the two numbers\n";
    cin >> a >> b;
    if (a>b){
        cout << "A is greater than b\n";
    }
    else if (a==b){
        cout << "A is equal to b\n";
    }
    else{ 
        cout << "A is smaller than b\n";
    }
    return 0;
}
