#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import nextRight

root = Node(10)
root.left = Node(2)
root.right = Node(6)
root.right.right = Node(5)
root.left.left = Node(8)
root.left.right = Node(4)

print("Preorder traversal of binary tree is: ",end="")
printPreorder(root)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root)
print("\n")

K = [10,2,6,5,8,4]

for i in range(6):

    k = K[i]

    res = nextRight(root,k) 
    if res is not None:
        print("Next right of %d " %(k), end="")
        print("is %d" %(res.val))
    else:
        print("No right element for %d" %(k))
