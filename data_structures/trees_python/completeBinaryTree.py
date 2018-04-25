#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import isCompleteBT

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.right = Node(6)
 
print("Preorder traversal of binary tree is: ",end="")
printPreorder(root)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root)
print("\n")

if (isCompleteBT(root)):
    print("Complete Binary Tree")
else:
    print("NOT Complete Binary Tree")


root2 = Node(1)
root2.left = Node(2)
root2.right = Node(3)
root2.left.left = Node(4)
root2.left.right = Node(5)
root2.right.left = Node(6)
root2.right.right = Node(7)
 
print("Preorder traversal of binary tree is: ",end="")
printPreorder(root2)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root2)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root2)
print("\n")

if (isCompleteBT(root2)):
    print("Complete Binary Tree")
else:
    print("NOT Complete Binary Tree")
