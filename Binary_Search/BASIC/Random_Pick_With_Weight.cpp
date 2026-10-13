#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> v;
    int s;
    public:
        Solution(vector<int>& w) {
            v.push_back(w[0]);
            for(int i=1;i<w.size();i++) {
                int x=v[i-1]+w[i];
                v.push_back(x);
            }
            s=v.back();
        }
        
        int pickIndex() {
            int x=rand()%(s+1);
            int l=0;
            int r=v.size();
            while(l<r) {
                int m=l+(r-l)/2;
                if(v[m]<x) {
                    l=m+1;
                } else {
                    r=m;
                }
            }
            return l;
        }
};

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    Solution* s=new Solution(v);
    cout<<s->pickIndex()<<endl;
    cout<<s->pickIndex()<<endl;
    cout<<s->pickIndex()<<endl;
    cout<<s->pickIndex()<<endl;
}