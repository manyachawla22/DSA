/*
it's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
*/

#include<iostream>
#include<vector>

using namespace std;

int helper(const vector<vector<int>>& board,const int n, vector<vector<bool>>& visited,const int i,const int j){
    if(visited[i][j])
        return 0;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    
    visited[i][j] = true;
    int count = 1;
    for(int d = 0; d < 4; ++d){
        int ni = i + dx[d];
        int nj = j + dy[d];
        if(ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == 1){
            count += helper(board, n, visited, ni, nj);
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &board, int n){
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int max = 0;
    for(int i = 0; i<n;++i){
        for(int j = 0; j<n;++j){
            if(board[i][j] == 1 && !visited[i][j]){
                int ans = helper(board,n,visited,i,j);
                if(ans > max)
                    max = ans;
            }
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            cin >> board[i][j];
    }

    cout << getBiggestPieceSize(board, n) << endl;
}
