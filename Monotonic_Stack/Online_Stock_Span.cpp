#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    private:
        stack<pair<int,int> > st;
    public:
        StockSpanner() {
            
        }
        
        int next(int price) {
            int c=1;
            while(!st.empty()&&st.top().first<=price) {
                c+=st.top().second;
                st.pop();
            }
            st.push(make_pair(price,c));
            return c;
        }
};

int main() {
    StockSpanner span;
    cout<<span.next(7)<<endl;
    cout<<span.next(2)<<endl;
    cout<<span.next(1)<<endl;
    cout<<span.next(2)<<endl;
    cout<<span.next(2)<<endl;
    return 0;
}