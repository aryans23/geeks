#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void match(node *head, int inputNode){
    bool found= false;
    cout << "Entered match" << endl;
    while (head->next) {
        if (head->data == inputNode) {
            found = true;
            cout << "Found " << head->data << endl;
            return;
        }
        head = head->next;
    }
    
    if(!found) {
        cout << "Not found " << endl;
        return;
    }
}

int main() {
    int inputNode = -1;

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

    while(p->next) {
        cout << p->data << endl;
        p = p->next;
    }

    cout << "Enter the node you want to get: " << endl;
    cin >> inputNode;
    if(inputNode != -1) {
        cout << "Entered Function" << endl;
        match(head, inputNode);
    }

}
