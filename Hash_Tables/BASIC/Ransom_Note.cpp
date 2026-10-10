#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> v(26,0);
    for(int i=0;i<magazine.size();i++) {
        v[magazine[i]-'a']++;
    }
    for(int i=0;i<ransomNote.size();i++) {
        if(v[ransomNote[i]-'a']==0) {
            return false;
        }
        v[ransomNote[i]-'a']--;
    }
    return true;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<canConstruct(s,t)<<endl;
    return 0;
}