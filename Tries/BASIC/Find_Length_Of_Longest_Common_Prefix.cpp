#include <bits/stdc++.h>
using namespace std;

class Trie {
    public:
        vector<Trie*> next;
        Trie() {
            vector<Trie*> t(10);
            next=t;
        }
};

void createTrie(vector<int>& v, Trie* head) {
    for(int i=0;i<v.size();i++) {
        string s=to_string(v[i]);
        Trie* cur=head;
        for(int j=0;j<s.size();j++) {
            if(cur->next[s[j]-'0']==nullptr) {
                cur->next[s[j]-'0']=new Trie();
            }
            cur=cur->next[s[j]-'0'];
        }
    }
}

int getCount(Trie* head,int n) {
    string s=to_string(n);
    int c=0;
    Trie* cur=head;
    for(int i=0;i<s.size();i++) {
        if(cur->next[s[i]-'0']!=nullptr) {
            c++;
            cur=cur->next[s[i]-'0'];
        } else {
            break;
        }
    }
    return c;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie* head=new Trie();
    createTrie(arr1,head);
    int ans=0;
    for(int i=0;i<arr2.size();i++) {
        ans=max(ans,getCount(head,arr2[i]));
    }
    return ans;
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    vector<int> v(n1);
    vector<int> v2(n2);
    for(int i=0;i<n1;i++) {
        cin>>v[i];
    }
    for(int i=0;i<n2;i++) {
        cin>>v2[i];
    }
    cout<<longestCommonPrefix(v,v2)<<endl;
}