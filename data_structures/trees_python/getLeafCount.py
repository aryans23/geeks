#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import getLeafCount

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Preorder traversal of binary tree is: ",end="")
printPreorder(root)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root)

print("\nThe number of leaves in the tree is: ",end="")
print(getLeafCount(root))

print("\n")