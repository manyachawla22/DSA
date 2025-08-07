#include<iostream>
#include<vector>

using namespace std;

int bruteForce(int* weight, int* value, int cap, int size){
    if(size<=0 || cap <= 0)
        return 0;

    //cout << "This is the call stack, the value and weight and capacity is" << value[0] << ' ' <<  weight[0] << ' '<< cap << endl; 
    int include = (weight[0] <= cap) ? bruteForce(weight+1, value+1, cap - weight[0], size-1) + value[0] : 0;
    int exclude = bruteForce(weight+1, value+1, cap,size-1);

    return max(include,exclude);
}


int helper(int* weight, int *value,int cap, int size, int** arr){
    if(size<=0 || cap <= 0)
        return 0;

    if(arr[size][cap] != -1)
        return arr[size][cap];
    int include = (weight[0] <= cap) ? helper(weight+1, value+1, cap - weight[0], size-1,arr) + value[0] : 0;
    int exclude = helper(weight+1, value+1, cap,size-1,arr);

    arr[size][cap]= max(include,exclude);
    return arr[size][cap];
}

int memo(int *weight, int *value, int cap, int size){
    int** arr = new int*[size+1];
    for(int i = 0; i<=size;++i){
        arr[i] = new int[cap+1];
    }

    for(int i = 0; i<=size;++i){
        for(int j = 0; j<=cap;++j)
            arr[i][j] = -1;
    }

    int ans = helper(weight,value,cap,size,arr);

    for(int i = 0; i<=size;++i){
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int DP(int *weight, int *value, int cap, int size){
    int** arr = new int*[size+1];
    for(int i = 0; i<=size;++i){
        arr[i] = new int[cap+1];
    }

    arr[size][0] = (weight[size] == 0) ? value[size] : 0;
    for(int i = size-1; i>=0;--i){
        for(int j = 0; j<=cap;++j){
            if(i == size)
                continue;
            if(weight[i]>j)
                arr[i][j] = arr[i+1][j];
            else{
                arr[i][j] = max(value[i]+arr[i+1][j-weight[i]], arr[i+1][j]);
            }
        }
    }

    int ans = arr[0][cap];

    for(int i = 0; i<=size;++i){
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main(){
    int n, w;
    cout << "Enter n" << endl;
    cin >> n;
    int *weight = new int[n];
    int *value = new int[n];

    cout << "Enter weights" << endl;
    for(int i =0; i<n;++i)
        cin >> weight[i];
    cout << "Enter values" << endl;
    for(int i = 0; i<n; ++i)
        cin >> value[i];
    cout << "Enter capacity" << endl;
    cin >> w;

    cout << bruteForce(weight,value,w,n) << endl;
    cout << memo(weight,value,w,n) << endl;
    cout << DP(weight,value,w,n) << endl;
    
    delete[] weight;
    delete[] value;

    return 0;
}
