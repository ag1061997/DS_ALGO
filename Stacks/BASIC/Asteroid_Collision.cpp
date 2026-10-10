#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(int i=0;i<asteroids.size();i++) {
        if(asteroids[i]<0) {
            while(!st.empty()&&st.top()>0) {
                if(abs(asteroids[i])>st.top()) {
                    st.pop();
                } else if(abs(asteroids[i])==st.top()) {
                    asteroids[i]=0;
                    st.pop();
                    break;
                } else {
                    asteroids[i]=0;
                    break;
                }
            }
            if(asteroids[i]<0) {
                st.push(asteroids[i]);
            }
        } else {
            st.push(asteroids[i]);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=asteroidCollision(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}