#include<iostream>
#include<algorithm>
using namespace std;

bool isSumInArr(int arr[], int size, int num){
    if( size == 0 )
        return false;
    int i = size-1;
    while( arr[i]>num ){
        --i;
    }
    bool result = false;
    if( arr[i] == num )
        return true;
    else 
        result = isSumInArr( arr, i, num-arr[i] );
    return result;
}
bool splitArray(int *input, int size){
    int arr[size],n=0;
    int s5 = 0, s3= 0, s=0;
    for(int i = 0; i<size; ++i){
        if( input[i] % 5 == 0 ){
            s5+=input[i];
        }
        else if( input[i] % 3 == 0){
            s3+=input[i];
        }
        else{
            arr[n]=input[i];
            ++n;
        }
    }
    int target = abs(s5-s3);
    
    if( (n<target) || (n-target)%2 != 0)
        return false;
    int req = (n - target)/2;
    sort(arr,arr+n);
    return isSumInArr(arr,n,req);
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}

