#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
};

void print(ListNode* head) {
    while(head!=nullptr) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr) {
        return head;
    }
    ListNode* t=head;
    ListNode* pre=nullptr;
    int n=0;
    while(t!=nullptr) {
        n++;
        pre=t;
        t=t->next;
    }   
    k=k%n;
    if(k==0) {
        return head;
    }
    k=n-k;
    t=head;
    while(k>1) {
        t=t->next;
        k--;
    }
    ListNode* ans=t->next;
    t->next=nullptr;
    pre->next=head;
    return ans;
}

int main() {
    int k;
    cin>>k;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    print(head);
    head = rotateRight(head, k);
    print(head);

    return 0;
}