#include <iostream>
using namespace std;
void p1(int n)
{
    int i=1;
    int val=1;
    while (i<=n){
        int j=0;
        while (j<(n-i)){
            cout << " ";
            j+=1;
        }
        j=0;
        while (j<i){
            cout << val;
            val+=1;
            j+=1;
        }
        cout << endl;
        i+=1;
    }
}
void p2(int n)
{
    int i,j;
    // cout << "Enter n" << endl;
    for (i=1; i<=n; i++){
        for(j=0; j<(2*(n-i)) ;++j)
            cout << " ";
        for(j=i; j>0; --j)
            cout << j;
        for( j=2; j<=i; j++ )
            cout << j;
        cout << endl;
    }
}
void p3(int n)
{
    int i,j;
    //cout << "Enter n" << endl;
    //cin >> n;
    for (i=0; i<n; i++){
        for(j=0;j<(n-i-1);j++)
            cout << " ";
        for(j=0; j<(2*i+1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void p4(int n)
{
    int i, j;
    for ( i=0; i<n; i++){
             for (j=0; j<=i; j++){
                 cout << char('A' + n + j - i -1);
             }
             cout << endl;
         }
}
int main(){
    cout << "Enter n" << endl;
    int n;
    cin >> n;
    p1(n);
    cout << endl;
    p2(n);
    cout << endl;
    p3(n);
    cout << endl;
    p4(n);
    cout << endl;
}

