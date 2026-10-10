#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x) {
            this->val=x;
            this->next=nullptr;
        }
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr||head->next==nullptr) {
        return head;
    }
    ListNode* pre=head;
    ListNode* cur=head->next;
    while(cur!=nullptr) {
        if(cur->val!=pre->val) {
            pre->next=cur;
            pre=cur;
        }
        cur=cur->next;
    }
    pre->next=cur;
    return head;
}

int main() {
    ListNode* head=new ListNode(1);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    ListNode* ans=deleteDuplicates(head);
    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}