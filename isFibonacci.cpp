#include<iostream>
using namespace std;
bool isFibonacci(int n)
{
    int f, f1, f2;
    f=f1=f2=1;
    if ( (n==1) || (n==2) )
        return true;
    else{
        while ( f <= n ) {
          f = f1 + f2;
          f1 = f2;
          f2 = f;
        }
        if ( f1== n )
            return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    cout << isFibonacci(n) << endl;
}
