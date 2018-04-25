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

bool sameLev(tnode *root, int level, int &targetLevel) {
	if(!root) {
		return true;
	}

	if(!root->left && !root->right) {
		if(targetLevel == 0) {
			targetLevel = level;
			return true;
		}

		if(level != targetLevel) {
			return false;
		}

		return true;
	}

	return (sameLev(root->left, level+1, targetLevel) && sameLev(root->right, level+1, targetLevel));
}

int main() {
    tnode *root = new tnode;
    root->data = 1;
    root->left = new tnode;
    root->left->data = 2;
    //root->right = new tnode;
    //root->right->data = 3;
    root->left->left = new tnode;
    root->left->left->data = 4;
	root->left->right = new tnode;
	root->left->right->data = 5;
    //root->left->right->left = new tnode;
    //root->left->right->left->data = 6;
    //root->left->right->left->right = new tnode;
    //root->left->right->left->right->data = 7;
    //root->left->right->left->right->left = new tnode;
    //root->left->right->left->right->left->data = 8;

    printTree(root);

	int targetLevel = 0;
	if(sameLev(root, 1, targetLevel)) {
		cout << "Every leaf is at same level " << endl;
	}
	else {
		cout << "Every leaf is NOT at same level " << endl;
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


