#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0;
    int j=numbers.size()-1;
    while(i<j) {
        if(numbers[i]+numbers[j]==target) {
            vector<int> ans(2);
            ans[0]=i+1;
            ans[1]=j+1;
            return ans;
        } else if(numbers[i]+numbers[j]<target) {
            i++;
        } else {
            j--;
        }
    }
    vector<int> ans(2,-1);
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    vector<int> ans=twoSum(v,k);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}