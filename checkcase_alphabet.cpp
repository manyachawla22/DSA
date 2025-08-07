#include <iostream>
using namespace std;
int main()
{
    char b;
    cout << "Enter the alphabet\n";
    cin >> b;
    int a=b;
    if (a>=65 && a<=90)
        cout << "1:The entered char is an uppercase alphabet\n";
    else if (a>=97 && a<=122)
        cout << "0:The entered char is a lowercase alphabet\n";
    else 
        cout << "-1:The entered char is not an alphabet\n";
    return 0;
}
