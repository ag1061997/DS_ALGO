#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x) {
            val=x;
            next=nullptr;
        }
};

ListNode* swapPairs(ListNode* head) {
    if(head==nullptr||head->next==nullptr) {
        return head;
    }
    ListNode* ans=nullptr;
    ListNode* pre=nullptr;
    ListNode* s=head;
    while(s!=nullptr&&s->next!=nullptr) {
        ListNode* t=s->next;
        s->next=s->next->next;
        t->next=s;
        if(ans==nullptr) {
            ans=t;
            pre=t->next;
        } else {
            pre->next=t;
            pre=t->next;
        }
        s=s->next;
    }
    return ans;
}

int main() {
    ListNode* h=new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(3);
    h->next->next->next=new ListNode(4);
    h->next->next->next->next=new ListNode(5);
    ListNode* ans=swapPairs(h);
    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}