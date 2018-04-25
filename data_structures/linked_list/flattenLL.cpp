// ********************************* NOT TESTED ********************************** //

#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *down = NULL;
} node;

void printList (node *head) {
    int val;
    cout << "*********************************" << endl;
    while(head) {
        cout << head->data << endl;
        head = head->next;
    }
    cout << "*********************************" << endl;
}

void reverse(node *&head) {
    if(!head) {
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
    node *ptr = new node;

    if(!head) {
        ptr->data = val;
        ptr->next = head;
        head = ptr;
        return;
    }
    
    ptr->data = val;
    ptr->next = head;
    head = ptr;
}

void init(node *&head) {
    int val;
    cout << "Enter numbers of the list 1 \nEnter -999 to quit" << endl;
    while(1) {
        cin >> val;
        if( val == -999) break;
        push(head, val);
    }
}

node *endOfList(node *head) {
    if (!head) {
        return;
    }

    if (!head->next) {
        return head;
    }

    while(head->next) {
        head = head->next;
    }
    return head;
}

void append(node *&child, node *&tail) {
    tail->next = child;
    tail = endOfList(child);
}

void flatten(node *&head, node *&tail) {
    node *curr = head;
    
    if(curr->down) {
        append(curr->down, tail);
        curr->down = NULL;
    }

    cout << curr->data << endl;
    flatten(curr->next, tail);
}

int main() {
    node *head;
    head = NULL;
       
    init(head);
    reverse(head);
    cout << "Original List" << endl;
    printList(head);

    return 0;
}
