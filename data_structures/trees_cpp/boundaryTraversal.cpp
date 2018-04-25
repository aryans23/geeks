#include <iostream>
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

void printLeftBorder(tnode *root) {
	if(!root->left && !root->right) {
		return;
	}

	cout << root->data << " " ;

	if(root->left) {
		printLeftBorder(root->left);
		return;
	}

	else {
		printLeftBorder(root->right);
		return;
	}
}

void printLeaves(tnode *root) {
	if(!root) {
		return;
	}
	
	printLeaves(root->left);
	
	if(!root->left && !root->right) {
		cout << root->data << " " ;
		return;
	}
	
	printLeaves(root->right);
}

void printRightBorder(tnode *root) {
	if(!root->left && !root->right) {
		return;
	}

	cout << root->data << " " ;

	if(root->right) {
		printRightBorder(root->right);
		return;
	}

	else {
		printRightBorder(root->left);
		return;
	}
}

void boundary(tnode *root) {
	if(!root) {
		return;
	}

	cout << root->data << " " ;

	if(root->left) {
		printLeftBorder(root->left);
	}

	printLeaves(root);

	if(root->right) {
		printRightBorder(root->right);
	}

	cout << endl;
}


int main() {
    tnode *root = new tnode;
    root->data = 1;
    //root->left = new tnode;
    //root->left->data = 2;
    root->right = new tnode;
    root->right->data = 3;
    //root->left->left = new tnode;
    //root->left->left->data = 4;
    //root->left->right = new tnode;
    //root->left->right->data = 5;
    //root->left->right->left = new tnode;
	root->right->left = new tnode;
	root->right->left->data = 6;
	root->right->right = new tnode;
	root->right->right->data = 7;
    //root->left->right->left->data = 8;
    //root->left->right->right = new tnode;
    //root->left->right->right->data = 9;
    //root->left->right->right->left = new tnode;
    //root->left->right->right->left->data = 10;
    //root->left->right->right->right = new tnode;
    //root->left->right->right->right->data = 11;
    printTree(root);

	boundary(root);

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


