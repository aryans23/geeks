#include <iostream>
#include <array>

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
	
void initArr(int *&arr, int l) {
	for(int i = 0; i < l; i++) {
		cout << "Enter value at index " << i << ": ";
		cin >> arr[i];
	}
}

void printArr(int *arr, int len) {
    cout << "*********************************" << endl;
	cout << "The array: ";
    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n*********************************" << endl;
}

void printPostorder(tnode*);
void printInorder(tnode*);
void printPreorder(tnode*);
void printTree(tnode*);

tnode *convert(int *arr, int start, int end) {
	if(start > end) {
		return NULL;
	}

	tnode *root = newTnode(arr[(start+end)/2]);
	root->left = convert(arr, start, (start+end)/2 - 1);
	root->right = convert(arr, (start+end)/2 + 1, end);

	return root;
}

int main() {
	cout << "Enter size of the array:  ";
	int len;
	cin >> len;

	int *arr = new int[len];
	initArr(arr, len);
	printArr(arr, len);

	printTree(convert(arr, 0, len-1));
	
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
    cout << "**********************************" << endl;
    cout << "PreOrder  : ";
	printPreorder(p);
	cout << "\nPostOrder : ";
    printPostorder(p);
	cout << "\nInOrder   : ";
    printInorder(p);
    cout << "\n**********************************" << endl;
}

