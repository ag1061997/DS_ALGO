#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j=0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]!=0) {
            swap(nums[i],nums[j]);
            j++;
        }
    }    
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    moveZeroes(v);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}