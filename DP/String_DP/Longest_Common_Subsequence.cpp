#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size();
    int m=text2.size();
    vector<vector<int> > dp(2,vector<int>(m+1));
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0||j==0) {
                dp[i%2][j]=0;
            } else if(text1[i-1]==text2[j-1]) {
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            } else {
                dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);
            }
        }
    }
    return dp[n%2][m];
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<longestCommonSubsequence(s1,s2)<<endl;
    return 0;
}