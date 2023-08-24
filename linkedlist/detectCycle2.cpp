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

node *detectCycle(node *head) {
    node *a=head, *b=head;
    while(b && b->next){
        a = a->next;
        b = b->next->next;
        if(a == b) {
            a = head;
            while(a!=b) {
                a = a->next;
                b = b->next;
            }
            return a;
        }
    }
    return NULL;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head->next->next->next->next->next = head->next;
    node *ans = detectCycle(head);
    if(ans) 
        cout<<"cycle at "<<ans->data;
    else
        cout<<"no cycle";
    return 0;
}