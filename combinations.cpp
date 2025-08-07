#include <iostream>
using namespace std;
int factorial(int f){
    int fac=1;
    for ( int i=1; i<=f; ++i )
        fac*=i;
    return fac;
}
int combination( int n, int r ){
    return ( factorial(n)/ ( factorial(r) * factorial(n-r) ) );
}
int main(){
    int n, r;
    cin >> n >> r;
    cout << combination(n,r) << endl;
}
