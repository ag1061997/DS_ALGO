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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr || headB == nullptr) {
        return nullptr;
    } 
    ListNode* p1=headA;
    ListNode* p2=headB;
    
    while(p1!=p2) {
        p1=p1?p1->next:headB;
        p2=p2?p2->next:headA;
    }
    return p1;
}

int main() {
    ListNode* h1 = new ListNode(1);
    h1->next=new ListNode(8);
    h1->next->next = new ListNode(4);

    ListNode* h2 = new ListNode(6);
    h2->next=new ListNode(1);
    h2->next->next = h1->next;

    cout<<getIntersectionNode(h1,h2)->val<<endl;
    return 0;
}