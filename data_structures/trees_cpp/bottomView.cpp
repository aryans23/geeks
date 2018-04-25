#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef struct _tnode {
    struct _tnode *left = NULL;
    struct _tnode *right = NULL;
    int data;
	int hd = 0;
} tnode;

void printPostorder(tnode*);
void printInorder(tnode*);
void printPreorder(tnode*);
void printTree(tnode*);

void bottomView(tnode *root) {
	if(!root) {
		return;
	}

	map<int, tnode *> m;
	queue<tnode *> q;
	
	root->hd = 0;
	q.push(root);
	tnode *temp = new tnode;

	while(!q.empty()) {
		temp = q.front();
		q.pop();

		m[temp->hd] = temp;

		if(temp->left) {
			temp->left->hd = temp->hd - 1;
			q.push(temp->left);
		}

		if(temp->right) {
			temp->right->hd = temp->hd + 1;
			q.push(temp->right);
		}
	}

	map<int, tnode *>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
		cout << it->second->data << " ";
	}
	cout << endl;
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

	bottomView(root);

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


