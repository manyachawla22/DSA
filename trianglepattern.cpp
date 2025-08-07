#include <iostream>
using namespace std;
int main()
{
    int n, i, j, a;
    cout << "Enter n" << endl;
    cin >> n;
    for (i=1; i<=n; i++){
        a=i;
        for(j=0; j<i; j++){
            cout << a;
            a++;
        }
        cout << endl;
    }
    cout << endl;
    a=1;
    for (i=1; i<=n; i++){
        for(j=0; j<i; j++){
            cout << a;
            a++;
        }
        cout << endl;
    }
	cout << endl;
    for (i=1; i<=n; i++){
        for(j=0; j<i; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
