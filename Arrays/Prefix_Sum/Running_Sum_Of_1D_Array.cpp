#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for(int i=1;i<nums.size();i++) {
        nums[i]+=nums[i-1];
    }
    return nums;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=runningSum(v);
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}