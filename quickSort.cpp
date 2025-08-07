#include <iostream>
#include <vector>
using namespace std;


void inputVector( vector<int>& v);
void outputVector( vector<int>& v);

int partition( vector<int> &vec, int start, int end ){
    
    int count = 0; 
    for( int i = start+1; i<=end; ++i ){
        if( vec[i] < vec[start] )
            ++count;
    }
    int index = count+start;
    
    int temp = vec[start];
    vec[start] = vec[index];
    vec[index] = temp;

    for( int i = start, j =end; (i<index) && (j>index);  ){
        if( vec[i] < vec[index])
            ++i;
        else if( vec[j] >= vec[index] ) 
            --j;
        else{
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    return index;
}

void quickSort( vector<int> &vec, int start, int end ){
    if( start >= end )
        return;
    int c = partition( vec, start, end );
    quickSort( vec, start, c-1 );
    quickSort( vec, c+1, end );
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    inputVector(vec);
    quickSort(vec, 0, n-1);
    outputVector(vec);
    return 0;
}

