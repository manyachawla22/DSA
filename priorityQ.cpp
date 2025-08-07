#include"priorityQueue.h"
int main(){
    MaxPriorityQueue p1;
    cout << p1.isEmpty() << endl;
    p1.insert(5);
    p1.insert(2);
    p1.insert(10);
    p1.insert(15);
    p1.insert(7);
    p1.insert(12);
    p1.insert(20);
    p1.insert(1);
    p1.insert(3);
    p1.insert(8);

    //p1.remove();
    //p1.remove();

    cout << p1.getSize() << endl;
    p1.print();
}
