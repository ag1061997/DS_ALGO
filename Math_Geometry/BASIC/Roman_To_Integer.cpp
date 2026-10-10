#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> values;

    values['I']=1;
    values['V']=5;
    values['X']=10;
    values['L']=50;
    values['C']=100;
    values['D']=500;
    values['M']=1000;

    int result = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        int current = values[s[i]];
        if (i < n - 1 && current < values[s[i + 1]]) {
            result -= current;
        } else {
            result += current;
        }
    }

    return result;  
}

int main() {
    string s;
    cin>>s;
    cout<<romanToInt(s)<<endl;
    return 0;
}