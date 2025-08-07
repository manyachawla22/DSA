/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Time complexity should be O(h).
*/

const int prime = 1000000007;

int balancedBTs(int n) {
    int * arr = new int[n+1];
    arr[0] = 1, arr[1] = 1;

    for(int i = 2; i<=n; ++i){
        long long h1 = arr[i-1];
        long long h2 = arr[i-2];
        long long sqH1 = (h1*h1)%prime;
        long long h1H2 = (h1*h2)%prime;
        h1H2 = (2*h1H2) % prime;
        int soln = (sqH1+h1H2)%prime;
        arr[i] = soln;
    }
    int soln = arr[n];
    delete [] arr;
    return soln;
}
