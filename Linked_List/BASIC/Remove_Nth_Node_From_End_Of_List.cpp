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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==nullptr||head->next==nullptr) {
        return nullptr;
    }
    ListNode* pre=nullptr;
    ListNode* s=head;
    while(n!=0) {
        s=s->next;
        n--;
    }
    while(s!=nullptr) {
        s=s->next;
        if(pre==nullptr) {
            pre=head;
        } else {
            pre=pre->next;
        }
    }
    if(pre==nullptr) {
        return head->next;
    } else {
        pre->next=pre->next->next;
        return head;
    }
}

int main() {
    ListNode* h=new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(3);
    h->next->next->next=new ListNode(4);
    h->next->next->next->next=new ListNode(5);
    int k;
    cin>>k;
    ListNode* ans=removeNthFromEnd(h,k);
    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}