#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int i=-1;
    int j=0;
    while(j<s.size()) {
        if(s[j]==' ') {
            if(i!=-1) {
                reverse(s.begin()+i,s.begin()+j);
                i=-1;
            }
        } else {
            if(i==-1) {
                i=j;
            }
        }
        j++;
    }
    if(i!=-1) {
        reverse(s.begin()+i,s.end());
    }
    i=0;
    j=0;
    int f=0;
    while(j<s.size()) {
        if(s[j]!=' ') {
            f=1;
            s[i++]=s[j++];
        } else {
            if(f==1) {
                s[i++]=s[j++];
            } else {
                j++;
            }
            f=0;
        }
    }
    if(i<s.size()&&s[j-1]==' ') {
        i--;
    }
    return s.substr(0,i);
}

int main() {
    string s;
    getline(cin,s);
    cout<<reverseWords(s)<<endl;
    return 0;
}