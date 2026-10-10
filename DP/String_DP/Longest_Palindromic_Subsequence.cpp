#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n=s.size();
    vector<vector<int> > dp(2,vector<int>(n+1));
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0||j==0) {
                dp[i%2][j]=0;
            } else if(s[i-1]==s[n-j]) {
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            } else {
                dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);
            }
        }
    }
    return dp[n%2][n];
}

int main() {
    string s1;
    cin>>s1;
    cout<<longestPalindromeSubseq(s1)<<endl;
    return 0;
}