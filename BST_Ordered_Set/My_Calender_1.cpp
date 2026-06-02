#include <bits/stdc++.h>
#include <map>
using namespace std;

class MyCalendar {
    map<int,int> booking;

    public:
        MyCalendar() {
            
        }
        
        bool book(int start, int end) {
            auto it=booking.lower_bound(start);
            if(it!=booking.end()&&end>it->first) {
                return false;
            }
            if(it!=booking.begin()) {
                auto preIt=prev(it);
                if(preIt->second>start) {
                    return false;
                }
            }
            booking[start]=end;
            return true;
        }
};

int main() {
    MyCalendar* calender;
    cout<<calender->book(10,20)<<endl;
    cout<<calender->book(15,25)<<endl;
    cout<<calender->book(20,30)<<endl;

    return 0;
}
