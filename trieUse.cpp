#include<iostream>
#include"trie.hpp"
// NOTEs: type of tries - compression and suffix trie
// compression- merge 2 linear nodes for space
// suffic - find suffix as well, if word is bend and we find nd, it should return true
int main(){
    Trie obj;
    //obj.insert("hi");
    obj.insert("and");
    obj.insert("are");
    obj.insert("andres");
    obj.insert("ande");
    obj.insert("andess");
    //cout << obj.search("and") << endl;
    //obj.remove("and");
    //cout << obj.search("and") << endl;
    //obj.print();
    //obj.autoComplete("a");
    obj.rootToLeaf();
    
    /*SuffixTrie t;
    t.insert("stop");
    //t.print();
    cout << t.search("stop") << endl;
    cout << t.search("top") << endl;
    cout << t.search("op") << endl;
    cout << t.search("p") << endl;
    cout << t.search("st") << endl;
    */
}
