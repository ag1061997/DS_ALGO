#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) {
    long x=LONG_MIN;
    long y=LONG_MIN;
    long z=LONG_MIN;
    for(int i=0;i<nums.size();i++) {
        if(x==LONG_MIN) {
            x=nums[i];
        } else if(nums[i]>x) {
            z=y;
            y=x;
            x=nums[i];
        } else if(nums[i]<x) {
            if(nums[i]>y) {
                z=y;
                y=nums[i];
            } else if(nums[i]<y&&nums[i]>z) {
                z=nums[i];
            }
        }
    }
    if(z!=LONG_MIN) {
        return z;
    }
    return x;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<thirdMax(v)<<endl;
    return 0;
}