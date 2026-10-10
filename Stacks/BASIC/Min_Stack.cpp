#include <bits/stdc++.h>
using namespace std;

class MinStack {
    private:
        stack<pair<int,int> > st;
    public:
        MinStack() {
            
        }
        
        void push(int val) {
            if(st.empty()) {
                st.push(make_pair(val,val));
            } else {
                st.push(make_pair(val,min(val,st.top().second)));
            }
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
        }
};

int main() {
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.getMin()<<endl;
    return 0;
}