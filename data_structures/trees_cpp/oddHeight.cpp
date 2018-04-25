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

void oddHeightOf(tnode *root, int level, int &maxLevel, tnode *&targetNode) {
	if(!root) {
		return;
	}

	if(!root->left && !root->right && level % 2 == 0) {
		return;			// even leaf
	}
	
	if (!root->left && !root->right && level % 2 != 0 && level > maxLevel) {
		maxLevel = level;
		targetNode = root;		// odd leaf
		return;
	}

	oddHeightOf(root->left, level+1, maxLevel, targetNode);
	oddHeightOf(root->right, level+1, maxLevel, targetNode);
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
    root->left->right->left->data = 6;
    root->left->right->left->right = new tnode;
    root->left->right->left->right->data = 7;
    root->left->right->left->right->left = new tnode;
    root->left->right->left->right->left->data = 8;

    printTree(root);

	int maxLevel = 1;
	tnode *targetNode = root; 
	oddHeightOf(root, 1, maxLevel, targetNode);
	cout << "Max odd height = " << maxLevel << " with the node value = " << targetNode->data << endl;

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


