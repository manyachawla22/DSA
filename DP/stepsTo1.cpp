#include<iostream>

using namespace std;
/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) 
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
*/

// the brute force method:

int countMinStepsToOne(int n)
{
	if(n == 1)
		return 0;
	int a = countMinStepsToOne(n-1);
	int b = (n%3 == 0) ? countMinStepsToOne(n/3) : a;
	int c = (n%2 == 0) ? countMinStepsToOne(n/2) : a;

	return min(a,min(b,c)) + 1;
}
// use memoization:

int helper(int n, int * arr){
    if(n == 1){
        arr[1] = 0;
        return 0;
    }
    if(arr[n] == -1){
        int a = helper(n-1,arr);
	    int b = (n%3 == 0) ? helper(n/3,arr) : a;
	    int c = (n%2 == 0) ? helper(n/2,arr) : a;
        int soln = min(a,min(b,c));
        arr[n] = soln+1;
    }
    return arr[n];
}

int countMinStepsToOne_UsingDP(int n){
    int * arr = new int[n+1];
    for(int i = 0; i<n+1; ++i){
        arr[i] = -1;
    }
    helper(n,arr);
    int ans = arr[n];
    delete []  arr;
    return ans;
}

// use tabulation:
int count(int n){
    int *arr = new int[n+1];
    arr[1] = 0;

    for(int i = 2; i<=n; ++i ){
        int a,b,c;
        a = arr[i-1];
        b = c = a;
        if(i%2 == 0)
            b = arr[i/2];
        if(i%3 == 0)
            c = arr[i/3];
        int soln = min(a,min(b,c))+1;
        arr[i] = soln;
    }
    int ans = arr[n];
    delete [] arr;
    return ans;

}

int main(){
    int n;
    cout << "Enter n " << endl;
    cin >> n;
    cout << countMinStepsToOne_UsingDP(n) << endl;
    cout << count(n) << endl;
    cout << countMinStepsToOne(n) << endl;
    return 0;
}
