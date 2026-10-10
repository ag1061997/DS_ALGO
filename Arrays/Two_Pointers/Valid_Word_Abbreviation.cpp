#include <bits/stdc++.h>
using namespace std;

bool validWordAbbreviation(string word, string abbr) {
    int n=word.size();
    int m=abbr.size();
    int i=0;
    int j=0;
    while(i<n&&j<m) {
        if(abbr[j]>='a'&&abbr[j]<='z') {
            if(abbr[j]!=word[i]) {
                return false;
            }
            j++;
            i++;
        } else if(abbr[j]=='0') {
            return false;
        } else {
            string x="";
            while(j<m&&abbr[j]>='0'&&abbr[j]<='9') {
                x+=abbr[j];
                j++;
            }
            int y=stoi(x);
            if(n-i<y) {
                return false;
            } else {
                i+=y;
            }
        }
    }
    return i==n&&j==m;
}

int main() {
    string s,s2;
    cin>>s>>s2;
    cout<<validWordAbbreviation(s,s2)<<endl;
    return 0;
}