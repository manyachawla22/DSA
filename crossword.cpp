//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class returnNextPlace{
    public:
    int startX;
    int startY;
    char dir;
    int len;
    returnNextPlace(int sx, int sy, char d, int l): startX(sx), startY(sy), dir(d), len(l){}
};

returnNextPlace nextPlace(vector<vector<char>>* grid){
    int x,y,len;
    x=y=len=-1;
    char dir = 'X';
    for(int i=0; i<10;++i){
        for(int j = 0; j<10; ++j){
            if((*grid)[i][j] == '-'){
                int count = 0;
                if(i-1<0 || (*grid)[i-1][j] =='+' )
                    ++count;
                if(i+1>=10 || (*grid)[i+1][j] =='+' )
                    ++count;
                else
                    dir = 'D';
                if(j-1<0 || (*grid)[i][j-1] =='+' )
                    ++count;
                if(j+1>=10 || (*grid)[i][j+1] =='+' )
                    ++count;
                else
                    dir = 'R';
                if(count >= 3){
                    x = i;
                    y=j;
                    break;
                }
            }
        }
        if(x!=-1)
            break;
    }
    if(dir == 'R'){
        len = 1;
        for(int i = x, j = y; (*grid)[i][j] != '+'; ++j,++len);
    }
    else if( dir == 'D'){
        len = 1;
        for(int i = x, j = y; (*grid)[i][j] != '+'; ++x,++len);
    }
    returnNextPlace ans(x,y,dir,len);
    return ans;
}

bool crossword(vector<vector<char>>* grid, vector<string>* words){
    //swap the used word on top, and pass the rest of the vector
    returnNextPlace next = nextPlace(grid);
    if(next.startX == -1)
        return true;
    
    for( auto& str:(*words)){
        if(str.size() == next.len){
            int x = next.startX;
            int y = next.startY;
            if(next.dir == 'R'){
                for(int i = 0; i<next.len;++i){
                    (*grid)[x][y] = str[i];
                    ++y;
                }
            }
            else{
                for(int i = 0; i<next.len;++i){
                    (*grid)[x][y] = str[i];
                    ++x;
                }
            }
            string& firstElement = (*words).front(); 
            swap(firstElement, str);
            vector<string>* tempWords = new vector<string>(words->begin() + 1, words->end());
            bool ans = crossword(grid,tempWords);
            if(ans)
                return true;
        }
    }
    return false;
}

int main(){
    vector<vector<char>> grid (10,vector<char>(10));
    for(int i =0; i<10;++i){
        for(int j = 0; j<10;++j){
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }
    cin.ignore(); // for clearing new line in buffer
    string input;
    getline(cin,input);
    string x="";
    vector<string> words;
    for(char c: input){
        if(c==';'){
            words.push_back(x);
            x ="";
        }
        else{
           x+=c; 
        }
    }
    words.push_back(x);
    /*for(int i = 0; i<x.size();++i){
        cout << words[i] << endl;
    }*/
    crossword(&grid,&words);
    for(int i =0; i<10;++i){
        for(int j = 0; j<10;++j){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}

