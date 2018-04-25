#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import leafAtSameLevel

root = Node(12)
root.left = Node(5)
root.left.left = Node(3)
root.left.right = Node(9)
root.left.left.left = Node(1)
root.left.right.left = Node(2)

print("Preorder traversal of binary tree is: ",end="")
printPreorder(root)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root)
print("\n")

if (leafAtSameLevel(root)):
    print("Leaves are at same level")
else:
    print("Leaves are NOT at same level")
