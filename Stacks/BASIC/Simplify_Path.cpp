#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    int n=path.size();
    stack<string> st;
    string s="";
    for(int i=0;i<n;i++) {
        if(path[i]=='/') {
            while(i<n-1&&path[i+1]=='/') {
                i++;
            }
            if(s!="") {
                if(s!=".") {
                    if(s=="..") {
                        if(!st.empty()) {
                            st.pop();
                        }
                    } else {
                        reverse(s.begin(),s.end());
                        st.push(s);
                    }
                }
                s.clear();
            }
        } else {
            s=s+path[i];
        }
    }
    if(s!="") {
        if(s!=".") {
            if(s=="..") {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                reverse(s.begin(),s.end());
                st.push(s);
            }
        }
        s.clear();
    }
    while(!st.empty()) {
        s+=st.top();
        st.pop();
        s+="/";
    }
    reverse(s.begin(),s.end());
    if(s=="") {
        return "/";
    }
    return s;
}

int main() {
    string s;
    cin>>s;
    cout<<simplifyPath(s)<<endl;
}