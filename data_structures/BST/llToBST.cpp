#include <iostream>

using namespace std;

typedef struct _tnode {
    struct _tnode *left;
    struct _tnode *right;
    int data;
} tnode;

typedef struct _node {
    struct _node *next;
    int data;
} node;

tnode *newTnode(int value) {
	tnode *root = new tnode;
	root->data = value;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void printList (node *head) {
    int val;
    cout << "*********************************" << endl;
	cout << "The list: ";
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n*********************************" << endl;
}

void printPostorder(tnode*);
void printInorder(tnode*);
void printPreorder(tnode*);
void printTree(tnode*);

void reverse(node *&head) {
    if(!head) {
        return;
    }
    
    if(!head->next) {
        return;
    }

    node *curr = head;
    head = head->next;
    reverse(head);
    
    curr->next->next = curr;
    curr->next = NULL;
}

void push(node *&head, int val) {
    node *ptr = new node;

    if(!head) {
        ptr->data = val;
        ptr->next = head;
        head = ptr;
        return;
    }
    
    ptr->data = val;
    ptr->next = head;
    head = ptr;
}

void init(node *&head) {
    int val;
    cout << "Enter numbers of the list 1 \nEnter -999 to quit" << endl;
    while(1) {
        cin >> val;
        if( val == -999) break;
        push(head, val);
    }
}

int lengthLL(node *head) {
	int l = 0;
	while(head) {
		l++;
		head = head->next;
	}

	return l;
}

tnode* convertUtil(node *&head, int n) {
	if(n <= 0) {
		return NULL;
	}
	
	tnode *left = convertUtil(head, n/2);
	tnode *root = newTnode(head->data);
	root->left = left;
	head = head->next;
	root->right = convertUtil(head, n-n/2-1);

	return root;
}

tnode* convert(node *head) {
	int n = lengthLL(head);
	return(convertUtil(head, n));
}

int main() {
    node *head;    
    head = NULL;
    int val; 
   
    init(head);
    reverse(head);
    printList(head);
	cout << endl;
    
	printTree(convert(head));

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

