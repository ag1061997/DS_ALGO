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

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr||head->next==nullptr) {
        return head;
    } 
    ListNode* ans=nullptr;
    ListNode* pre=nullptr;
    ListNode* s=head;
    while(s!=nullptr) {
        int c=1;
        while(s->next!=nullptr&&s->val==s->next->val) {
            s=s->next;
            c++;
        }
        if(c==1) {
            if(ans==nullptr) {
                ans=s;
                pre=s;
            } else {
                pre->next=s;
                pre=s;
            }
        } else if(ans!=nullptr){
            pre->next=s->next;
        }
        s=s->next;
    }
    return ans;
}

int main() {
    ListNode* h=new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(2);
    h->next->next->next=new ListNode(4);
    h->next->next->next->next=new ListNode(5);
    ListNode* ans=deleteDuplicates(h);
    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}