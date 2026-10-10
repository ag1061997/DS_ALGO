#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    int n=s.size();
    if(goal.size()!=n) {
        return false;
    }
    for(int i=0;i<n;i++) {
        int c=0;
        int j=0;
        int k=i;
        while(j<n) {
            if(goal[j]!=s[k]) {
                break;
            }
            c++;
            j++;
            k++;
            if(k==n) {
                k=0;
            }
            if(c==n) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<rotateString(s,t)<<endl;
    return 0;
}