#include <bits/stdc++.h>
using namespace std;

class Trie {
    Trie* children[26];
    bool isEnd;

    public:
        Trie() {
            for(int i=0;i<26;i++) {
                this->children[i]=nullptr;
            }
            this->isEnd=false;
        }
        
        void insert(string word) {
            Trie* n=this;
            for(int i=0;i<word.size();i++) {
                int idx=word[i]-'a';
                if(n->children[idx]==nullptr) {
                    n->children[idx]=new Trie();
                }
                n=n->children[idx];
            }
            n->isEnd=true;
        }
        
        bool search(string word) {
            Trie* n=this;
            for(int i=0;i<word.size();i++) {
                int idx=word[i]-'a';
                if(n->children[idx]==nullptr) {
                    return false;
                }
                n=n->children[idx];
            }
            return (n->isEnd==true);
        }
        
        bool startsWith(string prefix) {
            Trie* n=this;
            for(int i=0;i<prefix.size();i++) {
                int idx=prefix[i]-'a';
                if(n->children[idx]==nullptr) {
                    return false;
                }
                n=n->children[idx];
            }
            return true;
        }
};

int main() {
    Trie* n=new Trie();
    n->insert("apple");
    cout<<n->search("apple")<<endl;
    cout<<n->search("app")<<endl;
    cout<<n->startsWith("app")<<endl;
    n->insert("app");
    cout<<n->search("app")<<endl;

    return 0;
}