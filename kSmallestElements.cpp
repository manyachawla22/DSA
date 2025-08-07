#include<iostream>
#include<vector>
#include<queue>

using namespace std;

priority_queue<int> kSmallestElements(int arr[], int size, int k){
    priority_queue<int> ans;
    for(int i = 0;i<k;++i ){
        ans.push(arr[i]);
    }
    int i = k;
    for(int i = k; i<size; ++i){
        if(arr[i]<ans.top()){
            ans.pop();
            ans.push(arr[i]);
        }
    }
    return ans;
}

int main(){
    int arr[] = {8,9,34,5,6,3,2,33,4,7};
    priority_queue<int> ans = kSmallestElements(arr,10,4);
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << endl;
    return 0;
}
