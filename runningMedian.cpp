/*
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.

Print only the integer part of the median.
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/
#include<queue>
#include<iostream>
using namespace std;
void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    for(int i = 0; i<n;++i){
        int median;
        if(maxHeap.empty() || arr[i]<= maxHeap.top())
            maxHeap.push(arr[i]);
        else
            minHeap.push(arr[i]);

        if(minHeap.size() > 1 + maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() > 1 + minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() == minHeap.size()){
            median = (maxHeap.top() + minHeap.top())/2;
        }
        else{
            median = (maxHeap.size()>minHeap.size()) ? maxHeap.top() : minHeap.top();
        }
        cout << median << ' ';
    }
    cout << endl;
}
int main(){
    int arr[] = {5,4,3,2,1};
    findMedian(arr,5);
    return 0;
}
