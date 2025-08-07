#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;
  int result=0;
  cin >> n;
  for ( int j=0; n>0; ++j){
    int i = n%10;
    n/=10;
    i*= pow( 2,j);
    result+=i;
  }
  cout << result << endl;
}
