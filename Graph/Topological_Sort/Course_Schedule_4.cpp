#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void dfs(int n,vector<vector<int> > &g,vector<unordered_set<int> > &mp,vector<bool> &vis,int x) {
    vis[x]=true;
    for(int i=0;i<g[x].size();i++) {
        if(vis[g[x][i]]==false) {
            dfs(n,g,mp,vis,g[x][i]);
        }
        if(mp[x].find(g[x][i])==mp[x].end()) {
            mp[x].insert(mp[g[x][i]].begin(),mp[g[x][i]].end());
            mp[x].insert(g[x][i]);
        }
    }
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int> >& prerequisites, vector<vector<int> >& queries) {
    vector<vector<int> > g(numCourses,vector<int>());
    for(int i=0;i<prerequisites.size();i++) {
        g[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<unordered_set<int> > mp(numCourses,unordered_set<int>());
    vector<bool> vis(numCourses,false);
    for(int i=0;i<numCourses;i++) {
        if(vis[i]==false) {
            dfs(numCourses,g,mp,vis,i);
        }
    }
    vector<bool> ans(queries.size(),false);
    for(int i=0;i<queries.size();i++) {
        if(mp[queries[i][0]].find(queries[i][1])!=mp[queries[i][0]].end()) {
            ans[i]=true;
        }
    }
    return ans;
}

int main() {
    int n,m,o;
    cin>>n>>m>>o;
    vector<vector<int> > v(m,vector<int>(2));
    vector<vector<int> > q(o,vector<int>(2));
    for(int i=0;i<m;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    for(int i=0;i<o;i++) {
        cin>>q[i][0]>>q[i][1];
    }
    vector<bool> ans=checkIfPrerequisite(n,v,q);
    for(int i=0;i<o;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}