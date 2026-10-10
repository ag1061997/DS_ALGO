#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int x=-1;
    int y=-1;
    vector<int> ans(2);
    for(int i=0;i<nums.size();i++) {
        int j=abs(nums[i])-1;
        if(nums[j]<0) {
            x=abs(nums[i]);
        } else {
            nums[j]=-nums[j];
        }
    }
    for(int i=0;i<nums.size();i++) {
        if(nums[i]>0) {
            y=i+1;
        }
    }
    ans[0]=x;
    ans[1]=y;
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=findErrorNums(v);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0; 
}