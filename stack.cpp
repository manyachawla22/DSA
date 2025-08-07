#include<iostream>
#include<vector>

using namespace std;

class StackArr{
    private:
        int *data;
        int next;
        int capacity;
    public:
        StackArr(int size)
            : next(0), capacity(size)
        {
            data = new int[size];
        }
        ~StackArr(){
            delete[] data;
        }
        void push(int i){
            if(next >= capacity){
                cout << "Capacity Full" << endl;
                return;
            }
            data[next] = i;
            ++next;
        }
        int pop(){
            if(next == 0){
                cout << "Stack Empty" << endl;
                return INT_MIN;
            }
            --next;
            return data[next];
        }
        int top(){
            if( next == 0 ){
                cout << "Stack Empty" << endl;
                return INT_MIN;
            }
            return data[next-1];
        }
        bool isEmpty(){
            return next == 0;
        }
        int size(){
            return  next;
        }
};
// We can add a resizing array part to this to extend it
template <typename T>
class StackVec{
    private:
        vector<T> data;
    public:
        void push(T &i){
            data.push_back(i);
        }
        T pop(){
            T temp = data.back();
            data.pop_back();
            return temp;
        }
        T top() const {
            return data.back();
        }
        int size() const {
            return data.size();
        }
        bool isEmpty() const {
            return data.size() == 0;
        }

};

template<typename T>
class node{
    public:
        node<T> *next;
        T data;

        node (T val)
            : data(val), next(nullptr){}
};

template<typename T>
class StackLL{
    private:
        node<T> *head;
    public:
        StackLL()
            :head(nullptr) {}
        ~StackLL() {
            while (head != nullptr) {
                node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }
        void push(T i){
            node<T>* temp = new node<T>(i);
            temp->next = head;
            head = temp;
        }
        T pop(){
            if(head == nullptr)
                return INT_MIN;
            node<T>* temp = head;
            head = head->next;
            T val = temp->data;
            delete temp;
            return val;

        }
        T top(){
            if(head == nullptr)
                return 0;
            return head->data;
        }
        bool isEmpty(){
            return head==nullptr;
        }
        int size(){
            if(head == nullptr)
                return 0;
            node<T>* curr = head;
            int len = 0;
            while(curr != nullptr){
                ++len;
                curr = curr->next;
            }
            return len;
        }
};

int main(){
    StackLL<int> s1;
    s1.push(5);
    s1.push(3);
    cout << s1.top() << endl;
    s1.pop();
    s1.pop();
    cout << s1.isEmpty() << endl;
    cout << s1.size() << endl;
    s1.push(1);
    cout << s1.top() << endl;
    return 0;
}
