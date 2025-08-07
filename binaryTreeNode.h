#include<iostream>
template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(T val)
            :data(val), left(nullptr), right(nullptr){}
        
        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};
