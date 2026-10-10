#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p,int x) {
    if(x!=p[x]) {
        p[x]=find(p,p[x]);
    }
    return p[x];
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

int findCircleNum(vector<vector<int> >& isConnected) {
    int n=isConnected.size();
    vector<int> r(n,0);
    vector<int> p(n);
    for(int i=0;i<n;i++) {
        p[i]=i;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(isConnected[i][j]==1) {
                int x1=find(p,i);
                int y1=find(p,j);
                if(x1!=y1) {
                    merge(r,p,x1,y1);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        if(p[i]==i) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    cout<<findCircleNum(v)<<endl;
}