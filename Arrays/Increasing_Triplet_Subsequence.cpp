#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int x=INT_MAX;
    int y=INT_MAX;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]>x&&nums[i]>y) {
            return true;
        } else if(nums[i]>x&&nums[i]<y) {
            y=nums[i];
        } else if(nums[i]<x) {
            x=nums[i];
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<increasingTriplet(v)<<endl;
    return 0;
}