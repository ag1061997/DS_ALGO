#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans=INT_MIN;
    int s=0;
    for(int i=0;i<nums.size();i++) {
        s+=nums[i];
        ans=max(ans,s);
        if(s<0) {
            s=0;
        }
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
    cout<<maxSubArray(v)<<endl;
    return 0;
}