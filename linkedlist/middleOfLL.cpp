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

node* middleNode(node* head) {
    if(head == NULL)    return head;
    node *a=head, *b=head;
    while(b!=NULL && b->next!=NULL){
        a = a->next;
        b = b->next->next;
    }
    return a;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = middleNode(head);
    cout<<head->data;
    return 0;
}