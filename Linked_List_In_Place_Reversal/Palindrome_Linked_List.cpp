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

bool isPalindrome(ListNode* head) {
    if(head==nullptr) {
        return true;
    }
    ListNode* s=head;
    ListNode* f=head;
    while(f->next!=nullptr&&f->next->next!=nullptr) {
        s=s->next;
        f=f->next->next;
    }
    ListNode* ans=reverseList(s->next);
    while(ans!=nullptr) {
        if(ans->val!=head->val) {
            return false;
        }
        ans=ans->next;
        head=head->next;
    }
    return true;
}

int main() {
    ListNode* h=new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(1);
    cout<<isPalindrome(h)<<endl;
    return 0;
}