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

void inOrderIter(tnode *root) {
	stack<tnode *> s;
	s.push(root);
	tnode *curr = root;
	tnode *temp;

	while(!s.empty()) {
		while(curr) {
			if(curr->left) {
				s.push(curr->left);
			}
			curr = curr->left;
		}

		temp = s.top();
		s.pop();
		cout << temp->data << " ";

		if(temp->right) {
			curr = temp->right;
			s.push(curr);
			continue;
		}	
	}
	cout << endl;
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
	inOrderIter(root);

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


