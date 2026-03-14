#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int> > dp(2,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0&&j==0) {
                dp[i%2][j]=grid[i][j];
            } else if(i==0) {
                dp[i%2][j]=dp[i%2][j-1]+grid[i][j];
            } else if(j==0) {
                dp[i%2][j]=dp[(i-1)%2][j]+grid[i][j];
            } else {
                dp[i%2][j]=min(dp[(i-1)%2][j],dp[i%2][j-1])+grid[i][j];
            }
        }
    }
    return dp[(n-1)%2][m-1];
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    cout<<minPathSum(v)<<endl;
    return 0;
}