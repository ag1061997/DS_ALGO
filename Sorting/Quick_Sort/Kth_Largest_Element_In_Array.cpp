#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int n=nums.size();
    int idx=n-k;
    int l=0;
    int r=n-1;
    while(l<r) {
        int m=l+(rand()%(r-l+1));
        int p=nums[m];
        int lo=l;
        int hi=r;
        int i=l;
        while(i<=hi) {
            if(nums[i]<p) {
                swap(nums[i],nums[lo]);
                lo++;
                i++;
            } else if(nums[i]>p) {
                swap(nums[i],nums[hi]);
                hi--;
            } else {
                i++;
            }
        }
        if(idx<lo) {
            r=lo-1;
        } else if(idx>hi) {
            l=hi+1;
        } else {
            return p;
        }
    }
    return nums[l];
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<findKthLargest(v,k)<<endl;
}