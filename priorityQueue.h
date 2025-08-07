#include<vector>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

// this is min priority queue
// child = 2i +1, 2i+2
// parent = i-1/2
class MinPriorityQueue{
    vector<int> pq;

    public:
    MinPriorityQueue(){}
    
    bool isEmpty() const{
        return pq.size() == 0;
    }
    
    int getSize() const{
        return pq.size();
    }

    int getMin() const{
        if(isEmpty()){
            cout << "Empty queue" << endl;
            return INT_MAX;
        }
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int node = pq.size()-1;
        int parent  = (node-1)/2;
        while(node != 0 && pq[parent]>pq[node]){
            int temp = pq[parent];
            pq[parent] = pq[node];
            pq[node] = temp;

            node = parent;
            parent = (node -1)/2;
        }
    }
    void print() const{
        if(isEmpty())
            return;
        queue<int> pendingNodes;
        pendingNodes.push(0);
        while(!pendingNodes.empty()){
            int node = pendingNodes.front();
            pendingNodes.pop();
            int left = 2*node + 1;
            int right = 2*node +2;
            cout << pq[node] << ':';
            if(left<pq.size()){
                cout << 'L' << pq[left];
                pendingNodes.push(left);
            }
            if(right<pq.size()){
                cout << 'R' << pq[right];
                pendingNodes.push(right);
            }
            cout << endl;
        }
    }

    int remove(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int node = 0;
        int left = node*2 + 1;
        int right = node*2 + 2;
        while(node<pq.size() && (pq[node]>pq[left] || pq[node]>pq[right])){
            int min;
            if(left<pq.size() && right<pq.size())
                min = (pq[left]>pq[right]) ? right : left;
            else if(left<pq.size())
                min = left;
            else break;
            int temp = pq[node];
            pq[node] = pq[min];
            pq[min] = temp;

            node = min;
            left = node*2 +1;
            right = node*2 +2;
        }
        return ans;
    }
};
//update the class
class MaxPriorityQueue{
    vector<int> pq;

    public:
    MaxPriorityQueue(){}

    bool isEmpty() const{
        return pq.size() == 0;
    }

    int getSize() const{
        return pq.size();
    }

    int getMax() const{
        if(isEmpty()){
            cout << "Empty queue" << endl;
            return INT_MIN;
        }
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int node = pq.size()-1;
        int parent  = (node-1)/2;
        while(node != 0 && pq[parent]<pq[node]){
            int temp = pq[parent];
            pq[parent] = pq[node];
            pq[node] = temp;

            node = parent;
            parent = (node -1)/2;
        }
    }
    void print() const{
        if(isEmpty())
            return;
        queue<int> pendingNodes;
        pendingNodes.push(0);
        while(!pendingNodes.empty()){
            int node = pendingNodes.front();
            pendingNodes.pop();
            int left = 2*node + 1;
            int right = 2*node +2;
            cout << pq[node] << ':';
            if(left<pq.size()){
                cout << 'L' << pq[left];
                pendingNodes.push(left);
            }
            if(right<pq.size()){
                cout << 'R' << pq[right];
                pendingNodes.push(right);
            }
            cout << endl;
        }
    }

    int remove(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int node = 0;
        int left = node*2 + 1;
        int right = node*2 + 2;
        while(node<pq.size() && (pq[node]<pq[left] || pq[node]<pq[right])){
            int max;
            if(left<pq.size() && right<pq.size())
                max = (pq[left]<pq[right]) ? right : left;
            else if(left<pq.size())
                max = left;
            else break;
            int temp = pq[node];
            pq[node] = pq[max];
            pq[max] = temp;

            node = max;
            left = node*2 +1;
            right = node*2 +2;
        }
        return ans;
    }
};
