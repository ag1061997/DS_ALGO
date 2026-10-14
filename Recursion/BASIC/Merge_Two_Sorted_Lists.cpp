#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val) {
            this->val=val;
            this->next=nullptr;
        }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==nullptr) {
        return list2;
    } else if(list2==nullptr) {
        return list1;
    }
    if(list1->val<=list2->val) {
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    } else {
        list2->next=mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main() {
    ListNode* h1=new ListNode(1);
    h1->next=new ListNode(2);
    h1->next->next=new ListNode(4);

    ListNode* h2=new ListNode(1);
    h2->next=new ListNode(3);
    h2->next->next=new ListNode(4);

    ListNode* ans=mergeTwoLists(h1,h2);
    while(ans!=nullptr) {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
}