#include <iostream>
using namespace std;

typedef struct _node
{
  int data;
  struct _node* next;
} node;

/* Deletes nodes which have greater value node(s) on left side */
node* delLesserNodes(node *head)
{
  node *head_copy = head;
  while (head_copy->next) {
    if (head_copy->data < head_copy->next->data){
      node *temp = head_copy->next;
      head_copy->data = head_copy->next->data;
      head_copy->next = head_copy->next->next;
      delete temp;
      continue;
    }
    head_copy = head_copy->next;
  }
  return head;
}

/* Utility function to insert a node at the begining */
void push(node **head_ref, int new_data)
{
  node *new_node = new node();  
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

/* Utility function to print a linked list */
void printList(node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head=head->next;
  }
  cout << endl;
}

int main()
{
  node *head = NULL;

  /* Create following linked list
     12->15->10->11->5->6->2->3 */
  push(&head,3);
  push(&head,2);
  push(&head,6);
  push(&head,5);
  push(&head,11);
  push(&head,10);
  push(&head,15);
  push(&head,12);

  cout << "Given Linked List \n" << endl;
  printList(head);

  head = delLesserNodes(head);

  cout << "Modified Linked List \n" << endl;
  printList(head);

  return 0;
}
