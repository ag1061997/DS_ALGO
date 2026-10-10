#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int j=0;
    int ans=0;
    vector<int> v(26,0);
    int mx=0;
    for(int i=0;i<s.size();i++) {
        v[s[i]-'A']++;
        mx=max(mx,v[s[i]-'A']);
        if((i-j+1)-mx>k) {
            v[s[j]-'A']--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}

int main() {
    int k;
    string s;
    cin>>s>>k;
    cout<<characterReplacement(s,k)<<endl;
    return 0;
}