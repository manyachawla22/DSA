#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T val = 0)
            :data(val) {}
};

void PreOrder(TreeNode<int>* root){
    if(root == nullptr) // this is an edge case(if root == null) not a base case!
        return;
    cout << root->data << ':';
    for(int i =0; i<root->children.size(); ++i)
        cout << root->children[i]->data << ' ';
    cout << endl;
    for(int i =0; i<root->children.size(); ++i)
        PreOrder(root->children[i]);
}
void PostOrder(TreeNode<int>* root){
    if(root == nullptr)
        return;
    for(int i = 0; i<root->children.size(); ++i){
        PostOrder(root->children[i]);
    }
    cout << root->data << ' ';
}
void printTree(TreeNode<int>* root){
    if(root == nullptr)
        return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": " ;
        for(int i =0; i<front->children.size(); ++i){
            cout << front->children[i]->data << ' ';
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

/*TreeNode<int>* takeInput(){
    int rootData, n;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    cout << "Enter no of children of " << rootData << endl;
    cin >>  n;
    for(int i = 0; i<n; ++i){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;

}*/
TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter no of children of " << front->data << endl;
        int n;
        cin >> n;
        for(int i = 0; i<n; ++i){
            int child;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> child;
            TreeNode<int>* childNode = new TreeNode<int>(child);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

void deleteTree(TreeNode<int>* root){
    if(root == nullptr)
        return;
    for(int i =0; i<root->children.size(); ++i){
        deleteTree(root->children[i]);
    }
    delete root;
}
int sumOfNodes(TreeNode<int>* root) {
    if(root == nullptr)
        return -1;
    int sum = root->data;
    for(int i =0; i<root->children.size(); ++i){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == nullptr)
        return root;
    TreeNode<int>* maxNode = root;
    for (int i = 0; i < root->children.size(); ++i) {
        TreeNode<int> *tempMax = maxDataNode(root->children[i]);
        if (tempMax->data > maxNode->data)
          maxNode = tempMax;
    }
    return maxNode;
}
int getHeight(TreeNode<int>* root) {
    if(root == nullptr)
        return 0;
    int maxHeight = 0;
    for(int i =0; i<root->children.size(); ++i){
        int tempHeight = getHeight(root->children[i]);
        if(tempHeight>maxHeight)
            maxHeight = tempHeight;
    }
    return maxHeight+1;
}
void printLevelK(TreeNode<int>* root, int k){
    if(root == nullptr)
        return;
    if(k == 0){
        cout << root->data << endl;
        return;
    }
    for(int i = 0; i<root->children.size(); ++i){
        printLevelK(root->children[i], k-1);
    }
}

int leafNodes(TreeNode<int>* root){
    if(root == nullptr)
        return 0;
    int num = 0;
    if(root->children.empty())
        return 1;
    for(int i =0; i<root->children.size(); ++i){
        num += leafNodes(root->children[i]);
    }
    return num;
}

int NodeCount(TreeNode<int>* root){
    if(root == nullptr)
        return 0;
    int count = 1;
    for(int i =0; i<root->children.size(); ++i){
        count += NodeCount(root->children[i]);
    }
    return count;
}
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == nullptr && root2 == nullptr)
        return true;
    if(root1 == nullptr || root2 == nullptr)
        return false;
    if(root1->data != root2->data)
        return false;
    if(root1->children.size() != root2->children.size())
        return false;
    for (int i = 0; i < root1->children.size(); ++i) {
        bool ans = areIdentical(root1->children[i], root2->children[i]);
        if(ans == false)
            return false;
    }
    return true;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    TreeNode<int> *root = takeInput();
    PostOrder(root);
    cout << "No of nodes = " << NodeCount(root) << endl;
    deleteTree(root); // alternate: make a destrutor in TreeNode, to delete tree!

    /*
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);
    root->children.push_back(n1);
    root->children.push_back(n2);
    printTree(root);
    delete root;
    delete n1;
    delete n2;
    */
    return 0;
}
