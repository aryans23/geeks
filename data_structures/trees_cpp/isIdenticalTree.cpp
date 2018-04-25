#include <iostream>
using namespace std;

typedef struct _tnode {
    struct _tnode *left = NULL;
    struct _tnode *right = NULL;
    int data;
} tnode;

void printPostorder(tnode* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostorder(node->left);
 
     // then recur on right subtree
     printPostorder(node->right);
 
     // now deal with the node
     cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(tnode* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorder(node->left);
 
     /* then print the data of node */
     cout << node->data << " ";  
 
     /* now recur on right child */
     printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(tnode* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     cout << node->data << " ";  
 
     /* then recur on left sutree */
     printPreorder(node->left);  
 
     /* now recur on right subtree */
     printPreorder(node->right);
} 
    
void printTree(tnode *p) { 
    cout << "************** PreOrder ********************" << endl;
    printPreorder(p);
    cout << "\n************** PostOrder *******************" << endl;
    printPostorder(p);
    cout << "\n************** Inorder *********************" << endl;
    printInorder(p);
    cout << "\n********************************************" << endl;
}

bool isSame(tnode *t1, tnode *t2) {
	if(!t1 && !t2) {
		return true;
	}

	if(t1->data == t2->data) {
		return (isSame(t1->left, t2->left) && isSame(t1->right, t2->right));
	}

	else {
		return false;
	}
}

int main() {
    tnode *root = new tnode;
    root->data = 1;
    root->left = new tnode;
    root->left->data = 2;
    root->right = new tnode;
    root->right->data = 3;

    root->left->left = new tnode;
    root->left->left->data = 4;

    printTree(root);

    tnode *root2 = new tnode;
    root2->data = 1;
    root2->left = new tnode;
    root2->left->data = 2;
    root2->right = new tnode;
    root2->right->data = 3;

    root2->left->left = new tnode;
    root2->left->left->data = 4;

    printTree(root2);

	cout << "Same = " << isSame(root, root2) << endl;

    return 0;
}

