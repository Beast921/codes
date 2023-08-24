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

node* reverseList(node* head) {
    if(head == NULL || head->next==NULL)
        return head;
    node *a, *b, *c;
    a = NULL, b = head; c = head->next;
    while(b){
        b->next = a;
        a = b;
        b = c;
        if(c)
            c = c->next;
    }
    return head=a;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = reverseList(head);
    for(node *cur = head; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}