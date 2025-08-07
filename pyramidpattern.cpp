#include <iostream>
using namespace std;
int main()
{
    int n,i,j, val;
    cout << "Enter n" << endl;
    cin >> n;
    for (i=1; i<=n; i++){
        for(j=1;j<=(n-i);j++)
            cout << " ";
        for(j=1; j<=i; j++)
            cout << j;
        for ( j= (i-1); j>0; j-- )
            cout << j;
        cout << endl;
    }
    for (i=1; i<=n; i++){
        for(j=1;j<=(n-i);j++)
            cout << " ";
        val=i;
        for(j=1; j<=i; j++){
            cout << val;
            ++val;
        }
        val=i;
        for ( j=1; j<i; j++ ){
            cout << val;
            --val;
        }
        cout << endl;
    }
        return 0;
}
