#include <iostream>
#include<vector>
using namespace std;

/* Few functions that can be used:
 * v.pop_back()
 * v.push_back()
 * v.empty()
 * v.clear()
 * reverse(v.begin(), v.end())
 * v.at()
 * v.front()
 * v.back()
 * v.erase()
 * sort( v.begin(), v.end() )  or sort( v.begin(), v.end(), greater<>() )          */


void inputVector( vector<int>& v){
    for( int i =0; i<v.size(); ++i )
        cin >> v[i];
}

void outputVector( vector<int>& v ){
    for( int i=0; i<v.size(); ++i )
        cout << v[i] << " ";
    cout << endl;
}

void input2DVector( vector<vector<int> > & arr, int rows, int colms ){
     for( int i =0; i<rows; ++i ){
         for( int j = 0; j<colms; ++j )
             cin >> arr[i][j];
     }
 }

void output2DVector( vector<vector<int> > & arr, int rows, int colms ){
    for( int i =0; i<rows; ++i ){
        for( int j =0; j<colms; ++j )
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
    /*
int main(){
    vector<int> v(5);
    v.at(0)=25;
    inputVector(v);
    v.erase( v.begin() + 3 );
    outputVector(v);
    v.pop_back();
    inputVector(v);
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    outputVector(v);
    cout << v.empty() << endl;
    return 0;
}
*/
