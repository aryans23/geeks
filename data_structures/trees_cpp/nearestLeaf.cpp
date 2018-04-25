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

int min(int a, int b) {
	return a<b ? a:b;
}

int findDisToNearestLeafDown(tnode *root) {
	if(!root) {
		return INT_MAX;
	}

	if(!root->left && !root->right) {
		return 0;
	}

	return (1 + min(findDisToNearestLeafDown(root->left), findDisToNearestLeafDown(root->right)));
}

int findDisToNearestLeafUtil(tnode *root, int k, tnode *ancestors[], int index) {
	if(!root) {
		return INT_MAX;
	}

	int res;

	if(root->data == k) {
		res = findDisToNearestLeafDown(root);
		
		for(int i = index-1; i >= 0; i--) {
		  res = min(res, index - i + findDisToNearestLeafDown(root));
		}
		return res;
	}

	ancestors[index] = root;
	return min(findDisToNearestLeafUtil(root->left, k, ancestors, index+1), findDisToNearestLeafUtil(root->right, k, ancestors, index+1));
}

void findDisToNearestLeaf(tnode *root) {
	tnode *ancestors[100];
	int k;
	cout << "Enter the target leaf: ";
	cin >> k;
	cout << "Distance to nearest Leaf = " << findDisToNearestLeafUtil(root, k, ancestors, 0) << endl;
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
	
	findDisToNearestLeaf(root);
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


