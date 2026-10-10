#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<string> st;
    string s1="";
    for(int i=0;i<s.size();i++) {
        if(s[i]>='0'&&s[i]<='9') {
            s1+=s[i];
        } else if(s[i]!=' ') {
            if(!st.empty()) {
                if(st.top()=="*"||st.top()=="/") {
                    string expr=st.top();
                    st.pop();
                    string s2=st.top();
                    st.pop();
                    if(expr=="*") {
                        st.push(to_string(stoi(s2)*stoi(s1)));
                    } else {
                        st.push(to_string(stoi(s2)/stoi(s1)));
                    }
                    st.push(s.substr(i,1));
                    s1="";
                } else {
                    st.push(s1);
                    st.push(s.substr(i,1));
                    s1="";
                }
            } else {
                st.push(s1);
                st.push(s.substr(i,1));
                s1="";
            }
        }
    }
    if(st.size()>1) {
        if(st.top()=="*"||st.top()=="/") {
            string expr=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            if(expr=="*") {
                st.push(to_string(stoi(s2)*stoi(s1)));
            } else {
                st.push(to_string(stoi(s2)/stoi(s1)));
            }
        } else {
            st.push(s1);
        }
    } else if (s1!="") {
        st.push(s1);
    }
    int yy=0;
    int xx=0;
    while(st.size()>1) {
        string p=st.top();
        st.pop();
        string e=st.top();
        st.pop();
        if (e=="+") {
            xx+=stoi(p);
        } else if (e=="-") {
            yy+=stoi(p);
        }
    }
    if(!st.empty()) {
        xx+=stoi(st.top());
    }
    return xx-yy;
}

int main() {
    string s;
    getline(cin,s);
    cout<<calculate(s)<<endl;
    return 0;
}