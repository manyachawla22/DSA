#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class queueArr{
    private:
        int size;
        static const int capacity = 5;
        T arr[capacity];
        int first;
        int last;
    public:
        queueArr()
            : size(0), first(-1), last(0) {}
        void enqueue(T data){
            if(size == capacity)
                return;
            ++size;
            arr[last] = data;
            if(first == -1)
                first = 0;
            if(last == capacity-1)
                last = 0;
            else
                ++last;

        }
        T dequeue(){
            if(size == 0)
                return 0;
            --size;
            T val = arr[first];
            if(first == capacity-1)
                first = 0;
            else
                ++first;
            return val;
        }
        T front(){
            if(size == 0){
                cout << "empty queue" << endl;
                return -1;
            }
            return arr[first];
        }
        int getsize(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        void print(){
            if(last>first){
                for(int i =first; i<last; ++i)
                    cout << arr[i] << " ";
            }
            else{
                for(int i = first;i<capacity; ++i )
                    cout << arr[i] << " ";
                for(int i =0; i<last; ++i)
                    cout << arr[i] << " ";
            }
            cout << endl;
        }
};

template<typename T>
class node{
    public:
        node<T>* next;
        T data;
        
        node(T data)
            : data(data), next(nullptr){}
};

template<typename T>
class queueLL{
    private:
        node<T> *head;
        node<T> *tail;
        int size;
    public:
        queueLL()
            :head(nullptr), tail(nullptr), size(0) {}
        ~queueLL() {
            while (head != nullptr) {
                node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }
        void enqueue(T data){
            node<T> *temp = new node<T>(data);
            if(head == nullptr){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            ++size;
        }
        T dequeue(){
            if(head == nullptr)
                return -1;
            --size;
            node<T> *temp = head;
            head = head->next;
            T val = temp->data;
            delete temp;
            return val;
        }
        int getsize(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        T front(){
            if(head == nullptr)
                return -1;
            return head->data;
        }
};

int main(){
    queueLL<int> q;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
