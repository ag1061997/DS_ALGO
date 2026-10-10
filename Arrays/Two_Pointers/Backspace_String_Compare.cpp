#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
    int i=s.size()-1;
    int j=t.size()-1;
    int x=0;
    int y=0;
    while(i>=0||j>=0) {
        while(i>=0) {
            if(s[i]=='#') {
                x++;
                i--;
            } else if(x>0) {
                x--;
                i--;
            } else {
                break;
            }
        }
        while(j>=0) {
            if(s[j]=='#') {
                y++;
                j--;
            } else if(y>0) {
                y--;
                j--;
            } else {
                break;
            }
        }
        if(i>=0&&j>=0) {
            if(s[i]!=s[j]) {
                return false;
            }
        } else if(i>=0||j>=0) {
            return false;
        }
        i--;
        j--;
    }
    return true;
}

int main() {
    string s,s2;
    cin>>s>>s2;
    cout<<backspaceCompare(s,s2)<<endl;
    return 0;
}