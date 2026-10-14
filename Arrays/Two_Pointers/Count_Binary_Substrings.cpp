#include <bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s) {
    int ans=0;
    int c1=0;
    int c2=0;
    char pre=s[0];
    if(pre=='0') {
        c1++;
    } else {
        c2++;
    }
    for(int i=1;i<s.size();i++) {
        if(s[i]==pre) {
            if(pre=='0') {
                c1++;
            } else {
                c2++;
            }
        } else {
            ans+=min(c1,c2);
            if(pre=='0') {
                pre='1';
                c2=1;
            } else {
                pre='0';
                c1=1;
            }
        }
    }
    ans+=min(c1,c2);
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<countBinarySubstrings(s)<<endl;
}