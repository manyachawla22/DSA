#include<iostream>
#include<vector>
#include"BST.h"

using namespace std;

int main(){
    BST bst;
    bst.insert(2);
    bst.insert(3);
    bst.insert(1);
    bst.print();
    cout << bst.hasData(2) << endl;
    bst.print();
    cout << "Test ended" << endl;
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    /*bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(5);
    bst.insert(10);*/
    // cout << bst.hasData(5) << endl;
    bst.print();
    cout << endl << "Enter the number you want to delete" << endl;
    int x;
    cin >> x;
    bst.del(x);
    bst.print();
    return 0;
}
