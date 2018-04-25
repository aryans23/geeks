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

void split(node *head, node *&a, node *&b) {
    if (head == NULL) {
        return;
    }

    node *slow = head;
    node *fast = head;
    
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
    
    a = head;
    b = slow->next;
    slow->next = NULL;
}

node *merge(node *head1, node *head2){
    node *head = NULL;

    if(!head1) {
        while(head2) {
            push(head, head2->data);
            head2 = head2->next;
        }
        reverse(head);
        return head;
    }
    
    if(!head2) {
        while(head1) {
            push(head, head1->data);
            head1 = head1->next;
        }
        reverse(head);
        return head;
    }

    if(head1->data < head2->data) {
        push(head, head1->data);
        head->next = merge(head1->next, head2);
    }

    else if(head1->data > head2->data) {
        push(head, head2->data);
        head->next = merge(head1, head2->next);
    }

    // Now if they are equal

    else {
        push(head, head1->data);
        head->next = merge(head1->next, head2->next);
    }

    return head;
}

void mergeSort(node *&head) {
    if(!head) {
        return;
    }

    if(!head->next) {
        return;
    }

    node *a, *b;
    a = NULL;
    b = NULL;
    split(head,a,b);
    
    mergeSort(a);
    mergeSort(b);

    head = merge(a,b); 
}

int main() {
    node *head;    
    head = NULL;
    int val; 
   
    init(head);
    reverse(head);
    cout << "The list " << endl;
    printList(head);
    
    mergeSort(head);
    cout << "Sorted List" << endl;
    printList(head);

    return 0;
}
