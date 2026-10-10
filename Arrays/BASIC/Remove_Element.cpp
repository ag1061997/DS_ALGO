#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i=0;
    int j=0;
    while(j<nums.size()) {
        if(nums[j]!=val) {
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
    return i; 
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<removeElement(v,k)<<endl;
    return 0;
}