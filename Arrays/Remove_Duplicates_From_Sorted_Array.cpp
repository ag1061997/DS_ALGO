#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int j=0;
    int n=nums.size();
    for(int i=1;i<n;i++) {
        if(nums[i]==nums[i-1]) {
            continue;
        } else {
            swap(nums[j],nums[i-1]);
            j++;
        }
    }
    swap(nums[j],nums[n-1]);
    j++;
    return j;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int k = removeDuplicates(v);
    for(int i=0;i<k;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}