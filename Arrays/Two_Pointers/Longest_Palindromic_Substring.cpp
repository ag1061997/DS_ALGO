#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n=s.size();
    int idx=0;
    int l=1;
    for(int i=0;i<n;i++) {
        int j=i;
        int k=i+1;
        while(j>=0&&k<n&&s[j]==s[k]) {
            if(k-j+1>l) {
                l=k-j+1;
                idx=j;
            }
            j--;
            k++;
        }
        j=i-1;
        k=i+1;
        while(j>=0&&k<n&&s[j]==s[k]) {
            if(k-j+1>l) {
                l=k-j+1;
                idx=j;
            }
            j--;
            k++;
        }
    } 
    return s.substr(idx,l);  
}

int main() {
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}