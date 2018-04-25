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

void detectLoop(node *&head) {
    node *fast, *slow;
    fast = head;
    slow = head;
    
    while(fast != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            cout << "Loop detected" << endl;
            return;
        }
    }
}

int main() {
    node *head, *ptr, *p;
    head = NULL;

    for(int i = 0; i < 3; i++) { // storing like stack
        ptr = new node;
        cin >> ptr->data;
        ptr->next = head;
        head = ptr;
    }

    cout << "***********************************" << endl;
    
    reverse(head);      // reversing to make the stack match the input sequence
    printList(head);        

    cout << "***********************************" << endl;

    head->next->next->next = head;
    detectLoop(head);
    
}
