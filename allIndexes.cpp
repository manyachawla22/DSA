/*int allIndexes(int input[], int size, int x, int output[]) {
    if( size == 0 )
        return 0;

    int result = allIndexes( input, size-1, x, output);

    if ( input[size -1] == x){
        output[result] = size -1;
        return result+1;
    }
    else 
        return result;
}*/

int allIndexes(int input[], int size, int x, int output[], int index) {
  if( size == 0)
    return 0;
  if (input[0] == x) {
    output[0] = index;
    return 1+allIndexes(input+1, size-1, x, output+1, index+1);
    
  }
  else
    return allIndexes(input+1, size-1,  x, output, index+1);
}
int allIndexesRecursive(int input[], int size, int x, int output[]) {
  return allIndexes(input, size,  x, output, 0);
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
    
    int *output = new int[n];
    
    int size = allIndexesRecursive(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}
