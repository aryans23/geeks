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

void foo(node *&head){
    if(!head) {
        cout << "List Empty" << endl;
        return;
    }
    if(!head->next) {
        cout << "Only one element" << endl;
        return;
    }

    node *one, *two;
    one = head->next;
    two = head;

    while (one->next) {
        one = one->next;
        two = two->next;
    }

    two->next = NULL;
    one->next = head;
    head = one;

    printList(head);
}

int main() {
    node *head, *ptr, *p;
    head = NULL;

    for(int i = 0; i < 3; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head;
        head = ptr;
    }
    
    reverse(head);
    printList(head);
    
    foo(head);
}
