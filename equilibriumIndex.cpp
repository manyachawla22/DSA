#include<iostream>

using namespace std;

int inputArr( int input[] );

int main(){
    int arr[20];
    int size = inputArr(arr);
    int rightsum = 0, leftsum = 0; 
    for(int i = 0; i<size; ++i)
        rightsum += arr[i];
    for(int i=0; i<size; ++i){
        rightsum-=arr[i];
        if(leftsum == rightsum){
            cout <<"Equilibrum index  = " <<  i << endl;
            return 0;
        }
        leftsum+=arr[i];
    }
    cout << "No index found" << endl;
}
