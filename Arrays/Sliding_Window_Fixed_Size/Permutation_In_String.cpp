#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.size()>s2.size()) {
        return false;
    }
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    for(int i=0;i<s1.size();i++) {
        v1[s1[i]-'a']++;
    }
    int c=0;
    for(int i=0;i<26;i++) {
        if(v1[i]==0) {
            c++;
        }
    }
    int i=0;
    for(int j=0;j<s2.size();j++) {
        v2[s2[j]-'a']++;
        if(v2[s2[j]-'a']==v1[s2[j]-'a']) {
            c++;
        }
        while(v2[s2[j]-'a']>v1[s2[j]-'a']) {
            if(v2[s2[i]-'a']==v1[s2[i]-'a']) {
                c--;
            }
            v2[s2[i]-'a']--;
            i++;
        }
        if(c==26) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<checkInclusion(s1,s2)<<endl;
    return 0;
}