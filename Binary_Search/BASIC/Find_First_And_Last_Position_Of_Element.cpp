#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int>& v,int t) {
    int n=v.size();
    int l=0;
    int r=n-1;
    while(l<=r) {
        int m=l+(r-l)/2;
        if((m==0||v[m-1]<t)&&v[m]==t) {
            return m;
        } else if(v[m]>=t) {
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return -1;
}

int findLast(vector<int>& v,int t) {
    int n=v.size();
    int l=0;
    int r=n-1;
    while(l<=r) {
        int m=l+(r-l)/2;
        if((m==(n-1)||v[m+1]>t)&&v[m]==t) {
            return m;
        } else if(v[m]<=t) {
            l=m+1;
        } else {
            r=m-1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2);
    ans[0]=findFirst(nums,target);
    if(ans[0]!=-1) {
        ans[1]=findLast(nums,target);
    } else {
        ans[1]=-1;
    }
    return ans;
}

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=searchRange(v,t);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}