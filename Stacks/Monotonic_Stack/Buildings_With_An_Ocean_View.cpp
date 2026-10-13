#include <bits/stdc++.h>
using namespace std;

vector<int> findBuildings(vector<int>& heights) {
    vector<int> ans;
    int n=heights.size();
    int k=n;
    for(int i=n-1;i>=0;i--) {
        while(k<n&&heights[i]>heights[k]) {
            k++;
        }
        if(k==n) {
            ans.push_back(i);
        }
        k--;
        heights[k]=heights[i];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=findBuildings(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}