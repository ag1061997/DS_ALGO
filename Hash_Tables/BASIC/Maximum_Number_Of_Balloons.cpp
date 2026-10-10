#include <bits/stdc++.h>
using namespace std;

int maxNumberOfBalloons(string text) {
    int c1=0,c2=0,c3=0,c4=0,c5=0;
    for(int i=0;i<text.size();i++) {
        if(text[i]=='b') {
            c1++;
        } else if(text[i]=='a') {
            c2++;
        } else if(text[i]=='l') {
            c3++;
        } else if(text[i]=='o') {
            c4++;
        } else if(text[i]=='n') {
            c5++;
        }
    }
    return min(c1,min(c2,min(c3/2,min(c4/2,c5))));
}

int main() {
    string s;
    cin>>s;
    cout<<maxNumberOfBalloons(s)<<endl;
    return 0;
}