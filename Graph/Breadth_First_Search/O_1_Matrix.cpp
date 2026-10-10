#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int> > ans(n,vector<int>(m,-1));
    queue<pair<int,int> > q;
    vector<vector<int> > v(4,vector<int>(2,0));
    v[0][1]=1;
    v[1][1]=-1;
    v[2][0]=1;
    v[3][0]=-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]==0) {
                ans[i][j]=0;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int x=p.first+v[i][0];
            int y=p.second+v[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&ans[x][y]==-1) {
                ans[x][y]=ans[p.first][p.second]+1;
                q.push(make_pair(x,y));
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
    vector<vector<int> > ans=updateMatrix(v);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}