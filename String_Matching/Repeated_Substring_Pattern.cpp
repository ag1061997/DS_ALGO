#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n=s.size();
    vector<int> dp(n,0);
    int l=0;
    int i=1;
    while(i<n) {
        if(s[i]==s[l]) {
            l++;
            dp[i]=l;
            i++;
        } else if(l>0) {
            l=dp[l-1];
        } else {
            dp[i]=0;
            i++;
        }
    }
    int c=n-dp[n-1];
    return (dp[n-1]>0&&n%c==0);
}

int main() {
    string s;
    cin>>s;
    cout<<repeatedSubstringPattern(s)<<endl;

    return 0;
}