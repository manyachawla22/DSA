#include <iostream>
using namespace std;
void print_arr( int arr[],int n );
int input_arr( int arr[] );
void selectionsort( int arr[], int n )
{
    for ( int i=0; i<(n-1); ++i ){
        int min = arr[i];
        int index= i;
        for( int j=i+1; j<n; ++j ){
            if ( min > arr[j] ){
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
}
