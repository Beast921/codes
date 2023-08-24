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

node* addTwoNumbers(node* l1, node* l2) {
    int c = 0;
    node *l3=NULL, *l=NULL;
    while(l1 && l2) {
        int sum = l1->data + l2->data + c;
        c = sum/10;
        if(!l){
            l = new node(sum%10);
            l3 = l;
        }
        else {
            l3->next = new node(sum%10);
            l3 = l3->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1) {
        int sum = l1->data + c;
        c = sum/10;
        l3->next = new node(sum%10);
        l1 = l1->next;
        l3 = l3->next;
    }
    while(l2) {
        int sum = l2->data + c;
        c = sum/10;
        l3->next = new node(sum%10);
        l2 = l2->next;
        l3 = l3->next;
    }
    if(c)
        l3->next = new node(c);
    return l;
}

int main() {
    node *head1 = NULL, *head2 = NULL;
    head1 = push(head1, 1);
    head1 = push(head1, 2);
    head1 = push(head1, 3);
    head2 = push(head2, 4);
    head2 = push(head2, 9);
    head2 = push(head2, 5);
    head1 = addTwoNumbers(head1, head2);
    for(node *cur = head1; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}