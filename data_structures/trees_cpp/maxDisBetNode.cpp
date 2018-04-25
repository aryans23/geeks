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

int max(int a, int b) {
	return a>b ? a:b;
}

int maxSumUtil(tnode *root, int &res) {
	if(!root) {
		return 0;
	}

	if(!root->left && !root->right) {
		return root->data;
	}

	int ls = maxSumUtil(root->left, res);
	int rs = maxSumUtil(root->right, res);

	if(!root->left) {
		return max(root->data + maxSumUtil(root->right, res), root->data);
	}
	
	if(!root->right) {
		return max(root->data + maxSumUtil(root->left, res), root->data);
	}

	else { //if(root->left && root->right) {
		res = max(res, max(ls + root->data + rs, root->data));

		return max(root->data, max(ls + root->data, rs + root->data));
	}
}

void maxSum(tnode *root) {
	int res = INT_MIN;

	maxSumUtil(root, res);

	cout << "\n***** Maximum sum = " << res << " *******" << endl;
}

int main() {
    tnode *root = new tnode;
    root->data = 10;
    root->left = new tnode;
    root->left->data = 2;
    root->right = new tnode;
    root->right->data = 10;
    root->left->left = new tnode;
    root->left->left->data = 20;
    root->left->right = new tnode;
    root->left->right->data = 1;
	//root->right->left = new tnode;
	//root->right->left->data = 6;
	root->right->right = new tnode;
	root->right->right->data = -25;
	root->right->right->left = new tnode;
	root->right->right->left->data = 3;
	root->right->right->right = new tnode;
	root->right->right->right->data = 4;

    /*
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
	*/

    printTree(root);

	maxSum(root);

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


