#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int> >& times, int n, int k) {
    int e=times.size();
    vector<vector<pair<int,int> > > g(n,vector<pair<int,int> >());
    for(int i=0;i<e;i++) {
        g[times[i][0]-1].push_back(make_pair(times[i][1]-1,times[i][2]));
    }
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[k-1]=0;
    pq.push(make_pair(0,k-1));
    while(!pq.empty()) {
        pair<int,int> p=pq.top();
        pq.pop();
        int d=p.first;
        int u=p.second;
        for(int i=0;i<g[u].size();i++) {
            if(dist[g[u][i].first]>d+g[u][i].second) {
                dist[g[u][i].first]=d+g[u][i].second;
                pq.push(make_pair(dist[g[u][i].first],g[u][i].first));
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++) {
        if(dist[i]==INT_MAX) return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
}

int main() {
    int n,k,e;
    cin>>n>>k>>e;
    vector<vector<int> > v(e,vector<int>(3));
    for(int i=0;i<e;i++) {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cout<<networkDelayTime(v,n,k)<<endl;
}