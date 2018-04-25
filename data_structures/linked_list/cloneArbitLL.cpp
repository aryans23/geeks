//************************************************* NOT COMPLETE ******************************************************//

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

void sideClone(node *&original) {
    if(!original) return;
    node *insert;
    
    while (original->next != NULL) {
        insert = new node;
        insert->data = original->data;
        insert->next = original->next;
        original->next = insert;
        original = insert->next;
    }
   
    // last node 
    insert = new node;
    insert->data = original->data;
    insert->next = NULL; 
}

int main() {
    node *head, *ptr;
    head = NULL;

    for(int i = 0; i < 4; i++) {
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head;
        head = ptr;
    }

    cout << "***********************************" << endl;
    
    reverse(head);
    printList(head);

    cout << "***********************************" << endl;

    node *original, *copy;
    original = head;

    sideClone(original);
    
}
