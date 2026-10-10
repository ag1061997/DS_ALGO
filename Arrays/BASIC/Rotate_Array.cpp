#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
    k=n-k;
    for(int i=0;i<k/2;i++) {
        swap(nums[i],nums[k-i-1]);
    }
    for(int i=k;i<k+(n-k)/2;i++) {
        swap(nums[i],nums[n-i-1+k]);
    }
    for(int i=0;i<n/2;i++) {
        swap(nums[i],nums[n-i-1]);
    }
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    rotate(v,k);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}