#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int l=0;
    int r=letters.size()-1;
    if(target>=letters[r]) {
        return letters[l];
    }
    while(l<=r) {
        int m=l+(r-l)/2;
        if(letters[m]<=target) {
            l=m+1;
        } else {
            r=m-1;
        }
    }
    return letters[l];
}

int main() {
    int n;
    char t;
    cin>>n>>t;
    vector<char> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<nextGreatestLetter(v,t)<<endl;
    return 0;
}