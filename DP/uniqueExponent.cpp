#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int bruteForce(int a,int b,int i){
    int exp = int(pow(i,b));
    if(exp>a)
        return 0;
    if(exp == a)
        return 1;

    int include = bruteForce(a-exp,b,i+1);
    int exclude = bruteForce(a,b,i+1);

    return include+exclude;
}

int bruteForce(int a, int b){
    return bruteForce(a,b,1);
}

/*int helper(int* list,int n, int prev, int i,int** arr){
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
}*/
//asumption: only positive numbers in list

int DP(int a, int b){
    int largestX = int(pow(a,1.0/b)); 
    int** arr = new int*[a+1];
    for(int i =0; i<=a;++i){
        arr[i] = new int[largestX+1];
    }

    for(int i = 0; i<=a; ++i){
        for(int j = largestX; j>=0;--j){
            int exp = int(pow(j,b));
            if(exp>i){
                arr[i][j] = 0;
                continue;
            }
            if(exp == i){
                arr[i][j] = 1;
                continue;
            }
            int include = arr[i-exp][j+1];
            int exclude = arr[i][j+1];

            arr[i][j] = include+exclude;
        }
    }
    
    int ans = arr[a][1]; 
    
    for(int i =0;i<=a;++i){
        delete[] arr[i];
    }
    delete[] arr;

    return ans;
}


int main() {
    int a,b;
    cout << "Enter a and b" << endl;
    cin >> a >> b ;

    cout << bruteForce(a,b) << endl;
    cout << "DP:" << DP(a,b) << endl;

    return 0;
}
