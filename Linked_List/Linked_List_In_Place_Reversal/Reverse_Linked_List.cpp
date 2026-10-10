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

ListNode* reverseList(ListNode* head) {
    ListNode* pre=nullptr;
    while(head!=nullptr) {
        ListNode* t=head->next;
        head->next=pre;
        pre=head;
        head=t;
    }
    return pre;
}

int main() {
    ListNode* h=new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(3);
    ListNode* ans=reverseList(h);
    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}