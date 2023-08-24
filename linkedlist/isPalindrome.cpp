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

bool isPalindrome(node* head) {
    node *slow=head, *fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast && !fast->next)
        slow = slow->next;
    slow = reverseList(slow);
    fast = head;
    while(slow && fast) {
        if(slow->data != fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main() {
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 2);
    head = push(head, 1);
    if(isPalindrome(head))
        cout<<"Palindrome";
    else
        cout<<"Not palindrome";
    return 0;
}