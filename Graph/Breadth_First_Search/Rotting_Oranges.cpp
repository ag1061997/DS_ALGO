#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int> >& grid, int n, int m, int i, int j) {
    return (i<n&&j<m&&i>=0&&j>=0&&grid[i][j]==1);
}

int orangesRotting(vector<vector<int> >& grid) {
    int ans=0;
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]==2) {
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()) {
        int c=q.size();
        for(int i=0;i<c;i++) {
            pair<int,int> p=q.front();
            q.pop();
            if(check(grid,n,m,p.first+1,p.second)) {
                grid[p.first+1][p.second]=2;
                q.push(make_pair(p.first+1,p.second));
            }
            if(check(grid,n,m,p.first-1,p.second)) {
                grid[p.first-1][p.second]=2;
                q.push(make_pair(p.first-1,p.second));
            }
            if(check(grid,n,m,p.first,p.second+1)) {
                grid[p.first][p.second+1]=2;
                q.push(make_pair(p.first,p.second+1));
            }
            if(check(grid,n,m,p.first,p.second-1)) {
                grid[p.first][p.second-1]=2;
                q.push(make_pair(p.first,p.second-1));
            }
        }
        if(!q.empty()) {
            ans++;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]==1) {
                ans=-1;
            }
        }
    }
    return ans;
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
    cout<<orangesRotting(v)<<endl;
    return 0;
}