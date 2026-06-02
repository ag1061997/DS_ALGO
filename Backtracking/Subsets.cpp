#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    int n=nums.size();
    vector<int> t;
    int m=1<<n;
    for(int i=0;i<m;i++) {
        int c=0;
        int x=i;
        t.clear();
        while(x) {
            if(x&1) {
                t.push_back(nums[c]);
            }
            c++;
            x>>=1;
        }
        ans.push_back(t);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<vector<int> > ans=subsets(v);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}