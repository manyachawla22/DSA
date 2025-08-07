#include<iostream>
#include<vector>

using namespace std;

class node{
    public:
        node* next;
        int data;
        
        node(int data)
            : data(data), next(nullptr){}
};

class linkedList{
    private:
        node* tail;
    public:
        node* head;
        
        linkedList()
            : head(nullptr), tail(nullptr){}

        ~linkedList(){
            node* curr = head;
            while(curr != nullptr){
                node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }

        void add(int val){
            node* curr = new node(val);
            if(head == nullptr)
                tail = head = curr;
            else{
                tail->next = curr;
                tail = curr;
            }
        }

        int search(int val){
            node* curr = head;
            int i = 0;
            while(curr != nullptr){
                if(curr->data == val)
                    return i;
                curr = curr->next;
                ++i;
            }
            return -1;
        }

        void delNum(int val){
            node* curr = head;
            node* prev = curr;
            if(curr != nullptr && curr->data == val){
                head = curr->next;
                delete curr;
                return;
            }
            while(curr != nullptr){
                if(curr->data == val){
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                else{
                    prev = curr;
                    curr = curr->next;
                }
            }

        }
        void sortedAdd(int val){
            if(head==nullptr){
                add(val);
                return;
            }
            if(val <= head->data){
                insert(0,val);
                return;
            }
            node* curr = head;
            while(curr != nullptr && curr->next != nullptr){
                if(curr->data <= val && curr->next->data > val){
                    node* temp = new node(val);
                    temp->next = curr->next;
                    curr->next = temp;
                    return;
                }
                curr = curr->next;
            }
            add(val);
        }
        void insert(int i, int val){
            if(i == 0){
                node* n = new node(val);
                n->next = head;
                head  = n;
                return;
            }
            node* curr = head;
            for(int j = 0;curr !=nullptr &&  j<i-1; ++j)
                curr = curr->next;
            if(curr == nullptr)
                return;
            node* n = new node(val);
            n->next = curr->next;
            curr->next = n;
        }
        
        void delIndex(int i){
            if(head == nullptr)
                return;
            node* curr = head;
            node* prev = head;
            if(i==0){
                head = curr->next;
                delete curr;
                return;
            }
            for(int j = 0; curr != nullptr && j<i; ++j){
                prev = curr;
                curr = curr->next;
            }
            if(curr == nullptr)
                return;
            prev->next = curr->next;
            delete curr;
        }
        
        int length(){
            node* curr = head;
            int len = 0;
            while(curr!=nullptr){
                ++len;
                curr = curr->next;
            }
            return len;
        }
        
        void print(){
            node* curr = head;
            while(curr != nullptr){
                cout << curr->data << " " ;
                curr = curr->next;
            }
            cout << endl;
        }
        
        node* midNode(){
            node* slow = head;
            node* fast = head->next;
            while(fast!= nullptr && fast->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }   
        void mergeTwoSortedLinkedLists(linkedList l)
        {
            if(head == nullptr){
                head = l.head;
                return;
            }
	        if(l.head == nullptr)
		        return;
	
	        node* nhead = (head->data > l.head->data) ? l.head : head;
	        node* ntail = nhead;
	        if(head->data > l.head->data)
		        l.head = l.head->next;
	        else
		        head = head->next;
	        while(head != nullptr && l.head != nullptr){
		        node* temp = (head->data > l.head->data) ? l.head : head;
		        ntail->next = temp;
		        ntail = ntail->next;
		        if(head->data > l.head->data)
			        l.head = l.head->next;
		        else
			        head = head->next;
	        }
	        if(head == nullptr)
		        ntail->next = l.head;
	        else
		        ntail->next = head;
	        head = nhead;
        }
};
