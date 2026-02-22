#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
    private:
        queue<int> q;
    public:
        RecentCounter() {
            
        }
        
        int ping(int t) {
            while(!q.empty()&&t>(q.front()+3000)) {
                q.pop();
            }
            q.push(t);
            return q.size();
        }
};

int main() {
    RecentCounter counter;
    cout<<counter.ping(1)<<endl;
    cout<<counter.ping(2)<<endl;
    cout<<counter.ping(3001)<<endl;
    cout<<counter.ping(3002)<<endl;
    return 0;
}