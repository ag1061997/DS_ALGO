#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
        char a[10000];
        std::size_t len = s.length();
        int index =0;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < len; j +=2*(numRows-1)) {
                a[index++] = s[j];
                if (i > 0 && i<numRows-1 && j+2*(numRows-1)-2*i<len) {
                    a[index++] = s[j + 2*(numRows - 1)-2*i];
                }
            }
        }
        a[index]='\0';
        return a;  
}

int main() {
    string s;
    int n;
    cin>>s>>n;
    cout<<convert(s,n)<<endl;
    return 0;
}