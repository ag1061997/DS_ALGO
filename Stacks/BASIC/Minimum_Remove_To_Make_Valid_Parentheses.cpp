#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    int i=0;
    int j=0;
    int n=s.size();
    int start=0;
    while(j<n) {
        if(s[j]=='(') {
            s[i]=s[j];
            start++;
            i++;
        } else if(s[j]==')') {
            if(start>0) {
                s[i]=s[j];
                i++;
                start--;
            }
        } else {
            s[i]=s[j];
            i++;
        }
        j++;
    }
    int idx=i;
    while(start>0) {
        i--;
        if(s[i]=='(') {
            start--;
        }
    }
    j=i;
    while(j<idx) {
        if(s[j]!='(') {
            s[i]=s[j];
            i++;
        }
        j++;
    }
    return s.substr(0,i);
}

int main() {
    string s;
    cin>>s;
    cout<<minRemoveToMakeValid(s)<<endl;
}