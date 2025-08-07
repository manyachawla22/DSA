#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  while ( n>0){
    int i = n%10;
    n/=10;
    if ( i==0)
      continue;
    else
      cout << i;
  }
}
