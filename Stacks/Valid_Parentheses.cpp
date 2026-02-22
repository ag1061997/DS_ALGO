#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int j=-1;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='('||s[i]=='['||s[i]=='{') {
            j++;
            s[j]=s[i];
        } else if(s[i]==')') {
            if(j==-1||s[j]!='(') {
                return false;
            } else {
                j--;
            }
        } else if(s[i]==']') {
            if(j==-1||s[j]!='[') {
                return false;
            } else {
                j--;
            }
        } else if(s[i]=='}') {
            if(j==-1||s[j]!='{') {
                return false;
            } else {
                j--;
            }
        }
    }
    return j==-1;   
}

int main() {
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;
    return 0;
}