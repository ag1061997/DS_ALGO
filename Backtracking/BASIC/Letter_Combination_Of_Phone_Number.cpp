#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void find(string digits,int n,vector<string> &ans,unordered_map<char, vector<char> > mp,int idx, string &s) {
    if(idx==n) {
        ans.push_back(s);
        return;
    }
    for(int i=0;i<mp[digits[idx]].size();i++) {
        s[idx]=mp[digits[idx]][i];
        find(digits,n,ans,mp,idx+1,s);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    int n=digits.size();
    if(n==0) {
        return ans;
    }
    string s=digits;
    unordered_map<char, vector<char> > mp;
    mp['2']= {'a','b','c'};
    mp['3']= {'d','e','f'};
    mp['4']= {'g','h','i'};
    mp['5']= {'j','k','l'};
    mp['6']= {'m','n','o'};
    mp['7']= {'p','q','r','s'};
    mp['8']= {'t','u','v'};
    mp['9']= {'w','x','y','z'};
    find(digits,n,ans,mp,0,s);
    return ans;
}

int main() {
    string s;
    cin>>s;
    vector<string> ans=letterCombinations(s);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
}