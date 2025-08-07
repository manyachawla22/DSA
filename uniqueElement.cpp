#include <iostream>
using namespace std;
int input_arr( int input[] );

// n is no of pairs in the array and size = 2n+1
int uniqueElement( int *arr, int n ){
    int result = 0;
    for( int i =0; i<= (2*n); ++i )
        result ^= arr[i];
    return result;
}

int main(){
    int *arr = new int[1000];
    int size = input_arr(arr);
    int unique = uniqueElement(arr, (size-1)/2);
    cout << unique << endl;
    delete [] arr;
    return 0;
}
