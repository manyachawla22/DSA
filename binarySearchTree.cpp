#include<climits>
#include<iostream>
#include"binaryTreeNode.h"
#include<algorithm>
BinaryTreeNode<int>* input();
void print(BinaryTreeNode<int>* root);

using namespace std;

/*pair<bool,pair<int,int> > checkBST(BinaryTreeNode<int> *root){
	
	pair<bool,pair<int,int> > ans = make_pair(true,make_pair(INT_MIN, INT_MAX));
	if(root == nullptr)
		return ans;
	
	ans.first = false;
    ans.second.first = ans.second.second = root->data;
	if((root->left != nullptr && root->left->data > root->data) || (root->right != nullptr && root->right->data < root->data))
		return ans;
	
	pair<bool,pair<int,int> > leftAns = checkBST(root->left);
	if(leftAns.first == false || leftAns.second.second > root->data)
		return ans;
	
	pair<bool,pair<int,int> > rightAns = checkBST(root->right);
	if(rightAns.first == false || rightAns.second.first < root->data)
		return ans;
	
	ans.first = true;
	if(leftAns.second.first != INT_MAX)
		ans.second.first = leftAns.second.first;
	if(rightAns.second.second != INT_MIN)
		ans.second.second = rightAns.second.second;
	return ans;
}*/
#include<queue>
BinaryTreeNode<int>* input(){
    int data;
    cout << "Enter Root Data" << endl;
    cin >> data;
    if(data == -1)
        return nullptr;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    /*root->left = input();
    root->right = input();
    return root;*/
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int left;
        cin >> left;
        if(left != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(left);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int right;
        cin >> right;
        if(right != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(right);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void print(BinaryTreeNode<int> * root){
    if(root == nullptr)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
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
void convertArr(BinaryTreeNode<int> *root, vector<int> &elements) {
    if (root == nullptr) 
		return;
    convertArr(root->left, elements);
    elements.push_back(root->data);
    convertArr(root->right, elements);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if (!root) return;
    
    vector<int> elements;
    convertArr(root, elements);

	sort(elements.begin(), elements.end());
    
    int left = 0, right = elements.size() - 1;
    while (left < right) {
        int currentSum = elements[left] + elements[right];
        
        if (currentSum == sum) {
            cout << elements[left] << " " << elements[right] << endl;
            left++;
            right--;
        } 
        else if (currentSum < sum) {
            left++; 
        } 
        else {
            right--; 
        }
    }
}
bool checkBST(BinaryTreeNode<int>*root , int min , int max){
    if(root == nullptr)
        return true;
    if(root->data > max || root->data < min)
        return false;
    return checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);
}

BinaryTreeNode<int>* constructBSTfromArr(int arr[], int start, int end){
    if(start>end)
        return nullptr;
    int mid = (start+end)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int> *left = constructBSTfromArr(arr, start, mid-1);
    BinaryTreeNode<int> *right = constructBSTfromArr(arr, mid+1, end);
    root->left = left;
    root->right = right;
    return root;
}
#include"linkedList.h"
pair<node*,node*> LLfromBST(BinaryTreeNode<int> *root){
    pair<node*,node*> ans = make_pair(nullptr,nullptr);
    if(root == nullptr)
        return ans;
    pair<node*,node*> left = LLfromBST(root->left);
    pair<node*,node*> right = LLfromBST(root->right);
    node* curr = new node(root->data);
    if(left.second != nullptr){
        left.second->next = curr;
        ans.first = left.first;
    }
    else
        ans.first = curr;
    if(right.first != nullptr){
        curr->next = right.first;
        ans.second = right.second;
    }
    else
        ans.second = curr;
    return ans;
}
void delLL(node* head){
    if(head == nullptr)
        return;
    delLL(head->next);
    delete head;
}
void printLL(node* head){
    while(head != nullptr){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}
BinaryTreeNode<int>* lcaHelper(BinaryTreeNode<int>* root, int val1,int val2){
	if(root == nullptr || root->data == val1 || root->data == val2)
		return root;
	BinaryTreeNode<int>* left = lcaHelper(root->left, val1, val2);
	BinaryTreeNode<int>* right = lcaHelper(root->right, val1, val2);

	if(left && right)
		return root;
	if(left)
		return left;
	return right;
}
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
	BinaryTreeNode<int>* ans = lcaHelper(root, val1,val2);
	if(ans)
		return ans->data;
	return -1;
}
void helperReplaceWithLargerNodeSum(BinaryTreeNode<int>* root, int* sum){
	if(root == nullptr)
		return;
	helperReplaceWithLargerNodeSum(root->right,sum);
	*sum+=root->data;
	root->data = *sum;
	helperReplaceWithLargerNodeSum(root->left,sum);
}
int main(){
    BinaryTreeNode<int> *root = input();
    //int arr[]= {1,2,3,4,5,6};
    //BinaryTreeNode<int>*root = constructBSTfromArr(arr,0,5);
    print(root);
    int* sum = new int(0);
    helperReplaceWithLargerNodeSum(root,sum);
    print(root);
    //pair<node*,node*> LL = LLfromBST(root);
    //printLL(LL.first);
    //cout << checkBST(root, INT_MIN, INT_MAX) << endl;
    delete root;
    delete sum;
    //delLL(LL.first);
 return 0;
}
