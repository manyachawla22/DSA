#include<vector>
#include<algorithm>
using namespace std;
void insert(vector<int>&pq, int size){
    int node = size;
    int parent  = (node-1)/2;
    while(node != 0 && pq[parent]<pq[node]){
        int temp = pq[parent];
        pq[parent] = pq[node];
        pq[node] = temp;

        node = parent;
        parent = (node -1)/2;
    }
}

void remove(vector<int>& pq, int size){
    int temp = pq[0];
    pq[0] = pq[size-1];
    pq[size-1] = temp;
    size--;
    int node = 0;
    int left = node*2 + 1;
    int right = node*2 + 2;
    
    while(node<size && ( (left<size && pq[node]<pq[left]) || (right<size && pq[node]<pq[right]))){
        int max;
        if(left<size && right<size)
            max = (pq[left]<pq[right]) ? right : left;
        else if(left<size)
            max = left;
        else break;
        int temp = pq[node];
        pq[node] = pq[max];
        pq[max] = temp;

        node = max;
        left = node*2 +1;
        right = node*2 +2;
    }
}

void heapSort(vector<int>& arr){
    if(arr.size() == 0 || arr.size() == 1)
        return;
    int arrStart = 1;
    int arrEnd = arr.size()-1;
    while(arrStart<=arrEnd){
        insert(arr,arrStart);
        arrStart++;
    }
    arrEnd = arr.size();
    arrStart = 0;
    while(arrEnd>arrStart){
        remove(arr,arrEnd);
        arrEnd--;
    }
    // this is using max heap -> ascending order after sorting
    // for descending order either use min heap or we will use reverse:
    reverse(arr.begin(),arr.end());



}

