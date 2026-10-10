#include <bits/stdc++.h>
using namespace std;

void multiply(vector<vector<long long> > &m1,vector<vector<long long> > &m2) {
    vector<vector<long long> > res(2,vector<long long>(2));
    res[0][0]=m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0];
    res[0][1]=m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1];
    res[1][0]=m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0];
    res[1][1]=m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1];

    m1[0][0]=res[0][0];
    m1[0][1]=res[0][1];
    m1[1][0]=res[1][0];
    m1[1][1]=res[1][1];
}

vector<vector<long long> > find(vector<vector<long long> > &m,int x) {
    vector<vector<long long> > ans(2,vector<long long>(2));
    ans[0][0]=1;
    ans[0][1]=0;
    ans[1][0]=0;
    ans[1][1]=1;
    while(x) {
        if(x&1) {
            multiply(ans,m);
        }
        multiply(m,m);
        x>>=1;
    }
    return ans;
}

int climbStairs(int n) {
    if(n==0||n==1) {
        return n;
    }

    vector<vector<long long> > m(2,vector<long long>(2));
    vector<vector<long long> > m2(2,vector<long long>(2));
    m[0][0]=1;
    m[0][1]=1;
    m[1][0]=1;
    m[1][1]=0;
    m2[0][0]=1;
    m2[0][1]=0;
    m2[1][0]=1;
    m2[1][1]=0;

    vector<vector<long long> > res=find(m,n-1);
    multiply(res,m2);
    return (int)res[0][0];
}

int main() {
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    return 0;
}