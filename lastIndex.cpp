int lastIndex(int input[], int size, int x) {
  if( size == 0)
    return -1;
  if ( input[size-1] == x )
    return size -1;
  
  int index = lastIndex( input, size -1, x);

  if( index == -1)
    return -1;
  else
    return index;
}


#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << lastIndex(input, n, x) << endl;

}



