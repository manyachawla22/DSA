#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//longest increasing subsequence

/*int bruteForce(int* list,int n, int prev, int i){
    if(i>=n)
        return 0;

    int include = (prev < list[i]) ? 1 + bruteForce(list,n,list[i],i+1) : 0;
    int exclude = bruteForce(list,n,prev,i+1);

    return max(include,exclude);
}

int lis(int* money, int n){
    return bruteForce(money,n,INT_MIN,0);
}

int helper(int* list,int n, int prev, int i,int** arr){
    if(i>=n)
        return 0;
    if(arr[i][prev] != -1)
        return arr[i][prev];

    int include = (prev < list[i]) ? 1 + helper(list,n,list[i],i+1,arr) : 0;
    int exclude = helper(list,n,prev,i+1,arr);

    arr[i][prev] =  max(include,exclude);
    return arr[i][prev];
}

int ListMax(int* list, int n){
    int ans = 0;
    for(int i = 0; i<n;++i){
        if(list[i] > ans)
            ans = list[i];
    }
    return ans;
}
int memo(int* list, int n){

    int maximum = ListMax(list,n); 
    int** arr = new int*[n];
    for(int i =0; i<n;++i){
        arr[i] = new int[maximum+1];
    }
    for(int i = 0; i<n;++i){
        for(int j = 0; j<=maximum;++j)
            arr[i][j] = -1;
    }

    int ans = helper(list,n,0,0,arr); 
    
    for(int i =0;i<n;++i){
        delete[] arr[i];
    }
    delete[] arr;

    return ans;
}
//asumption: only positive numbers in list

int DP(int* list, int n){
    int maximum = ListMax(list,n); 
    int** arr = new int*[n];
    for(int i =0; i<n;++i){
        arr[i] = new int[maximum+1];
    }

    for(int j = maximum; j>=0; --j){
        if(j<list[n-1]){
            arr[n-1][j] = 1;
        }
        else
            arr[n-1][j] = 0;
    }
    for(int i = n-2; i>=0; --i){
        for(int j = maximum; j>=0;--j){
            int include = (j < list[i]) ? 1+arr[i+1][list[i]] : 0;
            int exclude = arr[i+1][j];

            arr[i][j] = max(include,exclude);
        }
    }
    
    int ans = arr[0][0]; 
    
    for(int i =0;i<n;++i){
        delete[] arr[i];
    }
    delete[] arr;

    return ans;
}
*/

//most optimal solution: using O(n2):
int DP(int* list, int n){
    int* arr= new int[n];

    arr[0] = 1;
    for(int i = 1; i<n;++i){
        arr[i] = 1;
        for(int j = i-1; j>=0;--j){
            if(list[j]  >= list[i])
                continue;
            int possibleAns = arr[j] + 1;
            if(possibleAns > arr[i])
                arr[i] = possibleAns;
        }
    }
    int best = 0;
    for(int i =0; i<n;++i){
        if(best < arr[i])
            best = arr[i];
    }
    return best;
}


int main() {
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    int* list = new int[n];
    cout << "Enter values" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    //cout << lis(list,n) << endl;
    cout << "DP:" << DP(list,n) << endl;
    //cout << "Memo:" << memo(list,n) << endl;

    return 0;
}
