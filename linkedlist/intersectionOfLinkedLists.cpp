#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int n) {
        data = n;
        next = NULL;
    }
};

node *push(node *head, int n) {
    node *t = new node(n);
    if(!head){
        head = t;
        return head;
    }
    node *cur = head;
    while(cur->next) {
        cur = cur->next;
    }
    cur->next = t;
    return head;
}

bool hasCycle(node *head) {
    node *slow=head, *fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

node *getIntersectionNode(node *headA, node *headB) {
    node *ans=NULL, *tail=headA;
    while(tail->next) {
        tail = tail->next;
    }
    tail->next = headA;
    node *slow=headB, *fast=headB;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            slow = headB;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            ans = slow;
            break;
        }
    }
    tail->next = NULL;
    return ans;
}

int main() {
    node *head1 = NULL, *head2 = NULL;
    head1 = push(head1, 1);
    head1 = push(head1, 2);
    head1 = push(head1, 3);
    head1 = push(head1, 4);
    head1 = push(head1, 5);
    head2 = push(head2, 2);
    head2->next = head1->next->next;
    node *ans = getIntersectionNode(head1, head2);
    if(ans)
        cout<<ans->data;
    else
        cout<<0;
    return 0;
}