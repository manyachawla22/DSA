#include<iostream>
#include<vector>

using namespace std;

void mergeSort(int arr[], int start, int end);
int inputArr( int input[] );
void outputArr( int b[], int n );

int main(){
    int x;
    cout << "Enter x" << endl;
    cin >> x;
    int arr[50];
    int size  = inputArr(arr);
    mergeSort(arr,0,size-1);
    int count = 0, i =0, j = size-1;
    while(i<j){
        if(arr[i] + arr[j] == x){
            if(arr[i]==arr[j]){
                int ci = 1;
                while(i<j){
                    ++ci;
                    ++i;
                }
                count+= (ci-1)*ci/2;
                break;
            }
            else {
                int ci = 1, cj = 1;
                while( (i<j) && arr[i] == arr[i+1]){
                    ++ci;
                    ++i;
                }
                while ((i < j) && arr[j] == arr[j - 1]) {
                    ++cj;
                    --j;
                }
                count += ci * cj;
                --j;
                ++i;
            }
        }
        else if (arr[i] + arr[j] > x)
            --j;
        else
            ++i;
    }
    cout << "The no of pairs = " << count << endl;
    return 0;
}
