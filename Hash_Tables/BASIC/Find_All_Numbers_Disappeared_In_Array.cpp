#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n;i++) {
        int j=nums[i]-1;
        while (j+1!=nums[j]) {
            int x=j+1;
            j=nums[j]-1;
            nums[x-1]=x;
        }
    }
    for(int i=0;i<n;i++) {
        if(nums[i]!=i+1) {
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=findDisappearedNumbers(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}