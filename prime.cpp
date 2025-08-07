#include <iostream>
#include <math.h>
#include<vector>
#include"ioVectors.h"
using namespace std;


bool isPrime(int p)
{
    if(p<=1)
        return false;
    if (p==2)
        return true;
    else if (p%2==0)
        return false;
        else{
        int i=3;
        while(i<=sqrt(p)){
                if (p%i==0){
                return false;
            }
            else
                i+=2;
        }
        return true;
    }
}

vector<int> primeTillN(int n)
{
    vector<int> prime;
    for( int i=2; i<=n; ++i ){
        if (isPrime(i) == true)
            prime.push_back(i);
    }
    return prime;
}
// Turing code for quesion: break n into prime pieces and add them up until n cant be broken
// n = 12 -> 12 = 2*2*3 -> n = 2+2+3 = 7
// n = 9 -> 9 = 3*3 -> n = 3+3 = 6, now 6 = 2*3 -> n = 2+3 = 5

int smallestN(int n){
    if(n<=2 || isPrime(n))
        return n;
    vector<int> prime = primeTillN(n);
    while(!isPrime(n)){
        int sum = 0;
        for(int i = 0; prime[i]<=n;++i){
            if(n%prime[i] == 0){
                sum+= prime[i];
                n/=prime[i];
                i=-1;
            }
            if(n==1){
                n = sum;
                break;
            }
        }
    }
    return n;
}

int main(){
    int n;
    cout << "ENTER N" << endl;
    cin >> n;
    /*vector<int> prime = primeTillN(n);
    outputVector(prime);*/
    cout << smallestN(n) << endl;
    return 0;

}

