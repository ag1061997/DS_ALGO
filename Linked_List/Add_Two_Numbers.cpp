#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x) {
            val=x;
            this->next=nullptr;
        }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c=0;
    ListNode* pre=nullptr;
    ListNode* ans=l1;
    while(l1!=nullptr||l2!=nullptr) {
        if(l1!=nullptr&&l2!=nullptr) {
            int x=(l1->val+l2->val+c)%10;
            c=(l1->val+l2->val+c)/10;
            l1->val=x;
            pre=l1;
            l1=l1->next;
            l2=l2->next;
        } else if(l2!=nullptr) {
            pre->next=l2;
            l2=nullptr;
            pre=pre->next;
            int x=(pre->val+c)%10;
            c=(pre->val+c)/10;
            pre->val=x;
            l1=pre->next;
        } else {
            int x=(l1->val+c)%10;
            c=(l1->val+c)/10;
            l1->val=x;
            pre=l1;
            l1=l1->next;
        }
    }
    if(c!=0) {
        pre->next=new ListNode(c);
    }
    return ans;
}

int main() {
    ListNode * l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);
    
    ListNode * l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);

    ListNode* ans=addTwoNumbers(l1,l2);

    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;

    return 0;
}