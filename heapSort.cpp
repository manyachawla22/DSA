#include"heapSort.h"
#include"ioVectors.h"
#include<vector>
using namespace std;
void outputVector(vector<int>&vec);
int main(){
    vector<int> arr ;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(20);
    heapSort(arr);
    reverse(arr.begin(),arr.end());
    outputVector(arr);
}
