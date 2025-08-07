/*
 * An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
*/

#include<climits>
#include<iostream>
using namespace std;
int helper(int** input, int m, int n, int x , int y){
	if(x==m-1 && y == n-1)
		return input[x][y];
	int right = (y+1<n) ? helper(input, m,n,x,y+1) : INT_MAX;
	int bottom = (x+1<m) ? helper(input, m,n,x+1,y) : INT_MAX;
	int diagonal = (y+1<n && x+1<m) ? helper(input, m,n,x+1,y+1) : INT_MAX;

	return min(right,min(bottom,diagonal)) + input[x][y];
}

int minCostPath(int **input, int m, int n)
{
	//return helper(input, m, n, 0,0);
	int **cost = new int*[m];
	for(int i = 0; i<m; ++i)
		cost[i] = new int[n];

	cost[0][0] = input[0][0];
	for(int x = 0; x<m; ++x ){
		for(int y = 0; y<n;++y){
			if(x==0 && y==0)
				continue;
			int left = (y-1>=0) ? cost[x][y-1] : INT_MAX;
			int up = (x-1>=0) ? cost[x-1][y] : INT_MAX;
			int diagonal = (y-1>=0 && x-1>=0) ? cost[x-1][y-1] : INT_MAX;
			cost[x][y] = min(left,min(up,diagonal)) + input[x][y];
		}
	}

	int ans = cost[m-1][n-1];

	for(int i = 0; i<m; ++i)
		delete [] cost[i] ;
	delete [] cost;
	return ans;
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
    cout << helper(arr,n,m,0,0) << endl;
}
