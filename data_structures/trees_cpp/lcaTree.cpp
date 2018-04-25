// *************** ASSUMPTION: NUMBERS n1 and n2 EXIST IN THE TREE **************** //
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

tnode *findLCA(tnode *root, int n1, int n2) {
	if(!root) {
		return NULL;
	}

	if(root->data == n1 || root->data == n2) {
		return root;
	}

	tnode *left_lca = findLCA(root->left, n1, n2);
	tnode *right_lca = findLCA(root->right, n1, n2);

	if(left_lca && right_lca) {
		return root;
	}

	return (!left_lca ? right_lca:left_lca);
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
    printTree(root);

	int n1, n2;
	cout << "Enter n1 and n2 : ";
	cin >> n1;
	cin >> n2;
	cout << endl;
	cout << "LCA data = " << findLCA(root, n1, n2)->data << endl;

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


