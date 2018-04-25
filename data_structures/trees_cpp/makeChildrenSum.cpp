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

bool isLeaf(tnode *root) {
	if(!root->left && !root->right)
		return true;
	else 
		return false;
}

void increment(tnode *root, int diff) {
	if(!root) {
		return;
	}

	if(root->left) {
		root->left->data += diff;
		increment(root->left, diff);
	}

	else if(root->right) {
		root->right->data += diff;
		increment(root->right, diff);
	}
}

void transform(tnode *root) {
	int diff, lval, rval;
	lval = 0;
	rval = 0;
	
	if(!root) {
		return;
	}

	if(isLeaf(root)) {
	   return;
	}	   

	transform(root->left);
	transform(root->right);

	if(root->left) {
		lval = root->left->data;
	}

	if(root->right) {
		rval = root->right->data;
	}

	diff = root->data - rval - lval;

	if(diff == 0) {
		return;
	}

	else if(diff < 0) {
		root->data -= diff;
		return;
	}

	else {
		increment(root, diff);
		return;
	}
}

int main() {

	tnode *root = new tnode;
	root->data = 50;
	root->left = new tnode;
	root->left->data = 7;
	root->right = new tnode;
	root->right->data = 2;
	root->left->left = new tnode;
	root->left->left->data = 3;
	root->left->right = new tnode;
	root->left->right->data = 5;
	root->right->left = new tnode;
	root->right->left->data = 1;
	root->right->right = new tnode;
	root->right->right->data = 30;

    //tnode *root = new tnode;
    //root->data = 1;
    //root->left = new tnode;
    //root->left->data = 2;
    //root->right = new tnode;
    //root->right->data = 3;
    //root->left->left = new tnode;
    //root->left->left->data = 4;
    //root->left->right = new tnode;
    //root->left->right->data = 5;
    //root->left->right->left = new tnode;
	//root->right->left = new tnode;
	//root->right->left->data = 6;
	//root->right->right = new tnode;
	//root->right->right->data = 7;
    //root->left->right->left->data = 8;
    //root->left->right->right = new tnode;
    //root->left->right->right->data = 9;
    //root->left->right->right->left = new tnode;
    //root->left->right->right->left->data = 10;
    //root->left->right->right->right = new tnode;
    //root->left->right->right->right->data = 11;
    printTree(root);

	transform(root);
	printTree(root);

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


