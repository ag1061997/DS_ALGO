#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s) {
    vector<int> v(26,0);
    for(int i=0;i<s.size();i++) {
        v[s[i]-'a']++;
    }
    sort(v.begin(),v.end());
    int c=v[25]-1;
    int ans=0;
    for(int i=24;i>=0;i--) {
        if(v[i]==0) {
            break;
        }
        if(c==0) {
            ans+=v[i];
        } else {
            if(c>=v[i]) {
                c=v[i]-1;
            } else {
                ans+=(v[i]-c);
                c--;
            }
        }
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<minDeletions(s)<<endl;
    return 0;
}