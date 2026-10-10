#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int c1=0;
    int s2=0;
    int n=s.size();
    for(int i=n-1;i>=0;i--) {
        if(s[i]==')') {
            s2++;
        } else if(s[i]=='(') {
            if(s2>0) {
                s2--;
            } else if(c1>0) {
                c1--;
            } else {
                return false;
            }
        } else {
            c1++;
        }
    }
    if(s2>0&&c1<s2) {
        return false;
    }
    c1=0;
    s2=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='(') {
            s2++;
        } else if(s[i]==')') {
            if(s2>0) {
                s2--;
            } else if(c1>0) {
                c1--;
            } else {
                return false;
            }
        } else {
            c1++;
        }
    }
    if(s2>0&&c1<s2) {
        return false;
    }
    return true;
}

int main() {
    string s;
    cin>>s;
    cout<<checkValidString(s)<<endl;
    return 0;
}