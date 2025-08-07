//read grid once and fetch info about blanks in a list:
// len, dir,start point, intersections
// map the list to list of words
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class blank{
    public:
        int startX;
        int startY;
        int len;
        char dir;
        vector<int> intersection;
        bool isFilled;

        blank(int x,int y, int l, char d, vector<int> i, bool filled = false): startX(x), startY(y), len(l), dir(d), intersection(i), isFilled(filled){}
};

bool checkStart(int x, int y, vector<vector<char>>* grid){
    if((*grid)[x][y] == '+')
        return false;
    if(x-1>=0 && (*grid)[x-1][y] == '-')
        return false;
    if(y-1>=0 && (*grid)[x][y-1] == '-')
        return false;
    return true;
}

pair<bool,bool> direction(int x, int y, vector<vector<char>>* grid){
    bool right,down;
    right = down = false;
    if( y+1<10 && (*grid)[x][y+1] == '-')
        right = true;
    if( x+1<10 && (*grid)[x+1][y] == '-')
        down = true;
    return make_pair(right,down);
}

bool checkIntersection(int x, int y, vector<vector<char>>* grid, char dir){ // update the dir part 
    if(dir == 'R'){
        if(x+1<10 && (*grid)[x+1][y] == '-')
            return true;
        if(x-1>=0 && (*grid)[x-1][y] == '-')
            return true;
    }
    else{
        if(y+1<10 && (*grid)[x][y+1] == '-')
            return true;
        if(y-1>=0 && (*grid)[x][y-1] == '-')
            return true;
    }
    return false;
}


vector<blank> readGrid(vector<vector<char>>* grid){
    vector<blank> blankList;
    for(int i =0; i<10;++i){
        for(int j = 0; j<10; ++j){
            if(checkStart(i,j,grid)){
                pair<bool,bool> dir = direction(i,j,grid);
                if(dir.first == true){
                    int count = 0;
                    vector<int> intersect;
                    for(int index = 0; j+index<10 && (*grid)[i][j+index] == '-';++index,++count){
                        if(checkIntersection(i,j+index,grid,'R'))
                            intersect.push_back(index);
                    }
                    blank obj(i,j,count,'R',intersect);
                    blankList.push_back(obj);
                }
                if(dir.second == true){
                    int count = 0;
                    vector<int> intersect;
                    for(int index = 0; i+index<10 && (*grid)[i+index][j] == '-';++index,++count){
                        if(checkIntersection(i+index,j,grid,'D'))
                            intersect.push_back(index);
                    }
                    blank obj(i,j,count,'D',intersect);
                    blankList.push_back(obj);
                }
            }
        }
    }
    sort(blankList.begin(), blankList.end(), [](const blank &a, const blank &b) {
        return a.len < b.len;
        });
    return blankList;
}

bool canPlace(string word, vector<vector<char>>*grid, blank b){ // this checks intersection and len if a word can be placed or not 
    if(word.size() != b.len)
        return false;
    for(int i = 0; i<b.intersection.size(); ++i){
        int x,y;
        if(b.dir == 'R'){
            x = b.startX;
            y = b.startY+b.intersection[i];
        }
        else{
            x = b.startX + b.intersection[i];
            y = b.startY;
        }
        if( (*grid)[x][y] != '-' && word[i] != (*grid)[x][y])
            return false;
    }
    return true;
}

bool helperCrossword(vector<blank>* gridData, vector<string>* words, vector<vector<char>>* grid, int emptyBlanks){
    if(emptyBlanks == 0)
        return true;


}



void placeWord( string word, vector<vector<char>>* grid, blank b){
    int x = b.startX;
    int y = b.startY;
    for(int i = 0; i<word.size();++i){
        (*grid)[x][y] = word[i];
        if(b.dir == 'R')
            ++y;
        else
            ++x;
    }
    b.isFilled = true;
}

void crossword(vector<vector<char>>* grid, vector<string>* words){
    vector<blank> gridData = readGrid(grid);
    sort((*words).begin(), (*words).end(), [](const string &a,const string &b ){
            return a.size() < b.size();
            }); // here [] indicates a lambda function-> function to define on what basis to sort
    for(int i =0; i<(*words).size();++i){
        if((i+1<(*words).size() && (*words)[i].size() == (*words)[i+1].size()) || (i-1>=0 && (*words)[i].size() == (*words)[i-1].size()))
            continue;
        else{
            placeWord((*words)[i], grid, gridData[i]);
            gridData.erase(gridData.begin() + i);
            (*words).erase((*words).begin() + i);
            --i;
            /*for(int j = i; j<gridData.size(); ++j){//can remove the for loop, check it!!! IMPORTANT!! by erasing blanks, it might be a problem;
                if((*words)[i].length() != gridData[j].len)
                    continue;
                else{
                    placeWord((*words)[i], grid, gridData[j]);
                    gridData.erase(gridData.begin() + j);
                    (*words).erase((*words).begin() + i);
                    --i;
                    break;
                }
            }*/
        }
    }
    helperCrossword(&gridData, words,grid,gridData.size());
    return;
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

