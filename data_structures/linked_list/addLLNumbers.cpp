#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} node;

void printList (node *head) {
    int val;
    cout << "*********************************" << endl;
    if (!head) cout << "NULL" << endl;
    while(head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
    cout << "*********************************" << endl;
}

void printListRec(node *head) {
    if(!head) return;
    printListRec(head->next);
    cout << head->data;
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
    cout << "** Enter numbers of the number from left to right **\n** Enter -999 to quit **" << endl;
    while(1) {
        cin >> val;
        if( val == -999) break;
        push(head, val);
    }
}

void add(node *head1, node *head2, node *&head, int carry) {
    int val = 0;
   
    while(head1 && head2) {
        push(head, (head1->data + head2->data + carry) % 10);
        carry = (head1->data + head2->data + carry)/10;
        head1 = head1->next;
        head2 = head2->next;
    }

    if(head1) {
        while(head1) {
            push(head, (head1->data + carry) % 10);
            carry = (head1->data + carry) / 10;
            head1 = head1->next;
        }
    }   

    else if(head2) {
        while(head2) {
            push(head, (head2->data + carry) % 10);
            carry = (head2->data + carry) / 10;
            head2 = head2->next;
        }
    } 
    
    if(carry) {
        push(head, carry);
    }
}

int main() {
    node *head, *head1, *head2;
    head = NULL;
    head1 = NULL;
    head2 = NULL;
    int val; 
   
    init(head1);
    cout << "\nThe first number is : ";
    printListRec(head1);
    cout << endl;
    
    init(head2);
    cout << "\nThe second number is : ";
    printListRec(head2);
    cout << endl;

    add(head1, head2, head, 0);   
    cout << "\nOn addition result is" << endl;
    printList(head);

    return 0;
}
