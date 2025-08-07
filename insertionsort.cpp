void insertionSort(int arr[], int n)
{
    for ( int i=1; i<n; ++i ){
        int current = arr[i];
        int j= i-1;
        while ( j>=0){
            if ( current < arr[j] )
                arr[j+1] = arr[j];
            else
                break;
            --j;
        }
        arr[j+1] = current;
    }
}
