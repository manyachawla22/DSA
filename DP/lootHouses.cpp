#include<iostream>
#include<algorithm>

using namespace std;

/*int bruteForce(int* money,int n, bool prev, int i){
    if(i>=n)
        return 0;

    int include = (prev == false) ? money[i] + bruteForce(money,n,true,i+1) : 0;
    int exclude = bruteForce(money,n,false,i+1);

    return max(include,exclude);
}

int maxLoot(int* money, int n){
    return bruteForce(money,n,false,0);
}*/

int helper(int* money,int n, bool prev, int i,int** arr){
    if(i>=n)
        return 0;

    if(arr[int(prev)][i] != -1)
        return arr[int(prev)][i];

    int include = (prev == false) ? money[i] + helper(money,n,true,i+1,arr) : 0;
    int exclude = helper(money,n,false,i+1,arr);

    arr[int(prev)][i] = max(include,exclude);
    return arr[int(prev)][i];
}

int memo(int* money, int n){
    
    int** arr = new int*[2];
    arr[0] = new int[n];
    arr[1] = new int[n];
    for(int i = 0; i<=n;++i){
        arr[0][i] = -1;
        arr[1][i] = -1;
    }

    int ans = helper(money,n,false,0,arr);
    
    /*cout << "Memo Map: " << endl;
    for(int i = 0; i<n;++i){
        cout << arr[0][i] << ' ';
    }
    cout << endl;
    for(int i = 0; i<n;++i)
        cout << arr[1][i] << ' ';
    cout << endl;*/

    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;

    return ans;
}

int DP(int* money, int n){
    int** arr = new int*[2];
    arr[0] = new int[n];
    arr[1] = new int[n];

    // 0 means included nth number, 1 means excluded nth number
    arr[0][n-1] = money[n-1];
    arr[1][n-1] = 0;
    for(int i = n-2; i>=0; --i){
        int exclude = arr[0][i+1];
        int include = money[i] + arr[1][i+1];
        arr[0][i] = max(exclude,include);
        arr[1][i] = exclude;
    }

    /*cout << "DP map:" << endl;
    for(int i = 0; i<n;++i){
        cout << arr[0][i] << ' ';
    }
    cout << endl;
    for(int i = 0; i<n;++i)
        cout << arr[1][i] << ' ';
    cout << endl;*/
    
    int ans = arr[0][0]; 
    
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;

    return ans;
}

int main() {
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    int* money = new int[n];
    cout << "Enter values" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> money[i];
    }

    //cout << maxLoot(money,n) << endl;
    cout << "DP:" << DP(money,n) << endl;
    cout << "Memo:" << memo(money,n) << endl;

    return 0;
}
