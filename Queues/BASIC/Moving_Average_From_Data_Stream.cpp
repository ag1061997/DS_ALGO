#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
    public:
        queue<int> q;
        int count;
        int sum;
        int size;
        MovingAverage(int size) {
            this->size=size;
            this->count=0;
            this->sum=0;
        }
        
        double next(int val) {
            if(count==size) {
                count--;
                sum-=q.front();
                q.pop();
            }
            sum+=val;
            q.push(val);
            count++;
            return (double)sum/(double)count;
        }
};

int main() {
    MovingAverage* m=new MovingAverage(3);
    cout<<m->next(1)<<endl;
    cout<<m->next(10)<<endl;
    cout<<m->next(3)<<endl;
    cout<<m->next(5)<<endl;
    return 0;
}