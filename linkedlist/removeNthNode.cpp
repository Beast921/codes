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

node* removeNthFromEnd(node* head, int n) {
    node *c=head, *p;
    int sz = 0;
    while(c) {
        sz++;
        c = c->next;
    }
    c=head;
    for(int i=1;i<=sz-n;++i) {
        p = c;
        c = c->next;
    }
    if(c == head)
        return head->next;
    p->next = c->next;
    return head;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = removeNthFromEnd(head, 2);
    for(node *cur = head; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}