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

void findMiddle(node *&slow, node *&fast) {
    if (slow == NULL) {
        return;
    }
    
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

void isPalindrome(node *a, node *b) {
    cout << "Entered func" << endl;
    while(b) {
        if(a->data != b->data) {
            cout << "Not a palindrome" << endl;
            return;
        }
        a = a->next;
        b = b->next;
    }
    cout << "Palindrome" << endl;
}

int main() {
    node *head, *ptr, *p;
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

    node *slow, *fast;
    slow = head;
    fast = head;
    findMiddle(slow, fast);    
    reverse(slow->next); 
    
    isPalindrome(head, slow->next);
}
