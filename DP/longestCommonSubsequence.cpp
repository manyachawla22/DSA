#include<iostream>
#include<string>
#include<climits>

using namespace std;

//subsequence - can be discontinous but order should remain, return the longest possible subsequence!

int bruteForce(const string &s,const string &t){
    if(s.length()==0 || t.length()==0)
        return 0;
    if(s[0] == t[0])
        return bruteForce(s.substr(1),t.substr(1)) + 1;
    int first = bruteForce(s.substr(1),t);
    int second = bruteForce(s,t.substr(1));
    int none = bruteForce(s.substr(1),t.substr(1));

    return max(first,max(second,none));
}

int memoHelper(const string &s,const string &t, int** arr, int x, int y, int sizeS, int sizeT){
    if(x >= sizeS || y>= sizeT)
        return 0;
    if(arr[x][y] != -1)
        return arr[x][y];
    if(s[x] == t[y]){
        arr[x][y] = memoHelper(s,t,arr,x+1,y+1,sizeS, sizeT) + 1;
        return arr[x][y];
    }

    int first = memoHelper(s,t,arr,x+1,y,sizeS, sizeT);
    int second = memoHelper(s,t,arr,x,y+1,sizeS, sizeT);
    int none = memoHelper(s,t,arr,x+1,y+1,sizeS, sizeT);

    arr[x][y] = max(first,max(second,none));
    return arr[x][y];
}

int memo(const string&s, const string &t){
    int sizeS = s.length();
    int sizeT = t.length();
    int** arr = new int*[sizeS];
    for(int i =0; i<sizeS;++i)
        arr[i] = new int[sizeT];
    for(int i = 0; i<sizeS;++i){
        for(int j = 0; j<sizeT; ++j)
            arr[i][j] = -1;
    }
    int ans =  memoHelper(s,t,arr,0,0,sizeS, sizeT);
    for(int i =0; i<sizeS;++i)
        delete [] arr[i];
    delete[] arr;
    return ans;
}


int DP(const string& s, const string &t){
    int sizeS = s.length()-1;
    int sizeT = t.length()-1;
    
    if(sizeS < 0 || sizeT < 0)
        return 0;
    
    int** arr = new int*[sizeS+1];
    for(int i =0; i<=sizeS;++i)
        arr[i] = new int[sizeT+1];
    
    if(s[sizeS] == t[sizeT] )
        arr[sizeS][sizeT] = 1;
    else
        arr[sizeS][sizeT] = 0;
    
    // fill last row
    for(int i = sizeT-1; i>=0;--i){
        if(arr[sizeS][sizeT] == 0 && t[i]==s[sizeS] && arr[sizeS][i+1] != 1){
            arr[sizeS][i] = arr[sizeS][i+1] + 1;
        }
        else
            arr[sizeS][i] = arr[sizeS][i+1];
        
    }
    
    // fill last colm
    for(int i = sizeS-1; i>=0; --i){
        if(arr[sizeS][sizeT] == 0 && s[i] == t[sizeT] && arr[i+1][sizeT] != 1)
            arr[i][sizeT] = arr[i+1][sizeT] + 1;
        else
            arr[i][sizeT] = arr[i+1][sizeT];
    }
    
    // fill other places row wise from bottom to top
    for(int i = sizeS-1; i>=0;--i){
        for(int j = sizeT-1; j>=0; --j){
            int right = (j+1<=sizeT) ? arr[i][j+1] : INT_MIN;
            int bottom = (i+1<=sizeS) ? arr[i+1][j] : INT_MIN;
            int diagonal = (j+1<=sizeT && i+1<=sizeS) ? arr[i+1][j+1] : INT_MIN;

            int maximum = max(right,max(bottom,diagonal));
            if(s[i] == t[j] && maximum == diagonal){
                arr[i][j] = maximum +1;
            }
            else
                arr[i][j] = maximum;
        }
    }
    
    cout << "The matrix:" << endl;
    for(int i = 0; i<=sizeS; ++i){
        for(int j = 0; j<=sizeT; ++j)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    int ans = arr[0][0];
    for(int i =0; i<=sizeS;++i)
        delete [] arr[i];
    delete[] arr;
    return ans;
}

int main(){
    string s,t;
    cout<< "Enter s" << endl;
    cin >> s;
    cout << "Enter t" << endl;
    cin >> t;
    //cout << s << endl;
    //cout << t << endl;
    //cout << "LCS : " << DP(s,t) << endl;
    cout << "LCS : " << DP(s,t) << endl;
    cout << "LCS : " << memo(s,t) << endl;
    cout << "LCS : " << bruteForce(s,t) << endl;
    return 0;

}
