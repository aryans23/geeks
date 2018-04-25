#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import isSubTree

T = Node(26)
T.right = Node(3)
T.right.right  = Node(3)
T.left = Node(10)
T.left.left = Node(4)
T.left.left.right = Node(30)
T.left.right = Node(6)

print("T: ")
print("Preorder traversal of binary tree is: ",end="")
printPreorder(T)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(T)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(T)
print("\n")

S = Node(10)
S.right = Node(6)
S.left = Node(4)
S.left.right = Node(30)

print("S: ")
print("Preorder traversal of binary tree is: ",end="")
printPreorder(S)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(S)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(S)
print("\n")

if (isSubTree(T,S)):
    print("The tree T is subtree of S")
else:
    print("The tree T is NOT subtree of S")
