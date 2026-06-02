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

ListNode *detectCycle(ListNode *head) {
    ListNode* s=head;
    ListNode* f=head;

    while(f!=nullptr&&f->next!=nullptr) {
        s=s->next;
        f=f->next->next;

        if(s==f) {
            s=head;
            while(s!=f) {
                s=s->next;
                f=f->next;
            }
            return s;
        }
    }

    return nullptr;
}

int main() {
    ListNode* h1=new ListNode(1);
    h1->next=new ListNode(2);
    h1->next->next=h1;

    ListNode* ans=detectCycle(h1);

    if(ans==nullptr) {
        cout<<-1<<endl;
    } else {
        cout<<ans->val<<endl;
    }

    return 0;
}