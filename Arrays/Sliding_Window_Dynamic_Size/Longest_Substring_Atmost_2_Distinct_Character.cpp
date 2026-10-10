#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    int i=0;
    char c1='1';
    char c2='1';
    int s1=0;
    int s2=0;
    int ans=0;
    for(int j=0;j<s.size();j++) {
        if(c1=='1'||s[j]==c1) {
            c1=s[j];
            s1++;
        } else if(c2=='1'||s[j]==c2) {
            c2=s[j];
            s2++;
        } else {
            while(s1>0&&s2>0) {
                if(s[i]==c1) {
                    s1--;
                } else {
                    s2--;
                }
                i++;
            }
            if(s1==0) {
                c1=s[j];
                s1=1;
            } else {
                c2=s[j];
                s2=1;
            }
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstringTwoDistinct(s)<<endl;
    return 0;
}