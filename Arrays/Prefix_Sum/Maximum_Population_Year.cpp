#include <bits/stdc++.h>
using namespace std;

int maximumPopulation(vector<vector<int> >& logs) {
    vector<int> v(101,0);
    for(int i=0;i<logs.size();i++) {
        v[logs[i][0]-1950]++;
        v[logs[i][1]-1950]--;
    }
    int ans=1950;
    int mx=0;
    int s=0;
    for(int i=0;i<101;i++) {
        s+=v[i];
        if(s>mx) {
            mx=s;
            ans=1950+i;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<maximumPopulation(v)<<endl;
    return 0;
}