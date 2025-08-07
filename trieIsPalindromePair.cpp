class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word))
            this->count++;
    }
    // BELOW THIS IS MY CODE, ABOVE CODE IS OF CN
    TrieNode* helperSearch(string word, TrieNode* root){
        if(word.size() == 0){
            return root;
        }
        char x = word[0];
        int index = x - 'a';
        if(root->children[index] == nullptr)
            return nullptr;
        return helperSearch(word.substr(1), root->children[index]);
    }
    bool isPalindrome(string str) {
        int length = str.length();
        int count = length;
        for ( int i =0; i != (count+1)/2; ++i, --length ){
            if ( str[i] != str[length-1]){
                return false;
            }
        }
        return true;
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
    int countMatchingPrefix(const string &word) {
        TrieNode *current = root;
        int matchedLength = 0;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                break;
            }
            current = current->children[index];
            matchedLength++;
        }
        if (matchedLength > 0 && current->isTerminal) {
            return matchedLength; // Return the matched length if it's a terminal node
        }
        return -1; // Return 0 if the last matched character is not an end of a word
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        for(int i = 0; i<words.size(); ++i){
            string x = words[i];
            reverse(x.begin(), x.end());
            add(x);
        }

        for(int i = 0; i<words.size(); ++i){
            string x = words[i];
            TrieNode* node = helperSearch(x,root);
            if(node!= nullptr && node->isTerminal)
                return true;
            if(node){
                for(int i =0; i<26;++i){
                    vector<string> leaf = helperRootToLeaf(node->children[i]);
                    for(int j =0; j<leaf.size();++j){
                    string y = leaf[j];
                    if(isPalindrome(y))
                        return true;
                    }   
                }
            }
            else {
                int count = countMatchingPrefix(x);
                if(count !=-1){
                    string y = x.substr(count);
                    if(isPalindrome(y))
                        return true;
                }
            }
        }
        return false;
    }
};
