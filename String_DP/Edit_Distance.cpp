#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    vector<vector<int> > dp(2,vector<int>(m+1));
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0) {
                dp[i%2][j]=j;
            } else if(j==0) {
                dp[i%2][j]=i;
            } else if(word1[i-1]==word2[j-1]) {
                dp[i%2][j]=dp[(i-1)%2][j-1];
            } else {
                dp[i%2][j]=min(dp[i%2][j-1],min(dp[(i-1)%2][j],dp[(i-1)%2][j-1]))+1;
            }
        }
    }
    return dp[n%2][m];
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<minDistance(s1,s2)<<endl;
    return 0;
}