#include<iostream>
using namespace std;
int main()
{
		int n, i, j ;
        cin >> n;
        for ( i=0; i<n; i++){
            for (j=0; j<n; j++)
                cout << n;
            cout << endl;
        }
        cout << endl;
        for ( i=1; i <= n; i++){
            for (j=0; j<n; j++)
                cout << i;
            cout << endl;
        }
        cout << endl;
        for ( i=1; i <= n; i++){
            for (j=1; j<=n; j++)
                cout << j;
            cout << endl;
        }
        cout << endl; 
        for ( i=1; i <= n; i++){
            for (j=n; j>0; j--)
                cout << j;
            cout << endl;
        }
        cout << endl;
        for ( i=0; i<n; i++){
            for (j=0; j<n; j++){
                cout << char('A'+ j );
            }
            cout << endl;
        }
        cout << endl;
        for ( i=0; i<n; i++){
            for (j=0; j<n; j++){
                cout << char('A'+ j + i);
            }
            cout << endl;
        }
        return 0;
}
