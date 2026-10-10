#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& g, vector<int>& vis, vector<int>& ans, bool &flag, int index) {
    if(flag) {
        return;
    }
    vis[index]=1;
    for(int i=0;i<g[index].size();i++) {
        if(vis[g[index][i]]==0) {
            dfs(g,vis,ans,flag,g[index][i]);
        } else if(vis[g[index][i]]==1) {
            flag=true;
            return;
        }
    }
    vis[index]=2;
    ans.push_back(index);
}

vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
    vector<vector<int> > g(numCourses,vector<int>());
    for(int i=0;i<prerequisites.size();i++) {
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }  

    vector<int> vis(numCourses,0);
    vector<int> ans;
    bool flag=false;
    for(int i=0;i<numCourses;i++) {
        if(vis[i]==0) {
            dfs(g,vis,ans,flag,i);
            if(flag) {
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    if(flag) {
        ans.clear();
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

    vector<int> ans=findOrder(n,v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}