#include <bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k) {
    int ans=0;
    int c=0;
    for(int i=0;i<k-1;i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
            c++;
        }
    }
    for(int i=k-1;i<s.size();i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
            c++;
        }
        ans=max(ans,c);
        if(s[i-k+1]=='a'||s[i-k+1]=='e'||s[i-k+1]=='i'||s[i-k+1]=='o'||s[i-k+1]=='u') {
            c--;
        }
    }
    return ans;
}

int main() {
    int k;
    string s;
    cin>>s>>k;
    cout<<maxVowels(s,k)<<endl;
    return 0;
}