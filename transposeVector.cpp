#include <iostream>
#include <vector>
using namespace std;

void input2DVector( vector<vector<int>>& v, int rows, int colms );
void output2DVector( vector<vector<int>>& v, int rows, int colms );

vector<vector<int>> transpose( int rows, int colms, vector<vector<int>>& arr ){
    vector<vector<int>> vec( colms, vector<int>(rows) );
    for( int i =0; i<rows; ++i)
        for(int j =0; j<colms; ++j)
            vec[j][i] = arr[i][j];
    return vec;
}

int main(){
    int rows, colms;
    cout << "Enter rows and colms" << endl;
    cin >> rows >> colms;
    vector<vector<int>> arr(rows, vector<int>(colms));
    input2DVector(arr,rows,colms);
    vector<vector<int>> vec = transpose( rows, colms, arr );
    output2DVector( vec, colms ,rows );
    return 0;
}
