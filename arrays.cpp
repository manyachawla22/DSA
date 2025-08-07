#include <iostream>
#include <climits>
using namespace std;

void printarr( int b[], int n ){
    for ( int i=0; i<n; ++i )
        cout << b[i] << " " ;
    cout << endl;
}

int linearsearch( int arr[], int n, int x ){
    for( int i=0; i<n; ++i )
        if ( arr[i]==x )
            return i;
    return -1;
}

void reverse( int arr[], int n ){
    for( int i=1; i<=(n/2); ++i ){
        int x= arr[i-1];
        arr[i-1]=arr[n-i];
        arr[n-i]=x;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    // input from user
    for ( int i=0; i<n; ++i )
        cin >> arr[i];
    reverse(arr,n);
    printarr( arr,n );
    
    /* // finding max
    int max = INT_MIN;
    for ( int i=0; i<n; ++i )
        if ( arr[i]>max )
            max = arr[i];
    cout << max << endl;
    
    //printing array
    cout << "Print array" << endl;
    printarr(arr, n);
    
    for ( int i=0; i<n; ++i )
        cout << arr[i] << " " ;
    cout << endl;
    
    // finding sum
    int sum = 0;
    for ( int i=0; i<n; ++i )
        sum += arr[i];
    cout << sum << endl;
    
    // cout arr;
    cout << " Memory location is " << arr << endl;

    // sizeof
    cout << sizeof(arr) << endl;*/
    
    return 0;
}
