#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans(numRows,vector<int>());
    int c=1;
    while(numRows>=c) {
        if(c>1) {
            ans[c-1].push_back(1);
            for(int j=1;j<c-1;j++) {
                ans[c-1].push_back(ans[c-2][j-1]+ans[c-2][j]);
            }
        }
        ans[c-1].push_back(1);
        c++;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > ans=generate(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}