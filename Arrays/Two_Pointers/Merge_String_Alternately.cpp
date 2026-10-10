#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string ans="";
    int i=0;
    int j=0;
    while(i<word1.size()&&j<word2.size()) {
        if(i<=j) {
            ans+=word1[i];
            i++;
        } else {
            ans+=word2[j];
            j++;
        }
    } 
    if(i==word1.size()) {
        ans+=word2.substr(j);
    } else {
        ans+=word1.substr(i);
    }
    return ans;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<mergeAlternately(s1,s2)<<endl;
    return 0;
}