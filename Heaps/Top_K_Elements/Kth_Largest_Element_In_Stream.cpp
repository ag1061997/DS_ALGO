#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    public:
        priority_queue<int,vector<int>,greater<int> > pq;
        int k;
        KthLargest(int k, vector<int>& nums) {
            this->k=k;
            for(int i=0;i<nums.size();i++) {
                if(pq.size()<k) {
                    pq.push(nums[i]);
                } else {
                    if(nums[i]>pq.top()) {
                        pq.pop();
                        pq.push(nums[i]);
                    }
                }
            }
        }
        
        int add(int val) {
            if(pq.size()<k) {
                pq.push(val);
            } else {
                if(val>pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
            }
            return pq.top();
        }
};

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    KthLargest* kl=new KthLargest(k,v);
    cout<<kl->add(3)<<endl; 
    cout<<kl->add(5)<<endl; 
    cout<<kl->add(10)<<endl; 
    cout<<kl->add(9)<<endl; 
    cout<<kl->add(4)<<endl;
    return 0; 
}