#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    vector<int> v(256,0);
    int ans=0;
    int f=0;
    for(int i=0;i<s.size();i++) {
        v[(int)s[i]]++;
    }
    for(int i=0;i<256;i++) {
        if(v[i]%2==0) {
            ans+=v[i];
        } else {
            if(f==0) {
                f=1;
                ans+=v[i];
            } else {
                ans=ans+v[i]-1;
            }
        }
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}