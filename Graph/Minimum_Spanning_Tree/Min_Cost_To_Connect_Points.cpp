#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &v,int x) {
    if(x!=v[x]) {
        v[x]=find(v,v[x]);
    }
    return v[x];
}

void merge(vector<int> &r,vector<int> &p,int x,int y) {
    if(r[x]<r[y]) {
        p[x]=y;
    } else if(r[y]<r[x]) {
        p[y]=x;
    } else {
        p[y]=x;
        r[x]++;
    }
}

int minCostConnectPoints(vector<vector<int> >& points) {
    int n=points.size();
    vector<int> v(n,0);
    vector<int> v2(n);
    for(int i=0;i<n;i++) {
        v2[i]=i;
    }
    vector<pair<int,pair<int,int> > > g;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            g.push_back(make_pair(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),make_pair(i,j)));
        }
    }
    sort(g.begin(),g.end());
    int ans=0;
    int c=0;
    for(int i=0;i<g.size()&&c<n-1;i++) {
        int x=g[i].second.first;
        int y=g[i].second.second;
        int x1=find(v2,x);
        int y1=find(v2,y);
        if(x1!=y1) {
            ans+=g[i].first;
            merge(v,v2,x1,y1);
            c++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<minCostConnectPoints(v)<<endl;
}