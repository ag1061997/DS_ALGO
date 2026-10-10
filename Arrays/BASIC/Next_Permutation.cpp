#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i=nums.size()-2;
    while(i>=0&&nums[i]>=nums[i+1]) {
        i--;
    } 
    if(i>=0) {
        int j=nums.size()-1;
        while(nums[j]<=nums[i]) {
            j--;
        }
        swap(nums[j],nums[i]);
    }
    int l=i+1;
    int r=nums.size()-1;
    while(l<r) {
        swap(nums[l],nums[r]);
        l++;
        r--;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    nextPermutation(v);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}