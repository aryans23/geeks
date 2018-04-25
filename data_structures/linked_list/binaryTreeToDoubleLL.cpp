#include <iostream>
using namespace std;

typedef struct _node {
  int val;
  struct _node *left;
  struct _node *right;
} node;

node *concatenate(node *leftList, node *rightList) 
{
  if (!leftList)
    return rightList;
  if (!rightList)
    return leftList;

  node *leftList_end = leftList->left;
  node *rightList_end = rightList->left;

  leftList_end->right = rightList;
  rightList_end->right = leftList;
  leftList->left = rightList_end;
  rightList->left = leftList_end;

  return leftList;
}

void displayCList(node *head)
{
  cout << "Circular Linked List is :\n";
  node *itr = head;
  do
  {
    cout << itr->val <<" ";
    itr = itr->right;
  } while (head!=itr);
  cout << "\n";
}

node *bTreeToCLL(node *root)
{
  if (!root)
    return NULL;

  node* left = bTreeToCLL(root->left);
  node* right = bTreeToCLL(root->right);

  root->left = root->right = root;
  left = concatenate(left,root);
  return concatenate(left,right);
}

node* newNode(int val)
{
  node* temp = new node();
  temp->val = val;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}

int main()
{
  node *root = newNode(10);
  root->left = newNode(12);
  root->right = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  node *head = bTreeToCLL(root);
  displayCList(head);
  return 0;
}
