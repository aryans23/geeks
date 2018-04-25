// *********************** IMPORTANT *************************** //
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

void printRootDown(tnode *root, int k) {
	if(k < 0 || !root) {
		return;
	}

	if(k == 0) {
		cout << root-> data << " " ;
		return;
	}

	printRootDown(root->left, k-1);
	printRootDown(root->right, k-1);
}

int distAncestor(tnode *root, tnode *target, int k) {
	if(!root || k < 0) {
		return -1;
	}

	if(root->data == target->data) {
		printRootDown(root, k);
		return 0;
	}

	int dl = distAncestor(root->left, target, k);

	if(dl != -1) {
		if(dl + 1 == k) {
			cout << root->data << endl;
		}
		else {
			printRootDown(root->right, k - dl - 2);
		}

		return 1 + dl;
	}

	int dr = distAncestor(root->right, target, k);

	if(dr != -1) {
		if(dr + 1 == k) {
			cout << root->data << endl;
		}
		else {
			printRootDown(root->left, k - dr - 2);
		}

		return 1 + dr;
	}

	return -1;
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
	root->right->right = new tnode;
	root->right->right->data = 7;
    root->left->right->left = new tnode;
    root->left->right->left->data = 8;
    root->left->right->right = new tnode;
    root->left->right->right->data = 9;
    root->left->right->right->left = new tnode;
    root->left->right->right->left->data = 10;
    root->left->right->right->right = new tnode;
    root->left->right->right->right->data = 11;
    root->left->right->right->right->left = new tnode;
    root->left->right->right->right->left->data = 12;
    printTree(root);

	int k;
	cout << "Enter k: ";
	cin >> k;

	tnode *target = new tnode;
	cout << "Enter target data: ";
	cin >> target->data;
	cout << endl;

	cout << "************ RESULTS ************ " << endl;
	distAncestor(root, target, k);
	cout << endl;

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


