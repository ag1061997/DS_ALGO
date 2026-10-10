#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    int type1=-1;
    int type2=-1;
    int left=0;
    int count1=0;
    int count2=0;
    int ans=0;
    for(int right=0;right<fruits.size();right++) {
        if(type1==-1||fruits[right]==type1) {
            count1++;
            type1=fruits[right];
        } else if(type2==-1||fruits[right]==type2) {
            count2++;
            type2=fruits[right];
        } else {
            while(count1>0&&count2>0) {
                if(fruits[left]==type1) {
                    count1--;
                } else {
                    count2--;
                }
                left++;
            }
            if(count1==0) {
                type1=fruits[right];
                count1++;
            } else {
                type2=fruits[right];
                count2++;
            }
        }
        ans=max(ans,right-left+1);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<totalFruit(v)<<endl;
    return 0;
}