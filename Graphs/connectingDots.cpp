#include<iostream>
#include<vector>

using namespace std;

/*Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
*/

bool hasCycleHelper(const vector<vector<char>>& board,const int n,const int m, vector<vector<bool>>& visited,const int i,const int j,const char color,const int len, const int sx, const int sy){
    int dx[] = {1,-1,0,0,};
    int dy[] = {0,0,1,-1,};
    
    if(len >= 4){
        for(int d = 0; d<4;++d){
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && ni == sx && nj == sy)
                return true;
        }
    }

    visited[i][j] = true;

    for(int d = 0; d < 4; ++d){
        int ni = i + dx[d];
        int nj = j + dy[d];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && board[ni][nj] == color){
            if(hasCycleHelper(board, n, m, visited, ni, nj, color, len + 1,sx,sy))
                return true;
        }
    }

    visited[i][j] = false;
    return false;
}


bool hasCycle(vector<vector<char>> &board, int n, int m){
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i = 0; i<n;++i){
        for(int j = 0; j<m;++j){
            bool ans = hasCycleHelper(board,n,m,visited,i,j,board[i][j],1,i,j);
            if(ans)
                return true;
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

    cout << (hasCycle(board, n, m) ? 1 : 0) << endl;
}

