#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int i=0;
    int j=0;
    int k=nums.size()-1;
    while(i<=k) {
        if(nums[i]==2) {
            swap(nums[i],nums[k]);
            k--;
        } else if(nums[i]==0) {
            swap(nums[i],nums[j]);
            j++;
            i++;
        } else {
            i++;
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
    sortColors(v);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}