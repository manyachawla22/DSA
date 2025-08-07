#include<iostream>
#include<vector>
#include<queue>
#include"ioArray.h"
using namespace std;

void outputArr(int arr[], int size);

void sortKSorted(int arr[], int size, int k){
    priority_queue<int> pq;
    for(int i =0; i < k; i++){
        pq.push(arr[i]);
    }
    int i = 0;
    for(int j = k; j<size;++i,j++){
        arr[i] = pq.top();
        pq.pop();
        pq.push(arr[j]);
    }
    while(!pq.empty()){
        arr[i] = pq.top();
        pq.pop();
        i++;
    }
}

int main(){
    int arr[] = {12,15,7,4,9};
    sortKSorted(arr,5,3);
    outputArr(arr,5);
    return 0;
}
