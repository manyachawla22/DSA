#include<iostream>
#include<vector>
using namespace std;

int subsetSum(vector<int>& arr, int target, int index){    
    if(arr.size() == index){
        return (target == 0) ? 1 : 0;
    }
    int ans = 0;
    ans += subsetSum(arr, target - arr[index], index+1 );
    ans += subsetSum(arr, target, index+1 );

    return ans; 
}

int main(){
    int testCases;
    cin >> testCases;
    for(int i = 0; i<testCases;++i){
        cin.ignore();
        int size, target;
        cin >> size >> target;
        vector<int> arr;
        for(int j = 0; j<size;++j){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << subsetSum(arr,target,0) << endl;
    }
    return 0;
}
