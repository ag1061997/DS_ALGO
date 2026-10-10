#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void dfs(vector<vector<int> >& grid, int n, int m, int i, int j, int &x, int &y, string &s) {
    if(i<0||i>=n||j<0||j>=m||grid[i][j]==0) {
        return;
    }
    s+=to_string(i-x)+to_string(j-y)+"_";
    grid[i][j]=0;
    dfs(grid,n,m,i+1,j,x,y,s);
    dfs(grid,n,m,i-1,j,x,y,s);
    dfs(grid,n,m,i,j+1,x,y,s);
    dfs(grid,n,m,i,j-1,x,y,s);
}

int numDistinctIslands(vector<vector<int> >& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int c=0;
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]==1) {
                string s="";
                dfs(grid,n,m,i,j,i,j,s);
                mp[s]=1;
            }
        }
    }
    return mp.size();
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
    cout<<numDistinctIslands(v)<<endl;
}