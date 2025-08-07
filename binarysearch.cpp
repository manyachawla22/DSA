int binarysearch( int arr[], int n, int x) {
    int start=0, end= n-1;
    while( start<=end){
        int mid = (start+end)/2;
        mid = (start+end)/2;
        if ( arr[mid] == x )
            return mid;
        else if ( arr[mid] < x )
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}
