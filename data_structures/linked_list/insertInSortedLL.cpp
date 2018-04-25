#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void printList(node *p) {
    while(p) {
        cout << p->data << endl;
        p = p->next;
    }
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

node *insert(node *head, int val) {
    if(!head) {
        return NULL;
    }

    node *insertNode = new node;

    if(head->data >= val) {        // first node is greater than the val
        insertNode->data = val;
        insertNode->next = head;
        head = insertNode;
        return head;
    }

    node *headCopy = head;

    while(headCopy->next && headCopy->next->data < val) {
        headCopy = headCopy->next;
    }
    
    insertNode->data = val;    
    insertNode->next = headCopy->next;
    headCopy->next = insertNode;
    return head;
}

int main() {
    node *head, *ptr, *p;
    head = NULL;
    int val;

    for(int i = 0; i < 3; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head;
        head = ptr;
    }

    cout << "***********************************" << endl;
    
    reverse(head);
    printList(head);

    cout << "***********************************" << endl;

    for(int i = 1; i < 5; i++) {
        cout << "Enter valur to be inserted: ";
        cin >> val;
        cout << endl;
        head = insert(head, val);
        printList(head);
        cout << "***********************************" << endl;
    }
}
