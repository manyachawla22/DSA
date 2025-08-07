void mergeArr( int arr[], int start, int end){
    
    int mid = ( start + end ) /2;
    int i = start;
    int j = mid +1;
    int size = end - start + 1;
    int * temp= new int [size];
    int k = 0;
    for( ; (k < size) && (i<=mid) && (j<=end); ++k ){
        if( arr[i] < arr[j] ){
            temp[k] = arr[i];
            ++i;
        }
        else{
            temp[k] = arr[j];
            ++j;
        }
    }
    if( i > mid){
        while (k < size) {
            temp[k] = arr[j];
            ++k;
            ++j;
        }
    }
    else{
        while( i<=mid){
            temp[k] = arr[i];
            ++i;
            ++k;
        }
    }
    for( int k =0; k < size; ++k, ++start )
        arr[start] = temp[k];
    delete [] temp;
}

void mergeSort(int arr[], int start, int end) {
    if( start >= end)
        return;
    int mid = ( start + end)/2;
    mergeSort( arr, start, mid );
    mergeSort( arr,  mid +1 , end);
    mergeArr( arr, start, end);
}


#include <iostream>
using namespace std;

/*int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}*/
