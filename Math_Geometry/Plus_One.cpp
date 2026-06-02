#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    for(int i=n-1;i>=0;i--) {
        if(digits[i]<9) {
            digits[i]++;
            return digits;
        } else {
            digits[i]=0;
        }
    }
    digits[0]=1;
    digits.push_back(0);
    return digits;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=plusOne(v);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}