#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    if(n<3) {
        return false;
    }
    stack<int> st;
    vector<int> v(n,INT_MIN);
    int mn=nums[0];
    for(int i=1;i<n;i++) {
        if(nums[i]>mn) {
            v[i]=mn;
        } else {
            mn=nums[i];
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(v[i]!=INT_MIN) {
            while(!st.empty()&&st.top()<=v[i]) {
                st.pop();
            }
            if(!st.empty()&&st.top()<nums[i]) {
                return true;
            }
        }
        st.push(nums[i]);
    }  
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<find132pattern(v)<<endl;
    return 0;
}