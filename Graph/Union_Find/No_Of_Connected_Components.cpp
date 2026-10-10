#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &v,int x) {
    int ans=v[x];
    if(ans!=v[ans]) {
        return v[x]=find(v,ans);
    }
    return ans;
}

void merge(vector<int> &r,vector<int> &p,int x,int y) {
    int x1=find(p,x);
    int y1=find(p,y);
    if(x1==y1) return;
    if(r[x1]<r[y1]) {
        p[x1]=y1;
    } else if(r[y1]<r[x1]) {
        p[y1]=x1;
    } else {
        p[y1]=x1;
        r[x1]++;
    }
}

int countComponents(int n, vector<vector<int> >& edges) {
    vector<int> v(n,0);
    vector<int> v2(n);
    for(int i=0;i<n;i++) {
        v2[i]=i;
    }
    for(int i=0;i<edges.size();i++) {
        merge(v,v2,edges[i][0],edges[i][1]);
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        if(v2[i]==i) {
            ans++;
        }
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
    cout<<countComponents(n,v)<<endl;
}