#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(k==0) return 0;
    if(k>=26) return s.size();
    vector<int> v(26,0);
    int i=0;
    int ans=0;
    int c=0;
    for(int j=0;j<s.size();j++) {
        if(v[s[j]-'a']==0) {
            c++;
        }
        v[s[j]-'a']++;
        while(c>k) {
            if(v[s[i]-'a']==1) {
                c--;
            }
            v[s[i]-'a']--;
            i++;
        }
        ans=max(ans,j-i+1);
    } 
    return ans;
}

int main() {
    string s;
    int k;
    cin>>s>>k;
    cout<<lengthOfLongestSubstringKDistinct(s,k)<<endl;
    return 0;
}