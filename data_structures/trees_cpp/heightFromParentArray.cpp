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

void initParent(int *parent, int n) {
	cout << "Start entering parents of nodes. Enter -1 for root" << endl;
	for(int i = 0; i < n; i++) {
		cout << "Enter parent of element " << i << ": ";
		cin >> parent[i];
	}
}

int findDepthUtil(int *parent, int curr) {
	if(parent[curr] == -1) {
		return 1;
	}
	
	else {
		return findDepthUtil(parent, parent[curr]) + 1;
	}
}

void findDepth(int *parent, int *depth, int n) {
	for(int i = 0; i < n; i++) {
		if(depth[i] != -1) {
			continue;
		}
		depth[i] = findDepthUtil(parent, i);
	}
}

int maxOf(int *arr, int n) {
	int max = 0;

	for(int i = 0; i < n; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int getHeight(int *parent, int n) {
	int depth[n];
	
	for(int i = 0; i < n; i++) {
		depth[i] = -1;
	}

	findDepth(parent, depth, n);
	
	return maxOf(depth, n);
}

int main() {
	cout << "******* Generating PARENT array ******" << endl;
	cout << "Enter number of nodes: ";
	int n;
	cin >> n;

	int parent[n];
	initParent(parent, n);

	cout << "\nMaximum Depth = " << getHeight(parent, n) << endl;
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


