#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if(x<0) return false;
    string s=to_string(x);
    int i=0;
    int j=s.size()-1;
    while(i<j) {
        if(s[i]!=s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    int s;
    cin>>s;
    cout<<isPalindrome(s)<<endl;
    return 0;
}