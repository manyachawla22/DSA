#include<iostream>
#include<string>

using namespace std;


int bruteForce(const string &s, const string &t){
    int sizeS = s.length();
    int sizeT = t.length();
    if( sizeS == 0 || sizeT == 0)
        return max(sizeS,sizeT);
    if(s[0] == t[0]){
        return bruteForce(s.substr(1), t.substr(1));
    }
    else{
        int replace = bruteForce(s.substr(1),t.substr(1)) + 1;
        int insert = bruteForce(s,t.substr(1)) + 1;
        int del = bruteForce(s.substr(1),t) + 1;

        return min(replace,min(insert,del));
    }
}


int memo(const string &s, const string &t, int**arr){
    int sizeS = s.length();
    int sizeT = t.length();
    if(sizeT <= 0 || sizeS <= 0)
        return max(sizeS,sizeT);

    if(arr[sizeS][sizeT] != -1)
        return arr[sizeS][sizeT];

    if(s[0] == t[0]){
        arr[sizeS][sizeT] = memo(s.substr(1),t.substr(1),arr);
        return arr[sizeS][sizeT];
    }
    else{
        int replace = memo(s.substr(1),t.substr(1),arr) + 1;
        int del = memo(s,t.substr(1),arr) + 1;
        int insert = memo(s.substr(1),t,arr) + 1;

        int minimum = min(replace,min(insert,del));
        arr[sizeS][sizeT] = minimum;
        return arr[sizeS][sizeT];
    }
}

int memo(const string s, const string t){
    int sizeS = s.length();
    int sizeT = t.length();

    int** arr = new int*[sizeS+1];
    for(int i = 0; i<=sizeS;++i)
        arr[i] = new int[sizeT+1];
    
    for(int i =0; i<=sizeS;++i){
        for(int j = 0; j<=sizeT;++j)
            arr[i][j] = -1;
    }
    
    int ans = memo(s,t,arr);
    
    /*cout << endl;
    cout << "sizeS:" << sizeS << endl;
    cout << "sizeT:" << sizeT << endl;
    for(int i =0; i<=sizeS;++i){
        for(int j = 0; j<=sizeT;++j)
            cout << arr[i][j] << ' ';
        cout << endl;
    }*/

    for(int i =0; i<=sizeS;++i)
        delete [] arr[i];
    delete [] arr;
    return ans;
}

int DP(const string&s, const string &t){
    int sizeS = s.length();
    int sizeT = t.length();
    
    int **arr = new int*[sizeS+1];
    for(int i = 0; i<=sizeS; ++i)
        arr[i] = new int[sizeT+1];

    for(int i = 0; i<=sizeS; ++i){
        for(int j = 0; j<=sizeT; ++j){
            int left = (j-1>=0) ? arr[i][j-1] : INT_MAX;
            int right = (i-1>=0) ? arr[i-1][j] : INT_MAX;
            int diagonal = (j-1>=0 && i-1>=0)? arr[i-1][j-1] : INT_MAX;
            if(s[i] == t[j])
               arr[i][j] = min(left,min(right,diagonal));
            else
                arr[i][j] = min(left,min(right,diagonal)) + 1;
        }
    }
    
    int ans = arr[sizeS][sizeT];
    for(int i =0; i<=sizeS; ++i)
        delete[] arr[i];
    delete[] arr;
    
    return ans;
}

int main(){
    string s,t;
    cout<< "Enter s" << endl;
    cin >> s;
    cout << "Enter t" << endl;
    cin >> t;
    
    cout << "Using DP : " << DP(s,t) << endl;
    cout << "Using memo :" << memo(s,t) << endl;
    cout << "Using reccursion :" << bruteForce(s,t) << endl;
    
    return 0;

}
