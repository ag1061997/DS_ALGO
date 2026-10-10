#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int> ans(n,0);
    stack<int> st;
    for(int i=n-1;i>=0;i--) {
        while(!st.empty()&&temperatures[st.top()]<=temperatures[i]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i]=st.top()-i;
        }
        st.push(i);
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
    vector<int> ans=dailyTemperatures(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}