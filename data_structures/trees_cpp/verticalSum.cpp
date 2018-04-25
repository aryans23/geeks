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

void printSum(int *Sum) {
	for(int i = 0; i < 1000; i++) {
		if(Sum[i] == 0) {
			continue;
		}

		cout << Sum[i] << " || ";
	}
	cout << endl;
}

void verticalSumUtil(tnode *root, int *Sum, int index) {
	if(!root) {
		return;
	}

	Sum[index] += root->data;

	verticalSumUtil(root->left, Sum, index-1); 
	verticalSumUtil(root->right, Sum, index+1);
}	

void verticalSum(tnode *root) {
	if(!root) {
		return;
	}
	
	int *Sum = new int[1000];
	int index = 500;

	Sum[index] = root->data;

	verticalSumUtil(root->left, Sum, index-1);
	verticalSumUtil(root->right, Sum, index+1);

	printSum(Sum);
}

int main() {

	tnode *root = new tnode;
	root->data = 100;
	root->left = new tnode;
	root->left->data = 50;
	root->right = new tnode;
	root->right->data = 50;

   // tnode *root = new tnode;
   // root->data = 70;
   // root->left = new tnode;
   // root->left->data = 32;
   // root->right = new tnode;
   // root->right->data = 3;
    
	root->left->left = new tnode;
    root->left->left->data = 6;
    root->left->right = new tnode;
    root->left->right->data = 13;
	root->right->left = new tnode;
	root->right->left->data = 1;
	root->right->right = new tnode;
	root->right->right->data = 2;
    root->left->right->left = new tnode;
    root->left->right->left->data = 5;
    root->left->right->right = new tnode;
    root->left->right->right->data = 4;
    root->left->right->right->left = new tnode;
    root->left->right->right->left->data = 2;
    root->left->right->right->right = new tnode;
    root->left->right->right->right->data = 1;
    root->left->right->right->right->left = new tnode;
    root->left->right->right->right->left->data = 1;
    printTree(root);

	verticalSum(root);

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


