/*Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
*/

#include<iostream>
#include<vector>

using namespace std;

bool hasPathHelper(const vector<vector<char>>& board,const int n,const int m, vector<vector<bool>>& visited,const int i,const int j,const string& str,const int index){
    if(index == str.size())
        return true;

    visited[i][j] = true;

    int dx[] = {1,-1,0,0,1,1,-1,-1};
    int dy[] = {0,0,1,-1,1,-1,1,-1};

    for(int d = 0; d < 8; ++d){
        int ni = i + dx[d];
        int nj = j + dy[d];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && board[ni][nj] == str[index]){
            if(hasPathHelper(board, n, m, visited, ni, nj, str, index + 1))
                return true;
        }
    }

    visited[i][j] = false;
    return false;
}


bool hasPath(vector<vector<char>> &board, int n, int m){
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    string str = "CODINGNINJA";
    for(int i = 0; i<n;++i){
        for(int j = 0; j<m;++j){
            if(board[i][j] == 'C'){
                bool ans = hasPathHelper(board,n,m,visited,i,j,str,1);
                if(ans)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0) << endl;
}
