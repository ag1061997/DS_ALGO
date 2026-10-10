#include <bits/stdc++.h>
using namespace std;

bool validPalindrome(string s) {
    int n=s.size();
    int i=0;
    int j=n-1;
    int f=0;
    while(i<j) {
        if(s[i]!=s[j]) {
            if(f==1) {
                return false;
            } else {
                if(i+1==j) {
                    return true;
                } else {
                    if(s[i+1]==s[j]) {
                        f=1;
                        i++;
                    } else if(s[i]==s[j-1]) {
                        j--;
                        f=1;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            i++;
            j--;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin,s);
    cout<<validPalindrome(s)<<endl;
    return 0;
}