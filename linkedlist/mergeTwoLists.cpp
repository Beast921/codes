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

node* mergeTwoLists(node* list1, node* list2) {
    if(!list1)  return list2;
    if(!list2)  return list1;
    if(list1->data < list2->data) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main() {
    node *head1 = NULL, *head2 = NULL;
    head1 = push(head1, 1);
    head1 = push(head1, 5);
    head1 = push(head1, 7);
    head1 = push(head1, 9);
    head1 = push(head1, 10);
    head2 = push(head2, 2);
    head2 = push(head2, 3);
    head2 = push(head2, 6);
    head2 = push(head2, 8);
    head2 = push(head2, 22);

    head1 = mergeTwoLists(head1, head2);
    for(node *cur = head1; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}