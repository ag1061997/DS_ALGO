#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    vector<int> v2(2);
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cin>>v2[0]>>v2[1];
    vector<vector<int> > ans=insert(v,v2);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}