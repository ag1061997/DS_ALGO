#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i=0;
    int j=1;
    int c=1;
    while(j<nums.size()) {
        while(j<nums.size()&&nums[j]==nums[i]) {
            c++;
            j++;
        }
        if(j<nums.size()) {
            if(c==1) {
                swap(nums[++i],nums[j++]);
            } else if(c>1) {
                i++;
                nums[i]=nums[i-1];
                swap(nums[++i],nums[j++]);
                c=1;
            }
        } else {
            if(c>1) {
                i++;
                nums[i]=nums[i-1];
            }
        }
    }  
    return i+1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int ans = removeDuplicates(v);
    for(int i=0;i<ans;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}