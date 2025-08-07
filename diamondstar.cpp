#include <iostream>
using namespace std;
int mod(int x);
int main()
{
	int n, i, j;
    cout << "Enter value of n (n can only be odd)" << endl;
    cin >> n;
    for ( i=0; i < ((n/2) +1); i++ ){
        for ( j=0; j < ((n/2) -i); j++ )
            cout << " ";
        for ( j=0; j < ((2*i) +1); j++ )
            cout << "*";
        cout << endl;
    }
    for ( i=1; i <= (n/2); i++ ){
        for ( j=0; j < i ; j++ )
            cout << " ";
        for ( j= (n-(2*i)); j>0; j-- )
            cout << "*";
        cout << endl;
    }
    cout << endl;
    for ( i=(n/2); i>=(-n/2); i-- ){
        for ( j = (-n/2); j <= (n/2); j++ ){
            if( (mod(j) + mod(i)) <= (n/2))  
                cout << "*";
            else 
                cout << " ";
        }
        cout << endl;            
    }
    return 0;
}
