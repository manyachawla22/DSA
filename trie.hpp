#include<string>
using namespace std;
class TrieNode{ // consider all letters are lowercase
    public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char x, bool isEnd = false): data(x), isTerminal(isEnd) {
        children = new TrieNode*[26];
        for(int i = 0; i<26; ++i){
            children[i] = nullptr;
        }
    }

};

class Trie{
    protected:
    TrieNode* root;

    void helperInsert(string word, TrieNode* root){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        char x = word[0];
        int index = x - 'a';
        TrieNode* child;
        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else{
            child = new TrieNode(x);
            root->children[index] = child;
        }
        helperInsert(word.substr(1), child);
    }

    virtual bool helperSearch(string word, TrieNode* root){
        if(word.size() == 0){
            if(root->isTerminal == true)
                return true;
            return false;
        }
        char x = word[0];
        int index = x - 'a';
        if(root->children[index] == nullptr)
            return false;
        return helperSearch(word.substr(1), root->children[index]);
    }

    void helperRemove(string word, TrieNode*root){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        TrieNode* child;
        int index = word[0]-'a';

        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else
            return;

        helperRemove(word.substr(1),child);

        // now to check if child is useless:
        if(child ->isTerminal == false){
            for(int i = 0; i<26; ++i){
                if(child->children[i] != nullptr)
                    return;
            }
        }
        delete child;
        root->children[index] = nullptr;
    }
    
    void helperPrint(TrieNode* root){
        if(root == nullptr)
            return;
        cout << root->data << ':';
        for(int i = 0; i < 26;++i){
            if(root->children[i] != nullptr){
                cout << root->children[i]->data << ' ';
            }
        }
        cout << endl;
        for(int i = 0; i < 26; ++i){
            if(root->children[i] != nullptr){
                helperPrint(root->children[i]);
            }
        }
        return;
    }
    
    void printAllFromNode(TrieNode* node, string prefix) { // print all words from node, and prefix is the string till node
        if (node->isTerminal)
            cout << prefix << endl;

        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                char ch = i + 'a';
                printAllFromNode(node->children[i], prefix + ch);
            }
        }
    }
    bool isLeaf(TrieNode* root){
        if(root == nullptr)
            return true;
        for(int i = 0; i<26;++i){
            if(root->children[i])
                return false;
        }
        return true;
    }
    vector<string> helperRootToLeaf(TrieNode* root){ // includes the root data as well
        vector<string> ans;
        if(root == nullptr)
            return ans;
        if(isLeaf(root)){
            string x(1,root->data);
            ans.push_back(x);
            return ans;
        }
        for(int i =0; i<26; ++i){
            if(root->children[i]){
                vector<string> child = helperRootToLeaf(root->children[i]);
                ans.insert(ans.end(), child.begin(),child.end());
            }
        }
        for (string& s : ans)
            s = root->data+s; // Append char to each string
        if(root->isTerminal){
            string x(1,root->data);
            ans.push_back(x);
        }
        return ans;
    }

    public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    virtual void insert(string word){
        helperInsert(word,root);
    }
    
    virtual bool search(string word){
        return helperSearch(word,root);
    }

    virtual void remove(string word){
        helperRemove(word,root);
    }
    void print(){ // prints the trie data strucuture in level order form like a tree
        helperPrint(root);
    }
    void rootToLeaf(){ // print all words present in trie
        vector<string> ans = helperRootToLeaf(root);
        for(int i = 0; i<ans.size();++i){
            string x = ans[i];
            cout << x << endl;
        }
    }

    void autoComplete(string prefix){ // prints all the words starting with the prefix
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->children[index])
                return;  // Prefix not found
            curr = curr->children[index];
        }

        printAllFromNode(curr, prefix);
    }

    /* earlier version:
    void autoComplete(string w){ // prints all the words starting with prefix w
        if(root == nullptr)
            return;
        TrieNode* curr = root;
        string og = w;
        while(w.size() != 0){
            char x = w[0];
            int index = x - 'a';
            if(curr->children[index] == nullptr)
                return;
            curr = curr->children[index];
            w = w.substr(1);
        }
        if(curr->isTerminal == true)
            cout << og << endl;
        for(int i = 0; i<26;++i){
            if(curr->children[i] != nullptr){
                char ch = i+'a';
                string sub = og+ch;
                autoComplete(sub);
            }
        }
    }*/
};

class SuffixTrie : public Trie{
    public:
    void insert(string word)override{
        for(int i = 0; i <word.length(); ++i){
            string sub = word.substr(i);
            helperInsert(sub,root);
        }
    }
    bool helperSearch(string word, TrieNode* root)override{
        if(word.size() == 0){
            return true;
        }
        char x = word[0];
        int index = x - 'a';
        if(root->children[index] == nullptr)
            return false;
        return helperSearch(word.substr(1), root->children[index]);
    } 
    //void remove(string word)override{} need to think about this and write it later!
};
