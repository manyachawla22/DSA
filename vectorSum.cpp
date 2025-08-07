#include <iostream>
#include <vector>
using namespace std;

void input2DVector( vector<vector<int>>& v, int rows, int colms );
void output2DVector( vector<vector<int>>& v, int rows, int colms );

int diagonalSum( vector<vector<int>>& v, int n ){
    int result=0;
    for( int i =0; i < n; ++i )
            result += v[i][i];
    for( int i = 0; i<n; ++i  )
            result += v[i][n-1-i];
    if( n%2 == 0 )
        return result;
    else
        return result - v[n/2][n/2];
}

int boundarySum( vector<vector<int>>& arr, int n ){
    int sum = diagonalSum( arr, n );
    for( int i =1; i< n-1; ++i ){
        sum += arr[0][i];
        sum += arr[n-1][i];
        sum += arr[i][0];
        sum += arr[i][n-1];
    }
    return sum;
}

int main(){
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    input2DVector(arr,n,n);
    int sum = boundarySum( arr, n );
    cout << sum << endl;
    output2DVector( arr, n ,n );
    return 0;
}
