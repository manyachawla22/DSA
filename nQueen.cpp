#include<iostream>
#include<vector>

using namespace std;

class nQueen{
    public:
    vector<vector<int>> board;
    int n;
    int count;
    nQueen(int n):n(n){
        board = vector<vector<int>>(n,vector<int>(n,0));
        count =0;
    }
    
    void print() {
        for (const auto& row : board) {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
        cout << endl;
        count ++;
    }

    bool canPlace(int row,int colm){
        /*for(int i =0; i<n;++i){
            if(board[row][i] == 1)
                return false;
        }*/
        for(int i =0; i<n;++i){
            if(board[i][colm] == 1)
                return false;
        }
        for(int i =row, j = colm; i>=0 && j>=0;--i,--j){
            if(board[i][j] == 1)
                return false;
        }
        /*for(int i =row, j = colm; i<n && j<n; ++i,++j){
            if(board[i][j] == 1)
                return false;
        }*/
        for(int i = row, j = colm; i>=0 && j<n; --i,++j){
            if(board[i][j] == 1)
                return false;
        }
        /*for(int i = row, j = colm; i<n && j>=0; ++i,--j){
            if(board[i][j] == 1)
                return false;
        }*/
        return true;
    }

    void solution(int row, vector<vector<int>>* ans){
        if(row==n){
            vector<int> soln;
            for(int i =0; i<n;++i){
                for(int j=0; j<n;++j){
                    soln.push_back(board[i][j]);
                }
            }
            (*ans).push_back(soln);
            //print();
            return;
        }
        for(int j =0; j<n;++j){
            if(canPlace(row,j)){
                board[row][j] = 1;
                solution(row+1,ans);
                board[row][j] = 0; 
            }
        }
        return;
    }
    vector<vector<int>> nQueens(){
        vector<vector<int>> ans;
        if(n ==2 || n ==3)
            return ans;
        solution(0,&ans);
        return ans;
    }
};

int main(){
    class nQueen obj(4);
    vector<vector<int>> ans = obj.nQueens();
    for (const auto& row : ans) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
    //cout << obj.count << endl;
    return 0;
}
