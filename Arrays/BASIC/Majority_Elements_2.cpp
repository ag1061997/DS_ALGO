#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    int x=0;
    int y=0;
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++) {
        if(nums[i]==x) {
            c1++;
        } else if(nums[i]==y) {
            c2++;
        } else if(c1==0) {
            x=nums[i];
            c1++;
        } else if(c2==0) {
            y=nums[i];
            c2++;
        } else {
            c1--;
            c2--;
        }
    }
    c1=0;
    c2=0;
    for(int i=0;i<n;i++) {
        if(nums[i]==x) {
            c1++;
        } else if(nums[i]==y) {
            c2++;
        }
    }
    vector<int> ans;
    if(c1>n/3) ans.push_back(x);
    if(c2>n/3) ans.push_back(y);
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans = majorityElement(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}