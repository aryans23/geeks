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

void find(tnode *root, int target) {
	bool done1 = false;		// indicates possesion of value
	tnode *curr1 = root;
	stack<tnode *> s1;
	int val1 = 0;

	bool done2 = false;		// indicates possesion of value
	tnode *curr2 = root;
	stack<tnode *> s2;
	int val2 = 0;

	while(1) {
		while(!done1) {
			if(curr1) {
				s1.push(curr1);
				curr1 = curr1->left;
			}

			else {
				if(s1.empty()) {
					done1 = true;		// to get out of this loop when done
				}
				else {
					curr1 = s1.top();
					s1.pop();
					val1 = curr1->data;
					curr1 = curr1->right;
					done1 = true;
				}
			}
		}

		while(!done2) {
			if(curr2) {
				s2.push(curr2);
				curr2 = curr2->right;
			}

			else {
				if(s2.empty()) {
					done2 = true;
				}
				else {
					curr2 = s2.top();
					s2.pop();
					val2 = curr2->data;
					curr2 = curr2->left;
					done2 = true;
				}
			}
		}

		if(val1 >= val2) {
			cout << "No such pairs" << endl;
			break;
		}

		if(val1 != val2 && val1 + val2 == target) {
			cout << "Pairs: " << val1 << " & " << val2 << endl;
			break;
		}

		else if(val1 + val2 < target) {
			done1 = false;
		}
		
		else {
			done2 = false;
		}
	}


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

	int target = 0;
	cout << "Enter target: ";
	cin >> target;
	find(root, target);
    
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


