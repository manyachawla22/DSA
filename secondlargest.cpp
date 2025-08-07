#include <iostream>
using namespace std;
int main()
{
    int n, curr, max, secondmax;
    max = secondmax= -(2 << 30);
    cin >> n;
    if ( (n==1) || (n==0) )
        cout << -(2 << 30) << endl;
    else if( n==2 ){
        cin >> max >> secondmax;
        if ( max > secondmax )
            cout << secondmax << endl;
        else
            cout << max << endl;
    }
    else{
        for ( int i=0; i<n; i++ ){
            cin >> curr;
            if ( curr>max ){
                secondmax=max;
                max=curr;
            }
        }
        cout << secondmax << endl;
    }
    return 0;
}
