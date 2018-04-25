#include <iostream>
#include <queue>

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

bool isCousin(tnode *root, tnode *a, tnode *b) {
	if(!root) {
		return false;
	}

	queue<tnode *> q;
	q.push(root);
	tnode *temp = new tnode;
	tnode *parA = new tnode;
	tnode *parB = new tnode;
	int currLvl, lvlA, lvlB, qlen;
	currLvl = 0;
	lvlA = 0;
	lvlB = 0;

	while(!q.empty()) {
		qlen = q.size();
		while(qlen > 0) {
			temp = q.front();
			q.pop();

			if(temp->left) {
				if(temp->left->data == a->data) {
					parA = temp;
					lvlA = currLvl + 1;
				}
				if(temp->left->data == b->data) {
					parB = temp;
					lvlB = currLvl + 1;
				}
				q.push(temp->left);
			}

			if(temp->right) {
				if(temp->right->data == a->data) {
					parA = temp;
					lvlA = currLvl + 1;
				}
				if(temp->right->data == b->data) {
					parB = temp;
					lvlB = currLvl + 1;
				}
				q.push(temp->right);
			}
			--qlen;
		}
		currLvl++;
	}

	return((lvlA == lvlB) && (parA != parB));
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

	tnode *a = new tnode;
	cout << "Enter node A value: ";
	cin >> a->data;
	
	tnode *b = new tnode;
	cout << "Enter node B value: ";
	cin >> b->data;

	cout << "Are " << a->data << " and " << b->data << " are cousins ??" << endl;
	
	if(isCousin(root, a, b)) {
		cout << "***** Yes !! *****" << endl;
	}
	else {
		cout << "***** No !! *****" << endl;
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


