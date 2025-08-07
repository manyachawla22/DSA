#include<iostream>
using namespace std;

const int MOD = 1000000007;

int staircase(int n){
    if(n == 0 || n == 1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    long long *arr = new long long[n+1];
    arr[0] = 1, arr[1]=1, arr[2]=2, arr[3]=4;
    for(int i = 4; i<=n; ++i){
        arr[i] = (arr[i-1]+arr[i-2]+arr[i-3])%MOD; 
    }
    int ans = arr[n];
    delete[]arr;
    return ans;
}

int main()
{
    int t,n;
    cin >> t;
    for(int i = 0; i<t; ++i){
        cin >> n;
        cout << staircase(n) << endl;
    }
    return 0;
}
