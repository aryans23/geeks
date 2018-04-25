#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import sumTree

root = Node(26)
root.left = Node(10)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(6)
root.right.right = Node(3)

print("Preorder traversal of binary tree is: ",end="")
printPreorder(root)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root)
print("\n")

if (sumTree):
    print("The tree is sum tree")
else:
    print("The tree is NOT sum tree")
