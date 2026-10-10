#include <bits/stdc++.h>
using namespace std;

void find(vector<vector<char> >& grid,int n,int m,int i,int j) {
    if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0') {
        return;
    }
    grid[i][j]='0';
    find(grid,n,m,i+1,j);
    find(grid,n,m,i-1,j);
    find(grid,n,m,i,j+1);
    find(grid,n,m,i,j-1);
}

int numIslands(vector<vector<char> >& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='1') {
                ans++;
                find(grid,n,m,i,j);
            }
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char> > v(n,vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    cout<<numIslands(v)<<endl;
    return 0;
}