#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>>*board){
    cout << endl;
    for(const auto& row : *board){
        for(int val:row){
            cout << val << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

pair<int,int> nextEmpty(vector<vector<int>>* board){
    for(int i = 0; i<9;++i){
        for(int j = 0; j<9; ++j){
            if((*board)[i][j] == 0){
                pair<int,int> ans = make_pair(i,j);
                return ans;
            }
        }
    }
    pair<int,int> ans = make_pair(-1,-1);
    return ans;
}
bool canPlace(vector<vector<int>>*board, int row, int colm, int val){
    for(int i = 0; i<9; ++i){
        if((*board)[i][colm] == val)
            return false;
    }
    for(int i = 0; i<9; ++i){
        if((*board)[row][i] == val)
            return false;
    }
    int boxR = (row/3)*3;
    int boxC = (colm/3)*3;
    for(int i = boxR; i<boxR+3;++i){
        for(int j = boxC; j<boxC+3;++j){
            if((*board)[i][j] == val)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>* board){
    pair<int,int> empty = nextEmpty(board);
    if(empty.first == -1){
        print(board);
        return true;
    }
    int row = empty.first;
    int colm = empty.second;
    for(int i = 1; i<=9; ++i){
        bool check = canPlace(board,row,colm,i);
        if(check){
            (*board)[row][colm] = i;
            bool ans = solve(board);
            if(ans)
                return true;
            (*board)[row][colm] = 0;
        }
    }
    return false;
}

int main() {
	vector<vector<int>> board(9,vector<int>(9,0));
	for(int i=0; i<9;++i){
		for(int j=0;j<9;++j){
			int c;
			cin >> c;
			board[i][j] = c;
		}
	}
	bool ans = solve(&board);
    if(ans == true){
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
	return 0;
}
