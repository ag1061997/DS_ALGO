#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int mx=INT_MIN;
    int mn=INT_MAX;
    int s1=0;
    int s2=0;
    int t=0;
    for(int i=0;i<nums.size();i++) {
        t+=nums[i];
        s1=max(s1+nums[i],nums[i]);
        mx=max(mx,s1);

        s2=min(s2+nums[i],nums[i]);
        mn=min(mn,s2);
    }
    if(mn==t) {
        return mx;
    }
    return max(mx,t-mn);
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<maxSubarraySumCircular(v)<<endl;
    return 0;
}