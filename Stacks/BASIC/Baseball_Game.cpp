#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> st;
    int ans=0;
    for(int i=0;i<operations.size();i++) {
        if(operations[i]=="+") {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.push(x);
            st.push(x+y);
        } else if(operations[i]=="D") {
            st.push(st.top()*2);
        } else if(operations[i]=="C") {
            st.pop();
        } else {
            st.push(stoi(operations[i]));
        }
    }
    while(!st.empty()) {
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<calPoints(v)<<endl;
    return 0;
}