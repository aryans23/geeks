#include <iostream>
#include <stack>
using namespace std;

typedef struct _tnode {
    struct _tnode *left = NULL;
    struct _tnode *right = NULL;
    int data;
} tnode;

void printPostorder(tnode*);
void printInorder(tnode*);
void printPreorder(tnode*);
void printTree(tnode*);

bool isIsomorph(tnode *root, tnode *root1) {
	if(!root && !root1) {
		return true;
	}

	if(!root || !root1) {
		return false;
	}

	if(root->data != root1->data) {
		return false;
	}

	return ((isIsomorph(root->left, root1->left) && isIsomorph(root->right, root1->right)) || 
			(isIsomorph(root->right, root1->left) && isIsomorph(root->left, root1->right)));

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
    root->left->right = new tnode;
    root->left->right->data = 5;
	root->right->left = new tnode;
	root->right->left->data = 6;
    root->left->right->left = new tnode;
    root->left->right->left->data = 7;
    root->left->right->right = new tnode;
    root->left->right->right->data = 8;
	
	cout << "************ TREE 1 ************" << endl;
    printTree(root);

	tnode *root1 = new tnode;
    root1->data = 1;
    root1->right = new tnode;
    root1->right->data = 2;
    root1->left = new tnode;
    root1->left->data = 3;
    root1->left->right = new tnode;
    root1->left->right->data = 6;
	root1->right->left = new tnode;
	root1->right->left->data = 4;
	root1->right->right = new tnode;
	root1->right->right->data = 5;
    root1->right->right->left = new tnode;
    root1->right->right->left->data = 8;
    root1->right->right->right = new tnode;
    root1->right->right->right->data = 7;
	
	cout << "************ TREE 2 ************" << endl;
    printTree(root1);

	cout << "************ RESULT **************" << endl;
	if(isIsomorph(root, root1)) {
		cout << "Both trees ARE Isomorph" << endl;
	}
	else {
		cout << "Both trees ARE NOT Isomorph" << endl;
	}

    return 0;
}

/* Given a binary tree, print its nodes in Postorder*/
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


