#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    
    for(int i=0;i<s.size();i++) {
        v1[s[i]-'a']++;
    }
    for(int i=0;i<t.size();i++) {
        v2[t[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(v1[i]!=v2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<isAnagram(s,t)<<endl;
    return 0;
}