#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i=g.size()-1;
    int j=s.size()-1;
    int ans=0;
    while(i>=0&&j>=0) {
        if(s[j]>=g[i]) {
            j--;
            ans++;
        }
        i--;
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> v2(m);
    for(int i=0;i<m;i++) {
        cin>>v2[i];
    }
    cout<<findContentChildren(v,v2)<<endl;
    return 0; 
}