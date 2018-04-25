#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void printCircularList(node *head) {
    if (!head) {
        cout << "List empty" << endl;
        return;
    }
    cout << "***********************************" << endl;
    node *p = head;
    do {
        cout << p->data << endl;
        p = p->next;
    } while(p != head);

    cout << "***********************************" << endl;
}

void split(node *head) {
    if (!head) {
        return;
    }

    node *head1 = head;
    node *fast = head;
    node *slow = head;
    node *head2 = NULL;
    
    while (1) {
        if(fast->next == head1) {
            break;  // only one node case
        }
        else if(fast->next->next == head1) {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next == head1) {
        fast->next = slow->next;
    }
    else if(fast->next->next == head1) {
        fast->next->next = slow->next;
    }

    head2 = slow->next;
    slow->next = head1;

    printCircularList(head1);
    printCircularList(head2);
}

node *pushCircular(node *head, int val) {
    if(!head) {
        head = new node;
        head->data = val;
        head->next = head;
        return head;
    }
    
    node *p = head;
    node *temp;
    temp = new node;
    temp->data = val;
    
    while(p->next != head) {
        p = p->next;
    }
    
    p->next = temp;
    temp->next = head;
    return head;
}

int main() {
    node *head, *start;
    head = NULL;
    int val;

    for(int i = 0; i < 2; i++) {
        cin >> val;
        head = pushCircular(head, val);
    }

    printCircularList(head);

    start = head;
    split(start);
}
