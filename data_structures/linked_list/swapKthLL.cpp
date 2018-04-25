#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
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

int lengthOf(node *head) {
    int length = 0;
    while (head) {
        head = head->next;
        length++;
    }
    return length;
}

node *swapK(node *&head) {
    int n = lengthOf(head);
    cout << "Enter k" << endl;
    int k;
    cin >> k;

    if (n < k) {
        return head;     // invalid case
    }

    if (2*k - 1 == n) {
        return head;     // equal nodes
    }

    node *front = head;
    node *frontPrev = NULL;
    node *back = head;
    node *backPrev = NULL;

    for (int i = 1; i < k; i++) {
        frontPrev = front;
        front = front->next;
    }

    for (int i = 1; i < n-k+1; i++) {
        backPrev = back;
        back = back->next;
    }
    
    if(frontPrev) {
        frontPrev->next = back;
    }

    if(backPrev) {
        backPrev->next = front;
    }

    node *temp = back->next;
    back->next = front->next;
    front->next = temp;
    
    if(k == 1) {
        head = back;
    }

    if(k == n) {
        head = front;
    }
    
    return head;
}
       
int main() {
    node *head;
    head = NULL;
   
    init(head);
    reverse(head);
    cout << "Original List" << endl;
    printList(head);
    
    if(!head) {
        cerr << "No List initialized" << endl;
        return 0;
    }

    cout << "After swapping" << endl;
    printList(swapK(head));
    return 0;
}
