#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > transpose(vector<vector<int> >& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int> > ans(m,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ans[j][i]=matrix[i][j];
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
    vector<vector<int> > ans=transpose(v);
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}