#include<iostream>
using namespace std;
void print_arr( int arr[], int n );
void bubblesort( int arr[], int n ){
    for ( int j=0; j<(n-1); ++j ){
        for( int i = 0; i<(n-j-1); ++i ){
            if ( arr[i] > arr[i+1] ){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        print_arr( arr, n );
    }
}
