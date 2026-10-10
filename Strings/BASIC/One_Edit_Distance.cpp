#include <bits/stdc++.h>
using namespace std;

bool isOneEditDistance(string s, string t) {
    int n=s.size();
    int m=t.size();
    if(abs(n-m)>1) {
        return false;
    }
    int i=0;
    int j=0;
    int f=0;
    while(i<n&&j<m) {
        if(s[i]==t[j]) {
            i++;
            j++;
        } else if(f==0) {
            if(n>m) {
                i++;
            } else if(m>n) {
                j++;
            } else {
                i++;
                j++;
            }
            f=1;
        } else {
            return false;
        }
    }
    if(f==0) {
        if(i<n||j<m) {
            return true;
        } else {
            return false;
        }
    } else {
        if(i<n||j<m) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<isOneEditDistance(s,t)<<endl;
    return 0;
}