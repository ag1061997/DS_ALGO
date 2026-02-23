#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> mp;
    stack<int> st;
    int m=nums2.size();
    for(int i=m-1;i>=0;i--) {
        while(!st.empty()&&st.top()<=nums2[i]) {
            st.pop();
        }
        if(st.empty()) {
            mp[nums2[i]]=-1;
        } else {
            mp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    for(int i=0;i<nums1.size();i++) {
        nums1[i]=mp[nums1[i]];
    }
    return nums1;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    for(int i=0;i<n;i++) {
        cin>>v1[i];
    }
    for(int i=0;i<m;i++) {
        cin>>v2[i];
    }
    vector<int> ans=nextGreaterElement(v1,v2);
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}