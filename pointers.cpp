#include<iostream>
using namespace std;
int main(){
    char c ='a';
    int a = 0;
    char *pc =&c;
    char ** pcc = &pc;
    
    int i=65;
    char d = i;
    int *p = &i;
    char *cp = (char*) p;

    cout << i << endl;
    cout << d << endl;
    cout << p << endl;
    cout << cp << endl;
    cout << *p << endl;
    cout << *cp << endl;

    cout << endl << *(pc+1) << endl;


    /*cout << c << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(pc) << endl;
    cout << p << endl;
    cout << pc << endl << endl;
    cout << pcc << endl;
    cout << *pcc << endl;
    cout << **pcc << endl << endl;
    cout << ++(*p) << endl;
    cout << ++(*pc) << endl;
    */
}
