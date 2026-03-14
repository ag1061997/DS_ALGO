#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    vector<vector<int> > dp(2,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(obstacleGrid[i][j]==1) {
                dp[i%2][j]=0;
            } else if(i==0&&j==0) {
                dp[i%2][j]=1;
            } else if(i==0) {
                dp[i%2][j]=dp[i%2][j-1];
            } else if(j==0) {
                dp[i%2][j]=dp[(i-1)%2][j];
            } else {
                dp[i%2][j]= dp[i%2][j-1]+dp[(i-1)%2][j];
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
    cout<<uniquePathsWithObstacles(v)<<endl;
    return 0;
}