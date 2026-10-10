#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ans=0;
    int s=1;
    int l=0;
    for(int r=0;r<nums.size();r++) {
        s*=nums[r];
        while(l<=r&&s>=k) {
            ans+=(r-l);
            s/=nums[l];
            l++;
        }
    }
    while(l<nums.size()) {
        ans+=(nums.size()-l);
        l++;
    }
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<numSubarrayProductLessThanK(v,k)<<endl;
    return 0;
}