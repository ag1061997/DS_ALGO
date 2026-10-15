#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> v2(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    for(int i=0;i<n;i++) {
        cin>>v2[i];
    }
    cout<<canCompleteCircuit(v,v2)<<endl;
}