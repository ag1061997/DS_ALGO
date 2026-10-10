#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int s=0;
    for(int i=0;i<nums.size();i++) {
        s+=nums[i];
    }
    int s2=0;
    for(int i=0;i<nums.size();i++) {
        s-=nums[i];
        if(s==s2)return i;
        s2+=nums[i];
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<pivotIndex(v)<<endl;
    return 0;
}