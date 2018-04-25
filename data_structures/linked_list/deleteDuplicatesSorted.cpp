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

void deleteNode(node *p) {
    node *temp;
    temp = p->next;
    p->next = p->next->next;
    delete temp;
}

void removeDuplicates(node *head) {
    if(!head) {
        return;
    }
    if(!head->next) {
        return;
    }

    node *p = head;

    while(p->next != NULL) {
        if(p->data == p->next->data) {
            deleteNode(p);
            continue;
        }
        p = p->next;
    }
}

int main() {
    node *head, *ptr, *p;
    head = NULL;

    for(int i = 0; i < 8; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head;
        head = ptr;
    }

    reverse(head);
    printList(head);
    
    removeDuplicates(head);    
    printList(head);
}
