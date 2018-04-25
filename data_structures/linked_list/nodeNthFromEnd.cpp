#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void findNthNodeFromEnd(node *head, int n) {
    node *shiftedNode = head;
    for(int i = 0; i < n; i++){
        if(shiftedNode->next == NULL) {
            cout << "n too large" << endl;
            return;
        }
        shiftedNode = shiftedNode->next;
    }

    while(shiftedNode->next) {
        shiftedNode = shiftedNode->next;
        head = head->next;
    }

    cout << "Data from the end: " << head->data << endl;
}

int main() {
    int n;
    node *head, *ptr, *p;
    head = new node;
    ptr = head;
    p = head;
    head->data = 0;
    head->next = NULL;

    for(int i = 0; i < 3; i++) {
        cin >> ptr->data;
        ptr->next = new node;
        ptr = ptr->next;
        ptr->next = NULL;
    }

    cout << "*********************************" << endl;

    while(p->next) {
        cout << p->data << endl;
        p = p->next;
    }

    cout << "Enter the value on N: " << endl;
    cin >> n;
    if(n > -1) {
        cout << "Entered Function" << endl;
        findNthNodeFromEnd(head, n);
    }

}
