#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    int i=0;
    int j=1;
    while(j<s.size()) {
        if(i>=0&&s[i]==s[j]) {
            i--;
            j++;
        } else {
            swap(s[i+1],s[j]);
            i++;
            j++;
        }
    }
    return s.substr(0,i+1);
}

int main() {
    string s;
    cin>>s;
    cout<<removeDuplicates(s)<<endl;
    return 0;
}