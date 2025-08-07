#include<iostream>
#include<vector>

using namespace std;


#include<climits>
int helper(int n, int *arr){
	if(arr[n] != -1 )
		return arr[n];
	int min = INT_MAX;
	for(int i = 1; (i*i)<=n; ++i){
		int temp = helper(n-(i*i),arr);
		if(temp<min)
			min = temp;
	}
	arr[n] = min+1;
	return min + 1;
}

int helperDP(int n){
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1]=1;
	for(int i = 2; i<=n; ++i){
		arr[i] = INT_MAX;
		for(int j =1; i-(j*j)>=0; ++j){
			arr[i] = min(arr[i], helperDP(i-(j*j)));
		}
		arr[i]+=1;
	}
    int soln = arr[n];
    delete [] arr;
	return soln;
}

int minCount(int n)
{
	return helperDP(n);
	/*int *arr = new int[n+1];
	arr[0]=0, arr[1]=1;
	for(int i = 2; i<=n; ++i)
		arr[i] = -1;
	return helper(n,arr);*/
}

int main(){
    int n;
    cin >> n;
    cout << minCount(n) << endl;
    return 0;
}
