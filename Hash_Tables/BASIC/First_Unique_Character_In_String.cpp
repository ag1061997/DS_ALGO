#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    vector<int> v(26,-1);
    for(int i=0;i<s.size();i++) {
        if(v[s[i]-'a']==-1) {
            v[s[i]-'a']=i;
        } else {
            v[s[i]-'a']=INT_MAX;
        }
    }
    int ans=-1;
    for(int i=0;i<26;i++) {
        if(v[i]!=-1&&v[i]!=INT_MAX) {
            if(ans==-1) {
                ans=v[i];
            } else {
                ans=min(ans,v[i]);
            }
        }
    }
    return ans;
}

int main() {
    string s1;
    cin>>s1;
    cout<<firstUniqChar(s1)<<endl;
    return 0;
}