#include <iostream>

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

void fixUtil(tnode *root, tnode *&first, tnode *&middle, tnode *&last, tnode *prev) {
	if(!root) {
		return;
	}

	fixUtil(root->left, first, middle, last, prev);

	if(prev && root->data < prev->data) {
		if(!first) {
			first = prev;
			middle = root;
		}
		else {
			last = root;
		}
	}

	prev = root;

	fixUtil(root->right, first, middle, last, prev);	
}

void swap(tnode *a, tnode *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void fix(tnode *root) {
	tnode *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;

	fixUtil(root, first, middle, last, prev);

	if(first && last) {
		swap(first, last);
	}
	if(first && middle) {
		swap(first, middle);
	}
}

int main() {

	/* ******** BST here ******** */
	/* ******** 12 <> 40 ******** */
    tnode *root = newTnode(20);
    root->left = newTnode(10);
    root->right = newTnode(30);
    root->left->left = newTnode(9);
    root->left->right = newTnode(11);
    //root->left->right->left = newTnode(8);
	root->right->left = newTnode(25);
	root->right->right = newTnode(12);
    root->left->right->right = newTnode(40);
    //root->left->right->right->left = newTnode(7);
    root->left->right->right->right = newTnode(13);
    //root->left->right->right->right->left = newTnode(6);

    printTree(root);

	fix(root);

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


