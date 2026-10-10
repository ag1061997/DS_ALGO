#include <bits/stdc++.h>
using namespace std;

bool check(char c) {
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')) {
        return false;
    }
    return true;
}

bool isPalindrome(string s) {
    int i=0;
    int j=s.size();
    j--;
    while(i<j) {
        if(check(s[i])) {
            i++;
        } else if(check(s[j])) {
            j--;
        } else if(tolower(s[i])==tolower(s[j])){
            i++;
            j--;            
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin,s);
    cout<<isPalindrome(s)<<endl;
    return 0;
}