#include"binaryTreeNode.h"
#include<iostream>
using namespace std;
class BST{
    BinaryTreeNode<int>* root;
    void print(BinaryTreeNode<int> * curr){
        if(curr == nullptr)
            return;
        queue<BinaryTreeNode<int>*> pendingNodes;
        pendingNodes.push(curr);
        while(!pendingNodes.empty()){
            BinaryTreeNode<int> *front = pendingNodes.front();
            cout << front->data << ':';
            if(front->left){
                cout << 'L' << front->left->data << ' ';
                pendingNodes.push(front->left);
            }
            if(front->right){
                cout << 'R' << front->right->data;
                pendingNodes.push(front->right);
            }
            cout << endl;
            pendingNodes.pop();
        }
    }
    bool helperHasData(BinaryTreeNode<int>* curr, int val){
        if(curr == nullptr)
            return false;
        if(curr->data == val)
            return true;
        if(curr->data > val)
            return helperHasData(curr->left, val);
        return helperHasData(curr->right, val);
    }
    BinaryTreeNode<int>* helperInsert(BinaryTreeNode<int>* curr, int val){
        BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(val);
        if(root == nullptr){
            root = temp;
            return root;
        }
        if(curr == nullptr)
            return curr;
        if(curr->data < val){
            BinaryTreeNode<int> *right = helperInsert(curr->right, val);
            if(right == nullptr)
                curr->right = temp;
            return curr;
        }
        BinaryTreeNode<int> *left = helperInsert(curr->left,val);
        if(left == nullptr)
            curr->left = temp;
        return curr;
    }
    BinaryTreeNode<int>* findMax(BinaryTreeNode<int>* curr) {
        if (curr == nullptr)
            return nullptr; 
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        return curr;
    }
    BinaryTreeNode<int>* helperDel(BinaryTreeNode<int>* curr, int val){
        if(curr == nullptr)
            return nullptr;
        if(curr->data < val)
            curr->right = helperDel(curr->right,val);
        else if(curr->data > val)
            curr->left = helperDel(curr->left, val);
        else{
            if(curr->right == nullptr){
                BinaryTreeNode<int>* temp = curr->left;
                delete curr;
                return temp;
            }
            else if(curr->left == nullptr){
                BinaryTreeNode<int>* temp = curr->right;
                delete curr;
                return temp;
            }
            else{
                BinaryTreeNode<int>* rightmost = findMax(curr->left);
                curr->data = rightmost->data;
                curr->left = helperDel(curr->left,rightmost->data);
            }
        }
        return curr;
    }
    public:
    BST()
        :root(nullptr){}
    ~BST(){
        delete root;
    }
    void insert(int val){
        helperInsert(root,val);
    }
    void del(int val){
        helperDel(root,val);
    }
    bool hasData(int val){
        return helperHasData(root, val);
    }
    void print(){
        print(root);
    }
};
