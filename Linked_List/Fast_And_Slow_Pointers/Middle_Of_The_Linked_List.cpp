#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x) {
            val = x;
            next=nullptr;
        }
};

ListNode* middleNode(ListNode* head) {
    ListNode* s=head;
    ListNode* f=head;
    while(f!=nullptr&&f->next!=nullptr) {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

int main() {
    ListNode* h=new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(3);
    cout<<middleNode(h)->val<<endl;
    return 0;
}