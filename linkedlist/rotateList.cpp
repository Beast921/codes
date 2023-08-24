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

node* rotateRight(node* head, int k) {
    if(!head || !k) return head;
    node *tail = head;
    int sz = 1;
    while(tail && tail->next) {
        ++sz;
        tail = tail->next;
    }
    tail->next = head;
    int i = sz - k%sz;
    while(i--) {
        tail = tail->next;
        head = head->next;
    }
    tail->next = NULL;
    return head;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = rotateRight(head, 2);
    for(node *cur = head; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}