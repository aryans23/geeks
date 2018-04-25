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

void push(node *&head, int val) {
    node *p;
    p = new node;
    p->data = val;
    p->next = head;
    head = p;
}

void findIntersection(node *a, node *b, node *&head) {
    if(!a || !b) {
        return;
    }
    if(a->data < b->data) {
        findIntersection(a->next, b, head);
    }
    else if(a->data > b->data) {
        findIntersection(a, b->next, head);
    }
    else {
        push(head, a->data);
        findIntersection(a->next, b->next, head);
    }
}

int main() {
    node *head1, *ptr;
    head1 = NULL;

    cout << "Enter the values in list 1" << endl;

    for(int i = 0; i < 3; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head1;
        head1 = ptr;
    }
    
    reverse(head1);
    printList(head1);

    node *head2;
    head2 = NULL;
    ptr = NULL;

    cout << "Enter the values in list 2" << endl;

    for(int i = 0; i < 3; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head2;
        head2 = ptr;
    }
    
    reverse(head2);
    printList(head2);

    node *head;
    head = NULL;

    findIntersection(head1, head2, head);
    reverse(head);
    printList(head);

}
