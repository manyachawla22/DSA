#include<iostream>
#include<vector>

using namespace std;

int bookAllocation(int*arr, int size, int n){
    if(size == 0 || size<n)
        return -1;
    if(n == 1){

    }
    
    //find the mid of total sum!
    int startSum = arr[0], endSum = arr[size-1], i ,j;
    for(int i = 1, j = size - 1; i<j;){
        if(startSum < endSum){
            startSum+=arr[i];
            ++i;
        }
        else{
            --j;
            endSum+=arr[j];
        }
    }
    int left,right;
    if(n%2==0){
        left = bookAllocation(arr,i+1,n/2);
        right = bookAllocation(arr+j,size-j,n/2); 
    }
    else{
        left = bookAllocation(arr,i+1,n/2+1);
        right = bookAllocation(arr+j,size-j,n/2);
    }
    return max(left,right);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    cout << "Enter no of students" << endl;
    cin >> n;
    cout << bookAllocation(arr,10,n) << endl;
    return 0;
}
