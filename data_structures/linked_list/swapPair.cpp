#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void printList(node *p) {
    cout << "***********************************" << endl;
    while(p) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "***********************************" << endl;
}

void reverse(node * &head) {
    if (!head){
        return;
    }

    if(!head->next) {
        return;
    }
    
    node *curr = head;
    head = head->next;
    reverse(head);
    
    curr->next->next = curr;
    curr->next = NULL;
} 

void swap(node *&a, node *&b) {
    int t;

    t = a->data;
    a->data = b->data;
    b->data = t;
}

void foo(node *head) {
    if(!head) {
        cout << "List empty" << endl;
        return;
    }

    else if(!head->next) {
        cout << "Only one element or odd elements" << endl;
        return;
    }
    
    node *start = head;
    swap(start, start->next);
    foo(start->next->next);

    printList(head);
}

int main() {
    node *head, *ptr;
    head = NULL;

    for(int i = 0; i < 5; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head;
        head = ptr;
    }
    
    reverse(head);
    printList(head);
    
    foo(head);
}
