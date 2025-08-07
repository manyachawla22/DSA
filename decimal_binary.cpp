#include<iostream>
using namespace std;
int main (){
    int n, i;
    cin >> n;
    if ( n==0)
        cout << 0;
    else {
        int arr[32];
        for (i = 0; n > 0; ++i) {
            arr[i] = (n % 2);
            n /= 2;
        }
        for (int j = i - 1; j >= 0; --j)
            cout << arr[j];
    }
    cout << endl;
}
