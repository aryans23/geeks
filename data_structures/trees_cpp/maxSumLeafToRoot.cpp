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

void maxLeafUtil(tnode *root, tnode *&targetLeaf, int currSum, int &maxSum) {
	if(!root) {
		return;
	}

	currSum += root->data;

	if(!root->left && !root->right) {
		if(currSum > maxSum) {
			targetLeaf = root;
			maxSum = currSum;
		}
		return;
	}

	maxLeafUtil(root->left, targetLeaf, currSum, maxSum);
	maxLeafUtil(root->right, targetLeaf, currSum, maxSum);
}

void maxLeaf(tnode *root) {
	if(!root) {
		return;
	}

	tnode *target = NULL;
	int currSum, maxSum;	
	currSum = 0;
	maxSum = 0;

	maxLeafUtil(root, target, currSum, maxSum);

	cout << "\nMax Leaf = " << target->data << endl;
	cout << "Max Sum = " << maxSum << endl;
}

int main() {

	//tnode *root = new tnode;
	//root->data = 100;
	//root->left = new tnode;
	//root->left->data = 50;
	//root->right = new tnode;
	//root->right->data = 50;
	//root->left->left = new tnode;
    //root->left->left->data = 6;
    //root->left->right = new tnode;
    //root->left->right->data = 13;
	//root->right->left = new tnode;
	//root->right->left->data = 1;
	//root->right->right = new tnode;
	//root->right->right->data = 2;
    //root->left->right->left = new tnode;
    //root->left->right->left->data = 5;
    //root->left->right->right = new tnode;
    //root->left->right->right->data = 4;
    //root->left->right->right->left = new tnode;
    //root->left->right->right->left->data = 2;
    //root->left->right->right->right = new tnode;
    //root->left->right->right->right->data = 1;
    //root->left->right->right->right->left = new tnode;
    //root->left->right->right->right->left->data = 1;

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
    root->left->right->left = new tnode;
	root->right->left = new tnode;
	root->right->left->data = 6;
	root->right->right = new tnode;
	root->right->right->data = 7;
    root->left->right->left->data = 8;
    root->left->right->right = new tnode;
    root->left->right->right->data = 9;
    root->left->right->right->left = new tnode;
    root->left->right->right->left->data = 10;
    root->left->right->right->right = new tnode;
    root->left->right->right->right->data = 11;
    root->left->right->right->right->left = new tnode;
    root->left->right->right->right->left->data = 20;

    printTree(root);

	maxLeaf(root);

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


