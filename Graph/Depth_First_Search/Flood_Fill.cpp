#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();
    if(color==image[sr][sc]) {
        return image;
    }
    int k=image[sr][sc];
    queue<pair<int,int> > q;
    q.push(make_pair(sr,sc));
    image[sr][sc]=color;
    while(!q.empty()) {
        pair<int,int> p=q.front();
        q.pop();
        if(p.first>0&&image[p.first-1][p.second]==k) {
            image[p.first-1][p.second]=color;
            q.push(make_pair(p.first-1,p.second));
        }
        if(p.first<n-1&&image[p.first+1][p.second]==k) {
            image[p.first+1][p.second]=color;
            q.push(make_pair(p.first+1,p.second));
        }
        if(p.second>0&&image[p.first][p.second-1]==k) {
            image[p.first][p.second-1]=color;
            q.push(make_pair(p.first,p.second-1));
        }
        if(p.second<m-1&&image[p.first][p.second+1]==k) {
            image[p.first][p.second+1]=color;
            q.push(make_pair(p.first,p.second+1));
        }
    }
    return image;
}

int main() {
    int n,m,r,c,x;
    cin>>n>>m>>r>>c>>x;
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    vector<vector<int> > ans=floodFill(v,r,c,x);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}