#include <bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    sort(capacity.begin(),capacity.end());
    int s=0;
    for(int i=0;i<apple.size();i++) {
        s+=apple[i];
    }
    int j=capacity.size()-1;
    int ans=0;
    while(s>0) {
        if(s>capacity[j]) {
            ans++;
            s-=capacity[j];
            j--;
        } else {
            ans++;
            s=0;
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> v2(m);
    for(int i=0;i<m;i++) {
        cin>>v2[i];
    }
    cout<<minimumBoxes(v,v2)<<endl;
    return 0; 
}