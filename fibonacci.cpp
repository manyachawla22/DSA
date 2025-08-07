#include <iostream>
using namespace std;

// regular function:
int fibonacciSeries( int n ){
    if ( n <= 1 )
        return n;
    int num = fibonacciSeries( n-1 ) + fibonacciSeries( n-2 );
    return num;
}

// I have not used memoization, this is bottom-top approach->Tabulation, memoization is top-down
// it would have been memoized, if i would have actually cached the data, and used whenever i want to, here i am calucating and using it then and there.
// with DP: can also be done by using a simple for loop!
void helperFibo(int n, int* arr, int index){
    if(index > n)
        return;
    arr[index] = arr[index-1] + arr[index-2];
    helperFibo(n,arr,index+1);
}
//can be further improvised, by having oinly 2 variables in storage instead of array
int fibonacci(int n){
    if(n<=1)
        return n;
    int* arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    helperFibo(n, arr,2);
    int ans =  arr[n];
    delete [] arr;
    return ans;
}


// with optimsed space as well:
void helper(int n, pair<int,int>*memo, int index){
    if(index>n)
        return;
    int sum = memo->first + memo->second;
    memo->first = memo->second;
    memo->second = sum;
    helper(n,memo,index+1);
}

int fibo(int n){
    if(n<=1)
        return n;
    pair<int,int> memo;
    memo.first = 0;
    memo.second = 1;
    helper(n,&memo,2);
    return memo.second;
}

int main(){
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    cout << fibonacci(n) << endl;
    cout << fibonacciSeries(n) << endl;
    cout << fibo(n) << endl;
    return 0;
}

