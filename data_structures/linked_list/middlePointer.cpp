#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
}node;

void printList(node *p) {
    while(p) {
        cout << p->data << endl;
        p = p->next;
    }
}

void findMiddle(node *slow) {
    if (slow == NULL) {
        return;
    }

    node *fast = slow;
    
    while (1) {
        if(fast->next == NULL) {
            break;
        }
        else if(fast->next->next == NULL) {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << "Middle element : " << slow->data << endl;
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

    cout << "************************************" << endl;

    printList(head);
    cout << endl;

    findMiddle(head);
}
