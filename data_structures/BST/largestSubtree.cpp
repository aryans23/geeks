/* *************** NOT COMPLETE *************** */

/* *************** IMPORTANT *************** */

#include <iostream>
#include <stack>
using namespace std;

typedef struct _tnode {
    struct _tnode *left;
    struct _tnode *right;
    int data;
} tnode;

tnode *newTnode(int value) {
	tnode *root = new tnode;
	root->data = value;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void printPostorder(tnode*);
void printInorder(tnode*);
void printPreorder(tnode*);
void printTree(tnode*);

int sizeUtil(tnode *root, int &maxSize_ref, int &max_ref, int &min_ref, bool &isBST) {
	if(!root) {
		isBST = true;	
		return 0;
	}

	bool leftFlag = false;
	bool rightFlag = false;

	int min = INT_MAX;
	int ls,rs;

	max_ref = INT_MIN;
	ls = sizeUtil(root->left, maxSize_ref, max_ref, min_ref, isBST);
	if(isBST && root->data > max_ref) {
		leftFlag = true;
	}

	min = min_ref;

	min_ref = INT_MAX;
	rs = sizeUtil(root->right, maxSize_ref, max_ref, min_ref, isBST);
	if(isBST && root->data < min_ref) {
		rightFlag = true;
	}

	if(min < min_ref) {
		min_ref = min;
	}
	if(root->data < min_ref) {
		min_ref = root->data;
	}
	if(max_ref < root->data) {
		max_ref = root->data;
	}

	if(leftFlag && rightFlag) {
		if(ls + rs + 1 > maxSize_ref) {
			maxSize_ref = ls + rs + 1;
		}
		return maxSize_ref;
	}
	else {
		isBST = false;
		return 0;
	}
}

int sizeOfLargestSubtree(tnode *root) {
	int max = INT_MAX;		// max from left subtree
	int min = INT_MIN;		// min from right subtree

	int maxSize = 0;		// max size of BST
	bool isBST = false;		// indicator to check whether current subtree is BST ot not

	return sizeUtil(root, maxSize, max, min, isBST);
}

 int main() {

	/* ******** BST here ******** */
    tnode *root = newTnode(20);
    root->left = newTnode(10);
    root->right = newTnode(30);
    root->left->left = newTnode(9);
    root->left->right = newTnode(11);
    //root->left->right->left = newTnode(8);
	root->right->left = newTnode(25);
	root->right->right = newTnode(40);
    root->left->right->right = newTnode(12);
    //root->left->right->right->left = newTnode(7);
    root->left->right->right->right = newTnode(13);
    //root->left->right->right->right->left = newTnode(6);

    printTree(root);

	cout << "Size of largest BST = " << sizeOfLargestSubtree(root) << endl;

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


