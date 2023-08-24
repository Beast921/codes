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

void deleteNode(node* node) {
    while(node->next->next) {
        node->data = node->next->data;
        node = node->next;
    }
    node->data = node->next->data;
    node->next = NULL;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    deleteNode(head->next->next);
    for(node *cur = head; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}