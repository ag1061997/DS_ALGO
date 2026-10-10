#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > findMissingRanges(vector<int>& nums, int lower, int upper) {
    int x=lower;
    vector<vector<int> > ans;
    vector<int> t(2);
    for(int i=0;i<nums.size();i++) {
        if(nums[i]-1>=x) {
            t[0]=x;
            t[1]=nums[i]-1;
            ans.push_back(t);
        }
        x=nums[i]+1;
    }
    if(upper>=x) {
        t[0]=x;
        t[1]=upper;
        ans.push_back(t);
    }
    return ans;
}

int main() {
    int n,l,h;
    cin>>n>>l>>h;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<vector<int> > ans=findMissingRanges(v,l,h);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}