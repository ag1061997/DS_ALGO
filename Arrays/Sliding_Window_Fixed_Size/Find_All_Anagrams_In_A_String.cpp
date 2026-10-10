#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if(p.size()>s.size()) {
        return ans;
    }
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    for(int i=0;i<p.size();i++) {
        v1[p[i]-'a']++;
    }
    int c=0;
    for(int i=0;i<26;i++) {
        if(v1[i]==0) {
            c++;
        }
    }
    int i=0;
    for(int j=0;j<s.size();j++) {
        v2[s[j]-'a']++;
        if(v2[s[j]-'a']==v1[s[j]-'a']) {
            c++;
        }
        while(v2[s[j]-'a']>v1[s[j]-'a']) {
            if(v2[s[i]-'a']==v1[s[i]-'a']) {
                c--;
            }
            v2[s[i]-'a']--;
            i++;
        }
        if(c==26) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    vector<int> ans=findAnagrams(s1,s2);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}