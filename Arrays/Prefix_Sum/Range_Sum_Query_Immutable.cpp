#include <bits/stdc++.h>
using namespace std;

class NumArray {
    private:
        vector<int> v;
    public:
        NumArray(vector<int>& nums) {
            v.push_back(0);
            for(int i=0;i<nums.size();i++) {
                v.push_back(nums[i]+v[i]);
            }
        }
        
        int sumRange(int left, int right) {
            return v[right+1]-v[left];
        }
};

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    NumArray arr(v);
    cout<<arr.sumRange(0,2)<<endl;
    cout<<arr.sumRange(0,5)<<endl;
    return 0;
}