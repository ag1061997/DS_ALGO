#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &g, vector<bool> &vis, vector<int> &dp,int n,int x,int &ans2,int c) {
    if(ans2==-1) {
        return;
    }
    c=0;
    for(int i=0;i<g[x].size();i++) {
        if(vis[g[x][i]]==true) {
            ans2=-1;
            return;
        }
        if(dp[g[x][i]]!=0) {
            c=max(c,dp[g[x][i]]);
        } else {
            vis[g[x][i]]=true;
            dfs(g,vis,dp,n,g[x][i],ans2,c);
            vis[g[x][i]]=false;
            c=max(c,dp[g[x][i]]);
        }
    }
    dp[x]=max(dp[x],c+1);
}

int minimumSemesters(int n, vector<vector<int> >& relations) {
    int e=relations.size();
    vector<vector<int> > g(n,vector<int>());
    for(int i=0;i<e;i++) {
        g[relations[i][0]-1].push_back(relations[i][1]-1);
    }
    int ans=0;
    int ans2=0;
    vector<bool> vis(n,false);
    vector<int> dp(n,0);
    for(int i=0;i<n;i++) {
        ans2=0;
        vis[i]=true;
        dfs(g,vis,dp,n,i,ans2,0);
        vis[i]=false;
        if(ans2==-1) {
            return -1;
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int> > v(e,vector<int>(2));
    for(int i=0;i<e;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<minimumSemesters(n,v)<<endl;
}