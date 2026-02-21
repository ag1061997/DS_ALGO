#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) {
        return false;
    }
    unordered_map<char,char> mp;
    for(int i=0;i<s.size();i++) {
        if(mp.find(s[i])!=mp.end()) {
            if(mp[s[i]]!=t[i]) {
                return false;
            }
        } else {
            mp[s[i]]=t[i];
        }
    }
    unordered_map<char,char> mp2;
    for(int i=0;i<s.size();i++) {
        if(mp2.find(t[i])!=mp2.end()) {
            if(mp2[t[i]]!=s[i]) {
                return false;
            }
        } else {
            mp2[t[i]]=s[i];
        }
    }
    return true;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<isIsomorphic(s,t)<<endl;
    return 0;
}