#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int l=0;
    int r=people.size()-1;
    int ans=0;
    while(l<=r) {
        ans++;
        if(l==r) {
            break;
        } else {
            if(people[l]+people[r]<=limit) {
                l++;
            }
            r--;
        }
    } 
    return ans;
}

int main() {
    int n,l;
    cin>>n>>l;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<numRescueBoats(v,l)<<endl;
    return 0;
}