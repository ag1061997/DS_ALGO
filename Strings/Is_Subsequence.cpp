#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    if(s.size()==0) {
        return true;
    }
    int j=0;
    for(int i=0;i<t.size();i++) {
        if(s[j]==t[i]) {
            j++;
            if(j==s.size()) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<isSubsequence(s,t)<<endl;
    return 0;
}