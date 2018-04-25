#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void deleteNode(node *p) {
    p->data = p->next->data;
    p->next = p->next->next;
    
}

int main() {
    int inputNode;
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

    cout << "****************************\n" << endl;

    cout << "Enter the node you want to delete: " << endl;
    // node starts with 0
    cin >> inputNode;
    if(inputNode != -1) {
        while(p->next && inputNode > 0) {
            p = p->next;
            inputNode--;
        }
        if(p->next != NULL) {
            deleteNode(p);
        }  
        else {
            cout << "Node not there" << endl;
        }
    }

    cout << "*****************************\n" << endl;
    cout << "After deletion" << endl;
    while (head->next) {
        cout << head->data << endl;
        head = head->next;
    }

}
