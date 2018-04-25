/* ********************* INCOMPLETE ******************** */
#include <iostream>
#include <stack>
#include <vector>
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

void mergeBST(tnode *root1, tnode *root2) {
	stack<tnode *> s1;
	stack<tnode *> s2;
	s1.push(root1);
	s2.push(root2);
	tnode *curr1 = root1;
	tnode *curr2 = root2;
	tnode *temp1;
	tnode *temp2;
	vector<int> ivec;

	while(!s1.empty() || !s2.empty()) {
		while(curr1) {
			if(curr1->left) {
				s1.push(curr1->left);
			}
			curr1 = curr1->left;
		}
		while(curr2) {
			if(curr2->left) {
				s2.push(curr2->left);
			}
			curr2 = curr2->left;
		}
		
		temp1 = s1.top();
		s1.pop();
		temp2 = s2.top();
		s2.pop();
		
		if(temp1->data < temp2->data) {
			cout << temp1->data << " ";
			s2.push(temp2);

			if(temp1->right) {
				curr1 = temp1->right;
				s1.push(curr1);
				continue;
			}	
		}
		else {
			cout << temp2->data << " ";
			s1.push(temp1);

			if(temp2->right) {
				curr2 = temp2->right;
				s2.push(curr2);
				continue;
			}	
		}
	cout << endl;
	}
}

int main() {

	/* ******** BST here ******** */
    tnode *root1 = newTnode(20);
    root1->left = newTnode(10);
    root1->right = newTnode(30);
    root1->left->left = newTnode(9);
    root1->left->right = newTnode(11);
    //root1->left->right->left = newTnode(8);
	root1->right->left = newTnode(25);
	root1->right->right = newTnode(40);
    root1->left->right->right = newTnode(12);
    //root1->left->right->right->left = newTnode(7);
    root1->left->right->right->right = newTnode(13);
    //root1->left->right->right->right->left = newTnode(6);

    printTree(root1);

	/* ******** BST here ******** */
    tnode *root2 = newTnode(22);
    root2->left = newTnode(12);
    root2->right = newTnode(32);
    root2->left->left = newTnode(11);
    root2->left->right = newTnode(13);
    //root2->left->right->left = newTnode(8);
	root2->right->left = newTnode(27);
	root2->right->right = newTnode(42);
    root2->left->right->right = newTnode(14);
    //root2->left->right->right->left = newTnode(7);
    root2->left->right->right->right = newTnode(15);
    //root2->left->right->right->right->left = newTnode(6);

	printTree(root2);

	mergeBST(root1, root2);

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


