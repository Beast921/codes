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

void swap(node **head, int i, int j) {
    if(i == j)  return;
    node *prevx=NULL, *curx=*head, *prevy=NULL, *cury=*head;
    while(curx && curx->data!=i) {
        prevx = curx;
        curx = curx->next;
    }
    while(cury && cury->data!=j) {
        prevy = cury;
        cury = cury->next;
    }
    if(!curx || !cury)  return;
    if(!prevx)
        *head = cury;
    else
        prevx->next = cury;
    if(!prevy)
        *head = curx;
    else
        prevy->next = curx;
    node *t = cury->next;
    cury->next = curx->next;
    curx->next = t;
}


int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    for(node *cur = head; cur; cur = cur->next)
        cout<<cur->data<<" ";
    cout<<'\n';
    swap(&head, 2, 4);
    for(node *cur = head; cur; cur = cur->next)
        cout<<cur->data<<" ";
    return 0;
}