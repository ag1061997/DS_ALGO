#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    stack<int> st;
    for(int i=prices.size()-1;i>=0;i--) {
        while(!st.empty()&&st.top()>prices[i]) {
            st.pop();
        }
        if(!st.empty()) {
            prices[i]-=st.top();
            st.push(prices[i]+st.top());
        } else {
            st.push(prices[i]);
        }
    }
    return prices; 
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=finalPrices(v);
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}