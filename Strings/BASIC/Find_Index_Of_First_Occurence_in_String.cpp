#include <bits/stdc++.h>
using namespace std;

vector<int> build(string s) {
    int m=s.size();
    vector<int> v(m,0);
    int l=0;
    int i=1;
    while(i<m) {
        if(s[i]==s[l]) {
            l++;
            v[i]=l;
            i++;
        } else {
            if(l>0) {
                l=v[l-1];
            } else {
                v[i]=0;
                i++;
            }
        }
    }
    return v;
}

int strStr(string haystack, string needle) {
    int n=haystack.size();
    int m=needle.size();
    vector<int> l=build(needle);

    int i=0;
    int j=0;
    while(i<n) {
        if(haystack[i]==needle[j]) {
            i++;
            j++;
        }

        if(j==m) {
            return i-m;
        } else if(i<n&&haystack[i]!=needle[j]) {
            if(j>0) {
                j=l[j-1];
            } else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<strStr(s,t)<<endl;
    return 0;
}